/*一个整型变量占4个字节，其中每个字节又分成高4位和低4位
输入一个整型变量，从高字节开始，依次取出每个字节的高4位和低4位并以十六进制数字字符的形式进行显示
要求通过指针取出每字节。*/
#include<stdio.h>
void change(char upbyte)
{
	if(upbyte<10){
		printf("%c",upbyte|'0');
	}else{
		printf("%c",upbyte-10+'A');
	}
}
int main()
{
	int n;	scanf("%d",&n);
	char *p=(char*)&n;
	char upbyte,lowbyte;
	
	for(int k=0;k<4;k++){
		upbyte= (*(p+3-k)>>4)& 0x0f;
		lowbyte=(*(p+3-k))& 0x0f;
		change(upbyte);	change(lowbyte);	

	}
}

