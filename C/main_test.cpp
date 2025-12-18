#include <stdio.h>

int main(int argc,char*argv[])
{
    printf("命令行参数有%d个",argc);
    for(int i=0;i<argc;i++) {
    	printf("第%d个参数：",i+1);
    	printf("参数值：%s\n",argv[i]); 
	} 
	return 0;
}

