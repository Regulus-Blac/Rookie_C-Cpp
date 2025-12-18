#include<stdio.h>
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		
		for(j=1;j<=i;j++){
			
			printf("%d*%d=%d",j,i,i*j);
			if(i*j<10)
				printf("   ");
			else
				printf("  ");
		}printf("\n");//一开始错在把两个三个空格和换行写成if else if和else了
		//但这样的话1*2之后因为有j++，i&j会相同 
		}	
	
	return 6;		
	}

	
	

