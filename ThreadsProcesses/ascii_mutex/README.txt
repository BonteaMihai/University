Write a C program which receives as command line parameter a file name.
5 threads are opened, which receive the file descriptor as parameter. Each thread will read characters from the file,
and count how many characters have an even ASCII code and an odd one.