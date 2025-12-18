#include <stdio.h>

	enum DAY{
		MON,TUE,WED,THUR,FRI,SAT,SUN
	}day;
	int main(){
		printf("%d",TUE+WED);
		printf("%d,%d",sizeof(TUE),sizeof(day)) ;
}
