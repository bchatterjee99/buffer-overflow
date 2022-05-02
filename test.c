#include <stdio.h>
#include <unistd.h>

int main()
{
    /* char* str = "/bin/sh"; */
    /* char* arg[2]; */
    /* arg[0] = str; */
    /* arg[1] = 0; */

    /* execve(str, arg, 0); */

    char* str = "hoe geche";

    int i = 0;
    while(str[i] != 0) 
    {
	printf("%c: 0x%2x\n", str[i], str[i]);
	i++;
    }

    return 0;
}
