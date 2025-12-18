#include <stdio.h>
int main()
{
/*	int num,left;int d=1;int n=0;
	scanf("%d",&num);
	
	for(d=1;0<d&&d<=num;d++)	
	{left=num%d;
	if(left==0)
{n++;
}
	}
	if(n==2)
	printf("这是一个素数\n");
	else
	printf("这是一个合数\n它有%d个因数\n",n);
	
	挺不错但是会循环好多次，比较慢，下面是改进版 */
	
	int num,d; int c=0;
	scanf("%d",&num);
	
	for(d=2;d<num;d++)
	{if(num%d==0)
	{
	c=1;
	printf("这是一个合数\n");
	break;}
	}
if(c==0)
	printf("这是一个素数\n");
	
	
	return 999;
}
