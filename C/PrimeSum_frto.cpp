#include<stdio.h>
int main()
{
	int m,n;
	scanf("%d %d",&m,&n);
	int max=m>n?m:n;int min=m>n?n:m;//分大小 
	
	int t,c,sum=0;
	int x,d;
	for(x=min;max>=x;x++)
	{
		for(d=2;d<x;d++)
		{
			c=0;       //问题一：必须每次循环都归零！！！！！！！！不然c一直是1了 【谋划】 
			if(x%d==0)
			{c=1;//引入变量来使素数能够被下一步表示 
			break;	
				}  //问题二：if下有多条语句时不加大括号，导致大括号混乱 【规范】 
		} 
	
		if(c==0){
			t++;
		sum+=x;
		}
		
	
	}
	printf("%d %d",t,sum);
	
	return 2;
}
