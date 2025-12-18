/*用指针实现字符串连接,定义函数strnCat,从源串s中最多取n个字符添加到目标串t的尾部，且以’\0’终止
返回目标串t的首地址。源串s不应该被修改*/
#include <stdio.h>
#define MAX 50
char *strnCat(char src[],char sub[],int num)
{
	char *psrc,*psub=sub,*Pret=src;
	for (psrc=src;*psrc!='\0';psrc++ );
	for(int i=0;i<num;i++) {
		*(psrc++)=*(sub++);
	}
	*psrc='\0';
	return Pret;
}
int main()
{
	int n;
	char a[MAX],b[MAX],*ret;
	gets(a);
	gets(b);
	scanf("%d",&n);
			
	ret=strnCat(a,b,n);
	
	printf("%s",ret);
	
	return 0;
}
