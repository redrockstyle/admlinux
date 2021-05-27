#include <fstream>
#include <string>
#include <vector>
#include <iostream>

#include <sys/wait.h>
#include <unistd.h>

constexpr auto filename = "log.txt";

void process(const std::string &message, const unsigned int processes, const unsigned int iterations) {
    std::vector<unsigned int> pids;
    unsigned int pid;
    for (unsigned int i = 0; i < processes; i++) {
        pid = fork();
        if (pid == 0) {
            for (unsigned int j = 0; j < (i + 1) * iterations; j++) {
                std::ofstream log(filename, std::ios::app);
                log << message << " " << j + 1 << std::endl;
                sleep(1);
            }
            break;
        } else {
            pids.push_back(pid);
        }
    }
    int status = 0;
    if (pid > 0) {
        while (wait(&status) > 0) {
            if (status != 0) {
                exit(0);
            }
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 4) {
        std::cout << argv[0] << "<message> <processes> <iterations>";
        return 1;
    }
    const std::string message = argv[1];
    const unsigned int processes_number = std::strtol(argv[2], nullptr, 10);
    const unsigned int iterations_number = std::strtol(argv[3], nullptr, 10);
    std::ofstream log(filename);
    log.close();
    process(message, processes_number, iterations_number);
    return 0;
}
