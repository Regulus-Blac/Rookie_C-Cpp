#include <stdio.h>
#include<string.h>
int main()
{
	char *s="Hello World!";
	char *t="Hello World!";
	char p[]="Hello World!";
		
	printf("s的地址：%p\n",s);
	printf("t的地址：%p\n",t);
	printf("p的地址：%p\n",p);
	
	p[0]='C';
	printf("p[0]:%c\n",p[0]);	
	s[0]='C';	
	printf("s[0]:%c\n",s[0]);
	t[0]='C';
	printf("t[0]:%c\n",t[0]);

		
	return 0;
}
