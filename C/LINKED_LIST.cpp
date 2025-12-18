/*课后练习：栈*/
//#include<stdio.h>
//#include<stdlib.h>
//struct text{
//	char c;
//	struct text *next;
//};
//typedef struct text TEXT;
//
//int main()
//{
//	TEXT *head=NULL,*p;
//	char x;
//	while((x=getchar())!=EOF) {
//		p=(TEXT *)malloc(sizeof(TEXT));
//		p->c=x;
//		p->next=head;
//		head=p;
//	}
//	TEXT *t=head;
//	while(t!=NULL) {
//		t=head;
//		head=t->next;
//		printf("%c",t->c);
//		free(t);
//	}
//	return 0;
//}
/*01.1
输入一行字符，直到达到文件的结尾（EOF，End of File）
建立一个先进先出单链表，链表的每个结点含有输入的一个字符。再完成下列任务：
（1）遍历输出该链表中所有字符；
（2）将该链表中所有字符无冗余地存放到一个通过动态存储分配创建的字符数组中
并且输出该字符数组的长度以及该字符数组的内容。(最后代码未保留该项)
*/
											//标准先进先出模版 
//#include<stdio.h>
//#include<stdlib.h>
//typedef struct sheet{
//	char c;
//	struct sheet *next;
//}SHEET;
//
//SHEET* inputsheet(void)
//{	//队列 
//	char cha;
//	SHEET *tail=NULL,*head=NULL,*p;
//	if((cha=getchar())!=EOF){
//		p=(SHEET*)malloc(sizeof(SHEET));
//		p->c=cha;
//		tail=p;
//		head=p;
//		//首元素 
//		while((cha=getchar())!=EOF){
//			p=(SHEET*)malloc(sizeof(SHEET));
//			p->c=cha;
//			tail->next=p;
//			tail=p;
//		}
//		tail->next=NULL;
//	}
//
//	return head;
//}
//
//void outputsheet(SHEET *head)
//{
//	while(head){
//		printf("%c",head->c);
//		head=head->next;
//	}
//}
//
//int main()
//{
//	SHEET *head;
//	head=inputsheet();
//	outputsheet(head);
//	
//	return 0;
// } 
/*01.2
增加功能：输入一个字符，如果该字符已在链表中，删除该字符的所有结点；
否则在输入字符和结点的数据域字符差的绝对值最大的第一个节点后面插入包含输入字符的结点
*/
//心路历程：一开始没有搞定循环，对连续重复的例子不适用，后来发现头上的连续也不好搞
//再然后发现会多输出，发现是因为把头上的改了之后没有flag=1
//最后发现结尾是连续的也出了问题 
										//唯一真神 
//#include<stdio.h>
//#include<stdlib.h>
//#define MAX 100
//typedef struct sheet{
//	char c;
//	struct sheet *next;
//}SHEET;
////找最大者
//int searchmax(int t[],int len) {
//	int max=0;
//	for(int i=0;i<len;i++){
//		if(t[i]>max){
//			max=t[i];
//		}
//	}
//	return max;
//}
////输入 
//SHEET* inputsheet(void)
//{	//队列 
//	char cha;
//	SHEET *tail=NULL,*head=NULL,*p;
//	if((cha=getchar())!=EOF){
//		p=(SHEET*)malloc(sizeof(SHEET));
//		p->c=cha;
//		tail=p;
//		head=p;
//		//首元素 
//		while((cha=getchar())!=EOF&&cha!='\n'){
//			p=(SHEET*)malloc(sizeof(SHEET));
//			p->c=cha;
//			tail->next=p;
//			tail=p;
//		}
//		tail->next=NULL;
//	}
//
//	return head;
//}
////输出 
//void outputsheet(SHEET *head)
//{
//	while(head){
//		printf("%c",head->c);
//		head=head->next;
//	}
//}
////插入 
//void insertsheet(SHEET *head,char target)
//{
//	SHEET *add=(SHEET *)malloc(sizeof(SHEET));
//	SHEET *ori=head;
//	char ccc;
//	add->c=target;
//	
//	int t[MAX],i=0,loca; 
//	while(ori){
//		ccc=ori->c;
//		t[i++]=abs(target-ccc);
//		ori=ori->next;
//	}
//	
//	loca=searchmax(t,i);
//
//	for(int j=0;j<MAX;j++){
//		if(t[j]==loca)
//			break;
//		head=head->next;
//	}
//	add->next=head->next;
//	head->next=add;
//}
////删除（和插入） 
//SHEET *replace(SHEET *head,char target)
//{
//	int flag=0;
//	SHEET *newhead=head,*p;
//
//	if(head){
//		if(head->c==target){
//			flag=1;				//头上的变了也不可以进入insertsheet 
//			while(head&&head->c==target){
//				head=head->next;
//			}
//		}
//		newhead=head;			//防止开头需要删除单个或连续个 
//		p=newhead;		
//		
//		while(p){
//			if(p->next&&p->next->c==target){
//				flag=1;				//别忘了p->next要存在
//				while(p->next&&p->next->c==target){//同理，也要存在！！！！！ 
//					p->next=p->next->next;
//				}
//			}
//			p=p->next;
//		}					
//	}
//
//	if(!flag){
//		insertsheet(newhead,target);
//	}
//	return newhead;
//}
//
//int main()
//{
//	SHEET *head,*newhead;
//	head=inputsheet();
//	
//	char target=getchar();
//	newhead=replace(head,target);
//	outputsheet(newhead);
//	
//	return 0;
// } 

/*01.3
小对比(删除特定元素~数组版) 
*/ 
//#include <stdio.h>
//void delete_c(char s[],char c){
//    int j=0,k=0;
//    while(s[j]){
//        if(s[j]!=c) s[k++]=s[j];
//        j++;
//    }
//    s[k]='\0';
//}
//int main()
//{
//    char string[100];
//    scanf("%s",string);
//    getchar();
//    delete_c(string,getchar());
//    printf("%s",string);
//    return 0;
//}	
/*02 MENU
用单向链表建立一张班级成绩单，包括每个学生的学号、姓名
英语、高等数学、普通物理、C语言程序设计四门课程的成绩。
除菜单0为退出外，菜单1-5分别实现下列功能：
① 输入每个学生的各项信息。
② 输出每个学生的各项信息。
③ 修改指定学生的指定数据项的内容。
④ 统计每个同学的平均成绩（保留2位小数）。
⑤ 输出各位同学的学号、姓名、四门课程的总成绩和平均成绩。
从main函数返回之前必须释放通过malloc等函数申请的内存空间。
*/
//#include<stdio.h>
//#include<stdlib.h>
//#define MAX_LEN 36
//
//typedef struct grade{
//	int num;
//	char name[MAX_LEN];
//	int eng;
//	int mat;
//	int phy;
//	int cgram;
//	struct grade *next;
//}GRADE;
//
////输入 
//GRADE* input(void)
//{
//	int cnt;
//	scanf("%d",&cnt);
//	GRADE *tail=NULL,*head=NULL,*p;
//
//	p=(GRADE*)malloc(sizeof(GRADE));
//	scanf("%d %s %d %d %d %d",&p->num,p->name
//	,&p->eng,&p->mat,&p->phy,&p->cgram);
//	tail=p;
//	head=p;
//
//	for(int i=0;i<cnt-1;i++) {
//		p=(GRADE*)malloc(sizeof(GRADE));
//		scanf("%d %s %d %d %d %d",&p->num,p->name
//		,&p->eng,&p->mat,&p->phy,&p->cgram);
//		tail->next=p;
//		tail=p;
//	}
//	tail->next=NULL;
//
//	printf("完成了%d位同学的成绩输入\n",cnt);
//
//	return head;
//}
////输出 
//void output(GRADE *p)
//{
//	while(p){
//		printf("%d %s %d %d %d %d\n",p->num,p->name
//		,p->eng,p->mat,p->phy,p->cgram);
//		p=p->next;
//	}
//}
////更改 
//void change(GRADE *p)
//{
//	int number,loca,flag=0;;
//	scanf("%d %d",&number,&loca);	getchar();
//	
//	while(p){
//		if(p->num==number){
//			flag=1;
//			break;
//		}
//		p=p->next;
//	}
//	
//	if(flag){
//		int t;/*系统不允许我们在case中定义一个变量,原因是我们在一个case中定义的变量
//		假如在另一个case中被使用就会出现错误，因为一般来说switch语句中的case只能被执行一个.
//		每一个case加一个大括号就行了*/
//		switch(loca){
//			case 0:{
//				char c;int i=0;
//				while((c=getchar())!=EOF&&c!='\n'){
//					p->name[i++]=c;
//				}
//				p->name[i]='\0';
//				break;
//			}
//			case 1: scanf("%d",&t);
//					p->eng=t;break;
//			case 2: scanf("%d",&t);
//					p->mat=t;break;
//			case 3: scanf("%d",&t);
//					p->phy=t;break;
//			case 4: scanf("%d",&t);
//					p->cgram=t;break;
//			default:printf("ERROR");break;		
//		}
//		printf("%d %s %d %d %d %d\n",p->num,p->name
//		,p->eng,p->mat,p->phy,p->cgram);
//	}else	printf("ERROR");	
//}
////算平均成绩 
//void average(char c,GRADE *p)
//{
//	GRADE *Thead=p;
//	float aver;	int sum;
//	while(p){
//		sum=p->eng+p->mat+p->phy+p->cgram;
//		aver=sum/4.0;//进行除法运算时，如果两个操作数都是整数，那么结果将是一个整数,so 改为4.0 
//		if(c-'0'==4)
//			printf("%d %s %.2f\n",p->num,p->name,aver);
//		if(c-'0'==5)
//			printf("%d %s %d %.2f\n",p->num,p->name,sum,aver);
//		p=p->next;
//	} 
//}
////所有人平均成绩与总成绩 
//
//int main()
//{
//	char c;	GRADE *head=NULL,*end;
//
//	while((c=getchar())!=EOF&&c!='0'){
//		switch(c-'0'){
//			case 1:head=input();			break;
//			case 2:output(head);			break;
//			case 3:change(head);			break;
//			case 4:case 5:average(c,head);	break;
//		}
//	}
//	while(head){
//		end=head;
//		head=head->next;
//		free(end);
//	}
//	
//	return 0;
// } 

/*03 约瑟夫问题	
N个人围成一圈并从1到N编号，从编号为1的人循序依次从1到M报数，报数为M的人退出圈子，后面
紧挨着的人接着从1到M报数。如此下去，每次从1报到M，都会有一个人退出圈子，
直到圈子里剩下最后一个人，游戏结束。
要求：用单向循环链表存放圈中人信息，编程求解约瑟夫问题，
输出依次退出圈子的人和最后留在圈中人的编号。
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct crowd{
	int num;
	struct crowd *next;
}CROWD;

int main()
{
	int m,n,cnt;	scanf("%d %d",&n,&m);	//n个人m个数 
	CROWD *p,*head,*tail;
	
	p=(CROWD *)malloc(sizeof(CROWD));
	p->num=1;
	tail=p;	head=p;
	
	for(int i=2;i<n+1;i++){
		p=(CROWD *)malloc(sizeof(CROWD));
		p->num=i;
		tail->next=p;
		tail=p;	
	}
	tail->next=head;					//闭环 
	p=head;
	
	for(int j=1;j<n;j++){
		for(int k=0;k<m-2;k++)
			p=p->next;					//m-2次，代表保到m-1了 
			
		printf("%d",p->next->num);
		if(j!=n-1)	printf(" ");
		
		p->next=p->next->next;	
		p=p->next;		
	}
	printf("\n%d",p->num);
	return 0;
}




