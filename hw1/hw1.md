# Установлена система Linux Debian 10
![Image alt](https://github.com/redrockstyle/admlinux/blob/hw1/deb.PNG)
____
## Вопросы
1. основные принципы Unix-way
```
Всё есть файл
Одна задача - одна программа
Есть множество путей решения
```
2. Линус Торвальдс является разработчиком чего
```
  Ядра Linux OS
```
3. Как посмотреть  название ядра системы из консоли?
```
uname -r
```
4. Промежутки измерения загрузки системы для команды uptime следующие
```
1 минута
5 минут
15 минут
```
5. какой командой узнать сколько занято на HDD
```
df -H
```
6. какие разделы содержит вывод команды vmstat
```	
procs - количество процессов
memory
swap
io - загрузка ввода/вывода
system
cpu - загрузка процессора
```
7. Описать работу своего Linux дистрибутива: какое ядро, архитектура, размеры hdd, объеме ОЗУ, загрузке процессора и т.д.
	
```
Ядро и архитектура по команде uname -ar:	
Linux debian 4.19.0-14-amd64 #1 SMP Debian 4.19.171-2 (2021-01-30) x86_64 GNU/Linux>
	 
HDD командой df -H:
Файловая система                                        Размер Использовано  Дост Использовано% Cмонтировано в
udev                                                      1,1G            0  1,1G            0% /dev
tmpfs                                                     207M         5,9M  201M            3% /run
/dev/sda1                                                  20M         1,8G   18G           10% /
tmpfs                                                     1,1G            0  1,1G            0% /dev/shm
tmpfs                                                     5,3M            0  5,3M            0% /run/lock
tmpfs                                                     1,1G            0  1,1G            0% /sys/fs/cgroup
tmpfs                                                     207M            0  207M            0% /run/user/0
	 
ОЗУ командой free -h:
             total       used       free     shared  buff/cache  available
Mem:         1,9Gi        95M      1,6Gi      5,0Mi       238Mi      1.7Gi
Swap:        974Mi         0B      974Mi
	
Загрузка процессора командой uptime:
 21:28:53 up 27 min,  1 users,  load average: 0,00, 0,00, 0,00
   ```
