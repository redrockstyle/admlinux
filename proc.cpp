#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/prctl.h>
#include <fstream>
#include <string>
#include <mutex>
#include <cstdlib>
#include <vector>

std::mutex mutex;

void write_log(const std::string& message, int iteration_number) {
	mutex.lock();
	std::ofstream ofs("log.txt", std::ios::app);
	ofs << "Iteration: " << iteration_number << "; " << message << std::endl;
	mutex.unlock();
}

void kill_children(const std::vector<pid_t>& children_pids) {
	for (pid_t pid : children_pids) {
		kill(pid, SIGQUIT);
	}
}

int main(int argc, char* argv[]) {
	std::string message(argv[1]);
	int processes_number = std::atoi(argv[2]);
	int iterations_number = std::atoi(argv[3]);
	std::ofstream ofs("log.txt");
	ofs.close();
	std::vector<pid_t> children_pids;
	pid_t pid;
	for (int i = 0; i < processes_number; ++i) {
		pid = fork();
		if (pid < 0) {
			kill_children(children_pids);
			return 1;
		}
		else if (pid == 0) {
			prctl(PR_SET_PDEATHSIG, SIGHUP);
			for (int j = 0; j < (i + 1) * iterations_number; ++j) {
				write_log(message, j + 1);
				sleep(1);
			}
			break;
		}
		else {
			children_pids.push_back(pid);
		}
	}
	int status = 0;
	if (pid > 0) {
		while (wait(&status) > 0) {
			if (status != 0) {
				exit(1);
			}
		}
	}
	return 0;
}
