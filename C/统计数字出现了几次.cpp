#include<stdio.h>
int main()
{
	int x,i;
	const int border=10;//数组的大小 
	int num[border];
		for(i=0;i<border;i++)
	{
		num[i]=0;
	}//如果没有初始化数组，若某个数字没有出现就不会显示0而是显示一个计算机的随机数了！！！ 
	
	
	scanf("%d",&x);
	while(x!=-1)
	{
		if(x>=0&&x<border)
		num[x]++;
		scanf("%d",&x);
	}
	
	for(i=0;i<border;i++)
	{
		printf("%d出现了%d次\n",i,num[i]);
	}
	

	return 111;
}
