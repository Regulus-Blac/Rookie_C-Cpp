#include<stdio.h>
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		
		for(j=1;j<=i;j++){
			
			printf("%d*%d=%-4d",j,i,i*j);
		//-4d是 左对齐 场宽4 无精度 整数 
		}printf("\n");
		}	
	
	return 7;		
	}

	
	

	

