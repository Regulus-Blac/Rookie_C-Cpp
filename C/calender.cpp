/*输入一个日期（年、月、日），计算并输出该日期是这一年的第几天。*/ 
#include <stdio.h>
int ISLEAP(int a)
{
	int eryue;
	if(a%4==0&&a%100!=0||a%400==0)
	eryue=29;else
	eryue=28;
	return eryue;
}

int main()
{
	int year,month,day,cnt ;
	scanf("%d %d %d",&year,&month,&day);
	int days_of_month[13]={0,31,ISLEAP(year),31,30,31,30,31,31,30,31,30,31};
	
	for(int i=month;i>0;i--){
		cnt+=days_of_month[i-1] ;
	}//把整月都加上 
	
	cnt+=day;//最后加天数 
	
	printf("%d",cnt);
	return 0;
}
