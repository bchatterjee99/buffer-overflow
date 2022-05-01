#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int foo(char* arr)
{
    char buffer[100];
    strcpy(buffer, arr);
}

int main()
{
    char str[400];
    FILE* badfile;

    badfile = fopen("badfile.txt", "r");
    fread(str, sizeof(char), 300, badfile);

    /* for(int i=0; i<15; i++) */
    /* { */
    /* 	printf("%d: %d %c\n", i, str[i], str[i]); */
    /* } */


    foo(str);
    printf("Returned Properly\n");
    

    return 0;
}
