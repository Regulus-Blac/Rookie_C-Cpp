#include<stdio.h>

 int main()
 {
	int a, b;
	scanf("%d %d", &a, &b);
	
int max=a>b?a:b;
int min=a>b?b:a;
int i,j; int c,n=0;
for(i=min;i<=max;i++)
	{
       c=0;//关键！！！又忘了！！！ 
		for(j=2;j<i;j++)
		{
			if(i%j==0)
			{c=1;
			break;}
		}
		
		if(c==0)
		{n++;
		printf("%d\n", i);
		}	
	}
	printf("共%d个素数", n);
	return 0;
}
