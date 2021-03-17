1 какой командой вывести файл на экран?
```
cat file
```
2 Какая команда позволяет просматривать файл и искать в нем что-либо во время просмотра?
```
less file
```
3 Какой командой вывести первые 5 строк файла?
```
head -n5 file
```
4 Какой командой вывести бинарный файл в 16-и ричном виде начиная с 301 байта?
```
od -j 300 -x file
```
5 Какая команда добавит содержимое файла file1 в конец файла file2?
```
cat file1 >> file2
```
6 Какая команда выведет только строки файла, содержащие латинскую букву первым символом?
```
cat file | grep ^[a-zA-Z]
```
7 Какая команда выведет содержимое архива tar?
```
tar -tf archive.tar
```
8 Как создать архив tar.gz содержащий директорию с файлами? Использовать tar и gzip через взаимодействующие через канал.
```
tar -c dirname/* | gzip > archive.tar.gz
```
9 В текущий момент код процесса less ожидает ввода с клавиатуры. Каким процессом он является?
```
спящий
```
10 Команда cat была запущена из интерпретатора bash и получила числовой идентификатор 5348. Для cat 5348 - это?
```
pid
```
11 Какая команда покажет только процессы, запущенные в рамках текущей сессии
```
ps
```
12 Запустить процесс с правами владельца исполняемого файла поможет установка?
```
бита SUID
```
13 Какая командf приостановит процессы с именем tar?
```
killall -s STOP tar
```