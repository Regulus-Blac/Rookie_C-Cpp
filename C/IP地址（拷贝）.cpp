/*IP地址通常是4个用句点分隔的小整数（即点分十进制），但这些地址在机器中是用一个4字节无符号整型数表示的。例如3232235876，
其机内二进制表示就是11000000 10101000 00000001 01100100，按照8位一组用点分开，该IP地址就写成192.168.1.100。
读入无符号整型数表示的互联网IP地址，对其译码，以常见的点分十进制形式输出。要求循环输入和输出，直至输入Ctrl+Z结束。*/
#include <stdio.h>
int main()
{
	const unsigned short int NUM=8,LEN=4;
	unsigned int x;
	int a[LEN]; 
	
	while(scanf("%d",&x)!=EOF){
	for(int i=0;i<LEN;i++){
		a[i]=(x>>i*NUM)&0xFF;
	}
	printf("%d.%d.%d.%d\n",a[3],a[2],a[1],a[0]);

	}
	return 0;
}
