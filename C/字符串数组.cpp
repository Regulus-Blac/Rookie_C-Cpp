#include <stdio.h>
int main()
{
	const int MONTH=12;
	printf("请输入月份，我将把它翻译为英语 \n");
	int month;
	scanf("%d",&month);
	
	char *a[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
	
/*	for(int i=0;i<MONTH;i++){
		if (i+1== month)
		printf("%s",a[i]);
	}        */
	
	printf("%s\n",a[month-1]);
	
	
	return 0;
}
