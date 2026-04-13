// Develop a c program that demonstrares process sychronisation and shared  file access the program shall create a child process; both process will then write uniqqe identifiers to a common file.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    int fd = open("output.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
    if (fd < 0)
    {
        perror("File open failed");
        exit(1);
    }
    pid_t pid = fork();

    // Write child login
    if (pid == 0)
    {
        char msg[] = "This line is writen by the child process";
        int n = strlen(msg);
        write(fd, msg, n);

        // printf("%d",strlen(msg));
    }
    // Write parent login
    // if(pid>0){
    //     char msg[]= "This line is write by the child process";

    // }

    return 0;
}