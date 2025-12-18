#include <stdio.h>
int main()
{
	int x;
	scanf("%d",&x);
	int hour1=x/100;
	int minute1=x%100;
	if(hour1<8){
	hour1+=24;
	}
	int hour2=hour1-8;
	if(hour2==0){
		printf("%d",minute1);
	}else{
		if(minute1>9){
			printf("%d%d",hour2,minute1);
		}else{
			printf("%d0%d",hour2,minute1);
		}
	}
	
	
	
	return 0;
}
