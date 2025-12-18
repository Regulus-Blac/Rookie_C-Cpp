/*供菜单选项(0-4,其中0为退出)。对应菜单选项1-4，该程序具有以下功能：
（1）“成绩输入”，输入n个学生的姓名和C语言课程的成绩。
（2）“成绩排序”，将成绩按从高到低的次序排序，姓名同时进行相应调整
成绩相同的，按照输入先后次序排列。
（3）“成绩输出”，输出排序后所有学生的姓名和C语言课程的成绩。
（4）“成绩查找”，输入一个C语言课程成绩值，用二分查找进行搜索。如果查找到有该成绩，
则输出该成绩学生的姓名和C语言课程的成绩;否则，输出提示“not found！”。	*/

#include <stdio.h>
#include <string.h>
#define CAP 100		//最大人数 
char name[CAP][20];	//二维数组储存人名 
int num[CAP];	
int cnt;
//为排序做准备 
void swap(int j)
{
		int t1=num[j];	
		num[j]=num[j+1];	
		num[j+1]=t1;
		char t2[20];
		strcpy(t2,name[j]);	
		strcpy(name[j],name[j+1]);
		strcpy(name[j+1],t2);
		//name[j]是二维数组一维化，后仍为一个一维数组，所以不可以直接char t2=它 
		//利用strcpy交换人名 
	}
//记录成绩 	
void input(void)
{
	scanf("%d",&cnt);
	int i;	int a=cnt;
	
	for(i=0;a>0;i++){
		scanf("%s",&name[i]);
		scanf("%d",&num[i]);
		a--;
	}
	printf("%d records were input!\n",cnt);
}
//成绩排序 (冒泡排序)
void sort(void)			
{
	int j;
	for(int k=cnt-1;k>0;k--){
		
		for(j=0;j<k;j++){
			
			if(num[j]<num[j+1]){
			swap(j);	}//成绩低的到了最后 	
		}	
	}
	printf("Reorder finished!\n");

}
//输出 
void output(void)
{
	for(int c=0;c<cnt;c++){
	printf("%s %d\n",name[c],num[c]);
	}
	
}
//查找特定成绩 
void search(void)
{
	int t,i,flag=0;
	scanf("%d",&t);
	for(i=0;i<cnt;i++){
		if(t==num[i]){
		printf("%s %d\n",name[i],num[i]);
		flag=1;
		}
	}
	//循环遍历法 
	if(flag==0){
		printf("not found！");
	} 
//int left=0;int right=cnt-1;
//	int middle=(cnt-1)/2;
//	while(left!=right){	
//		if(num[middle]==t){
//			printf("%s %d\n",name[middle],num[middle]);
//			flag=1;
//			break;
//		}
//		else if(num[middle]>t){
//			left=middle+1;
//			middle=(right+middle)/2;
//		}else{
//			middle=(middle-1)/2;
//			right=middle-1;
//		}
//	}
//
//	if(flag==0&&num[right]!=t){
//	printf("not found！");}
//}
// 二分查找法，但我感觉只能查一次 
}
int main()
{
  	int n ;
	int code=1;
	
	scanf("%d",&n);
	while(code&&n>0&&n<=4){
		
		switch(n){
			case 0:
				code=0;
				break;
			case 1:	
				input();
				break;
				
			case 2:
				sort();
				break;
			case 3:	
				output();
				break;
			case 4:	
				search();
				break;
		} 
		
		scanf("%d",&n);		
	}
    return 0;
}
