#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int function2(char* str2)
{
    char buffer[100];
    strcpy(buffer, str2);
    return 1;
}

int function1(char* str1, char* str2)
{
    char buffer[300];
    printf("function1 buffer: %p\n", &buffer);
    strcpy(buffer, str1);
    function2(str2);
    return 1;
}

int main()
{
    char str1[400];
    char str2[400];
    FILE* fp1;
    FILE* fp2;

    fp1 = fopen("asm-1.txt", "r");
    fread(str1, sizeof(char), 300, fp1);

    fp2 = fopen("badfile.txt", "r");
    fread(str2, sizeof(char), 300, fp2);

    function1(str1, str2);
    printf("returned\n");
    
    return 0;
}
