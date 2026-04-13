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
        perror("file open failed");
        exit(1);
    }
    pid_t pid = fork();
    if (pid == 0)
    {
        char *msg1 = "this line is written by the child process";
        char ans1 = write(fd, msg1, strlen(msg1));
        sleep(1);
        printf("%d", ans1);
    }
    if (pid > 0)
    {
        char *msg2 = "this line is written by the parent process ";
        char ans2 = write(fd, msg2, strlen(msg2));
        sleep(1);
        printf("%d", ans2);
    }
    return 0;
}