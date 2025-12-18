#include <stdio.h>
int main()
{
	int a,b,c,d;int n=0;
	scanf("%d",&a);
	d=c=b=a;

	for (b=a;b<a+5;b++)
	{   
		for (c=a;c<a+5;c++)
		{
			for (d=a;d<a+5;d++)
				{if(d!=c&&d!=b&&c!=b)
					{
				n++;
				if(n%6==0)
					printf("%d%d%d\n",b,c,d);
				else
					printf("%d%d%d ",b,c,d);}
			}
		}
	}
	
	// 20mins加油！
	// 一开始printf写在了每一个for后面，但这会让百位和十位是分离的 
	// 三个不等都要写，不能省 
	return 5;
}
