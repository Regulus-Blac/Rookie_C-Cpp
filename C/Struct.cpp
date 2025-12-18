/*eg 01*/
//#include <stdio.h>
//
//struct date{		
//	int year;
//	int month;
//	int day;
//	}today;
//
//int main()
//{
//
//  	today=(struct date){2024,10,22};
//	struct date day=today;
//	day.month=12;
//	printf("Today's date is %i-%i-%i.\n",
//	today.year,today.month,today.day);
//	printf("%i",day.month);
//	return 0;
//}

#include<stdio.h>

typedef struct Birthday{
	int year;
	int month;
	int day;	
}Birthday;

typedef struct Student{
	int id;
	char name[50];
	float grade;
	Birthday Birthday;
}Student,stu1,stu2,stu3;
/*
void printstruct(Student stu)
{
	printf("学号 %d\t姓名 %s\t成绩 %.2f\t出生年月 %d-%d-%d\n",stu.id,stu.name,
	stu.grade,stu.Birthday.year,stu.Birthday.month,stu.Birthday.day);
}	*/
//但函数是拷贝，用指针会更高效 
void printstruct(Student * pstu)
{
	printf("学号 %d\t姓名 %s\t成绩 %.2f\t出生年月 %d-%d-%d\n",pstu->id,pstu->name,
	pstu->grade,pstu->Birthday.year,pstu->Birthday.month,pstu->Birthday.day);
}
int main()
{
	Student stu1={1001,"Tom Cruse",86,{1987,8,15}};
	Student stu2={.id=1002,"Zhangyibo",.grade=95,{.year=2001,.month=5,.day=8}};	//只有C99才可以.name来初始化 
	
	Student *pstu1=&stu1;
	Student *pstu2=&stu2;
	
	printstruct(pstu1);
	printstruct(pstu2);
	return 0;
}



















