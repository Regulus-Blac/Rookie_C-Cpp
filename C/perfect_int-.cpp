#include<stdio.h>
int Isperfect(int a )
{
	int ret,sum=0 ;

	for(int j=1;j<a;j++){
		if(a%j==0)
		sum+=j;	
	} 

	if(sum==a)ret=1;
	else ret=0;

	return ret;//单一出口 
}


int main()
{
	for(int i=2;i<10000;i++){
		if(Isperfect(i)==1){
			
			printf("%d=1",i);
			
			for(int j=2;j<i;j++){
				if(i%j==0){
				printf("+%d",j);			
				} 
				
			}			printf("\n");
		}
	}
return 0;
}





