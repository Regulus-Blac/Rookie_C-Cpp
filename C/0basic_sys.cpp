#include<stdio.h>

void output_m(char* buf, int len)
{
    for (int i = 0; i < len; i++) {
        if (buf[i] != '\0')
            printf("%c (0x%02X) ", buf[i], (unsigned char)buf[i]);
        else
            printf("\\0 (0x00) ");
    }
    printf("\n");
    return;
}

int main()
{
	short a = 19;
	int num = 0;
	char buf[20];
	
	printf("%x\n",*(char *)&a);
	printf("%x\n",*((char *)&a + 1));
	
	buf[num ++] = *(char *)(&a);
	output_m(buf, 1);
	
	buf[num ++] = *((char *)&a + 1);
	
	output_m(buf, 2);
	
	
	return 0;
 } 
