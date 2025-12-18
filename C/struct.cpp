/*01
设计一个含有年、月、日的日期结构类型，输入一个日期，计算并输出该日期是本年中的第几天。
如果日期不存在则输出error。
*/
//#include <stdio.h>

//struct DATE{
//	int year;
//	int month;
//	int day;
//}date;
//
//int IsLeap(int year){
//	int flag;
//	if(year%4==0&&year%100!=0||year%400==0)
//		flag=1;
//	else flag=0;
//	return flag;
//}
//
//int Isdate(struct DATE date,int *p) {
//	int situ;	int code=IsLeap(date.year);
//	int a[13]={0,31,28+code,31,30,31,30,31,31,30,31,30,31};
//	if(date.month==2&&code==0&&date.day>28)
//		situ=0;
//	else if(date.month==2&&code&&date.day>29)
//		situ=0;
//	else{
//		situ=1;
//		for(int i=1;i<date.month;i++) {
//			*p+=a[i];
//		}
//		*p+=date.day;
//	}
//	
//	return situ;
//}
//
//int main()
//{
//	int t=0;
//	int *p=&t;									//	传递第几天 
//	scanf("%d%d%d",&date.year,&date.month,&date.day);
//	
//	if(date.year<0||date.month<0||date.month>12||date.day<1||date.day>31)
//		printf("error");
//	else{
//		if(Isdate(date,p))
//			printf("%d",*p);
//		else printf("error");
//		}
//	return 0;
//}
/* 02.
设有描述学生的结构类型声明为：
struct student {									3
int num; // 学号									1022010001 张三 98
char name[20]; // 姓名								1022010002 李四 89
int score; // 成绩									1022010003 王五 90
};
请编程完成任务：
（1）输入整数n，定义有n个元素的结构数组s并对其进行初始化
	同时定义结构指针p并使其指向s的最后一个元素；
（2）不用指针p，依次输出各数组元素的各成员之值。
（3）用指针p，依次逆序输出各数组元素的各成员之值。
*/
//#include<stdio.h>
//#define MAX 100
//struct student {
//	int num;					// 学号
//	char name[20]; 				// 姓名
//	int score; 					// 成绩
//}stu[MAX];

//int main(){
//	int n;	scanf("%d",&n);
//	struct student *p=stu;
//	for(int i=0;i<n;i++,p++)
//		scanf("%d%s%d",&stu[i].num,stu[i].name,&stu[i].score);
// 
//	for(int j=0;j<n;j++)
//		printf("%d %s %d\n",stu[j].num,stu[j].name,stu[j].score);
//			
//	p--;
//	
//	for(int k=0;k<n;k++,p--){
//		printf("%d %s %d",p->num,p->name,p->score);
//		if(k!=n-1)	printf("\n");
//	}		
//
//	return 0;
//}

/* 03.
本关任务：设计一个能够描述上网网址的结构类型struct web，它包含缩略名、全名、URL(网址)
缩略名 全名 URL(网址)
TXSP 腾讯视频 https://v.qq.com
BD 百度搜索网站 http://www.baidu.com
HKD 华中科技大学 http://www.hust.edu.cn
请构造对应的结构数组，程序接收n个常用的网址、缩略名、全名，按照缩略名排序后输出。
再输入一个缩略名，程序快速找到对应的URL（网址）并输出。
*/
#include<stdio.h>
#include<string.h>
#define MAX 100
struct WEB {
	char add[100]; 				// 网址
	char abbr[10];				// 缩略名
	char full[50]; 				// 全名
}web[MAX];
typedef struct WEB WEB;

void swap(WEB *a,WEB  *b)	//写了WEB就不用再写char了，struct WEB本身就是一种数据结构了
{
	WEB t=*a;
	*a=*b;
	*b=t;
}

WEB *Search(WEB web[],WEB t)
{
	WEB *ret;
	for(int k=0;k<MAX;k++) {
			if(!strcmp(web[k].abbr,t.abbr)){
				ret=&web[k];
				break;
			}			
	}
	return ret;
}

int main()
{
	int n;	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%s%s%s",web[i].add,web[i].abbr,web[i].full);
	for(int j=0;j<n-1;j++) {
		for(int k=0;k<n-1-j;k++) {
			if(strcmp(web[k].abbr,web[k+1].abbr)>0)		//不能不写>0,因为非零即为TRUE 
				swap(&web[k],&web[k+1]);
		}
	}
	
	for(int i=0;i<n;i++){
		printf("%s %s %s\n",&web[i].add,&web[i].abbr,web[i].full);
	}
	WEB temp;
	scanf("%s",temp.abbr);	
	
	WEB *Ret=Search(web,temp);
	printf("%s",Ret->add);
	
	return 0;
}
























