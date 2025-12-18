#include <stdio.h>
int main()
{
	printf("您想查询多少以内（包括）的素数？\n"); 
		int num,d,max; 
	scanf("%d",&max);
	
	for(num=2;num<=max;num++)
	{	int c=0;//一定要在循环里定义！！！！！！！！！不然每一次并不会归零 
			for(d=2;d<num;d++)
			{if(num%d==0)
				{c=1;
				break;}
	     	}
				if(c==0)
					printf("%d\n",d);
				

	
	}
	

	return 999;
}
