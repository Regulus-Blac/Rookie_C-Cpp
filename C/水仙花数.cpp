#include <stdio.h>
int main()
{
	int x,tr;int ten=1;
	scanf("%d",&x);
	int y=x;
	while(y>1)
	{y--;
	ten*=10;
	 } 
	//此时y=1，下面遍历
	
	for(tr=ten;tr<ten*10;tr++) //tr表示范围内的数，想用try，但这是保留字段 
	{
		int sum=0;//不然下一个tr也会加上前一个数的sum 
		int t=tr;//保护tr 
		int j=ten;//保护ten值
			for(;j>0;j/=10){
				int ret=t/j;
				t%=j;//整数分解 
             int r=ret;
			 //超级重要，若没有r保护ret，就会是ret乘自己，eg 5->25->625[而非125] 
			int i=1;
				while(i<x){
					i++;
					ret*=r;
				}//表示乘方 
			
				sum+=ret;	}
			
			if(sum==tr)
				printf("%d\n",tr);
			
		
	}
		
	return 1;
}
