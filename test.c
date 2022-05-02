#include <stdio.h>
#include <unistd.h>

int main()
{
    char* str = "/bin/sh";
    char* arg[2];
    arg[0] = str;
    arg[1] = 0;

    execve(str, arg, 0);
    return 0;
}
