/* 01.
从input.txt文件中输入若干行字符（最后一行字符串为：-END-）
将每一行加行号后输出到output.txt文件中
*/
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#define MAX 100
//int IsSame(char c[])
//{
//	int flag=1;
//	if(strcmp(c,"-END-")==0)	flag=0;
//	return flag;
//}
//
//int main()
//{
//	char add[MAX];
//	int num=0;
//	FILE *fp1,*fp2;
//	
//	if((fp1=fopen("D:\\Study\\C\\作业\\test.txt","r"))==NULL){
//		printf("Can not open infile\n");
//		exit(-1);
//	}
//	if((fp2=fopen("D:\\Study\\C\\作业\\output.txt","w+"))==NULL){
//		printf("Can not open outfile\n");
//		fclose(fp1);
//		exit(-1);
//	}
//		
//	if((fgets(add,MAX,fp1))==NULL){
//		printf("Can not fgets");
//	}
//	num++;
//
//	while(IsSame(add)){
//		
//		fprintf(fp2,"00%d %s",num,add);
//		fgets(add,MAX,fp1);
//		num++;
//	}
//	fclose(fp1);
//	fclose(fp2);
//	
//	if((fp2=fopen("D:\\Study\\C\\作业\\output.txt","r"))==NULL){
//		printf("Can not printout!\n");
//		exit(-1);
//	}
//	while(!feof(fp2)){
//		if((fgets(add,MAX,fp2))!=NULL){
//			printf("%s",add);
//		}
//	}
//	fclose(fp2);
//	
//	return 0;
//}

/*02
编写一个程序，统计input.txt文件(英文)中字符、单词及句子的个数（空格和换行符不做统计），并按照以下格式输出结果至文件output.txt中：
Characters: 439
Words: 76
Sentences: 3
*/
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	FILE *fp1,*fp2;
//	char t;
//	int c=0,word=0,sen=0,edge=1;
//
//	
//	if((fp1=fopen("D:\\Study\\C\\作业\\input.txt","r"))==NULL){
//		printf("Can not open infile\n");
//		exit(-1);
//	}
//	
//	if((fp2=fopen("D:\\Study\\C\\作业\\output.txt","w"))==NULL){
//		printf("Can not open outfile\n");
//		fclose(fp1);
//		exit(-1);
//	}	
//	while(!feof(fp1)){
//		t=fgetc(fp1);
//		if(t==' '){
//			if(edge==1){
//				word++;	
//			}
//				
//		}
//		else if(t=='.'){
//			sen++;	c++;	edge=1;
//		}
//		else if(t>='0'&&t<='9'){
//			edge=0;			
//			c++;
//		}		
//		else if(t=='\n'){
//			word++;	edge=0;
//		}
//		else 
//			c++;	edge=1;
//	}
//	fprintf(fp2,"Characters: %d\nWords: %d\nSentences: %d\n",c-1,word+1,sen);
//	/*c 的值在最后一次读取时会增加 1，因为 fgetc(fp1) 在文件结束时会返回 EOF，并且在 EOF 之前的最后一个字符也会被计数
//	由于 EOF 不是文件中的有效字符，因此在输出字符数时需要减去 1	*/
//	fclose(fp1);
//	fclose(fp2);
//	
//		if((fp2=fopen("D:\\Study\\C\\作业\\output.txt","r"))==NULL){
//		printf("Can not printout!\n");
//		exit(-1);
//	}
//	while(!feof(fp2)){
//		if((t=fgetc(fp2))!=EOF){
//			printf("%c",t);
//		}
//	}
//	fclose(fp2);
//
//	return 0;
// } 
 /*03
 给定文件input.txt中的替换单词，替换掉文件中段落的目标单词（如果目标单词后连着标点符号则不用替换）
 替换完成后将替换后的段落以及修改信息写入文件output.txt。
修改信息的格式为：##x modified##，其中x为替换的次数。注意被替换后的段落和修改信息之间有一空格。
you they	you：替换单词，they：目标单词 
##2 modified##
*/
//本代码并未考虑开头为非字母的情况，不过无伤大雅，省了点事而已~ 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20
typedef struct sheet{
	char c[MAX];
	struct sheet *next;
}SHEET;

SHEET* inputsheet()
{	//队列 
	SHEET *tail=NULL,*head=NULL,*p;
	char temp[MAX],t;
	while ((scanf("%s",temp))!=EOF) { 
        p = (SHEET*)malloc(sizeof(SHEET));

        strcpy(p->c, temp); 
        
        p->next = NULL; 

        if (head == NULL) {
        	tail=p;
            head = p; 			// 第一个节点
        } else {
            tail->next = p; 
        }
        tail = p; 
        t=getchar();
        if(t=='\n')
        	break;
    }

	return head;
}

void Replace(SHEET *head,char tar[],char des[],int *num)
{
	char temp[MAX];
	SHEET *p;
	p=head;

	while(p) {
		if(strcmp(tar,p->c)==0){
			strcpy(p->c,des);
			(*num)++;
		}
		p=p->next;
	}						
}

int main()
{
	int n=0,*num=&n; 					//存次数 
	SHEET *p,*head;

	FILE *fp;	

	if((fp=fopen("D:\\Study\\C\\作业\\output.txt","w"))==NULL){
		printf("Can not open outfile\n");
		exit(-1);
	}
	char tar[MAX],des[MAX];
	scanf("%s %s",tar,des);	
	
	head=inputsheet();			//将文件中的文本存到链表中去 

	Replace(head,tar,des,num);	
	p=head;
		
	while(p){
		fputs(p->c,fp);
		fputc(' ',fp);
		p=p->next;
	}								//输出到output文件中 
	fprintf(fp,"##%d modified##",*num);	
	fclose(fp);	
	//下面为验证 
	if((fp=fopen("D:\\Study\\C\\作业\\output.txt","r"))==NULL){
		printf("Can not printout!\n");
		exit(-1);
	}
	char t;
	while(!feof(fp)){
		if((t=fgetc(fp))!=EOF){
			printf("%c",t);
		}
	}
	
	fclose(fp);

	return 0;
 } 
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#define MAX 20
//int main(){
//	char tar[MAX],des[MAX],temp[MAX],t;
//	int num=0;
//	scanf("%s %s",tar,des);
//	
//	FILE *fp;	
//
//	if((fp=fopen("D:\\Study\\C\\作业\\output.txt","w"))==NULL){
//		printf("Can not open outfile\n");
//		exit(-1);
//	}	
//	
//	while((scanf("%s",temp))!=EOF){
//		t=getchar();
// 
//		if(strcmp(temp,tar)==0){
//			num++;
//			fprintf(fp,"%s",des);
//		}else{
//			fprintf(fp,"%s",temp);
//		}
//		fputc(' ',fp);
//		if(t=='\n') break;
//	}
//	
//	fprintf(fp,"##%d modified##",num);	
//	fclose(fp);
//	//验证 
//		if((fp=fopen("D:\\Study\\C\\作业\\output.txt","r"))==NULL){
//		printf("Can not printout!\n");
//		exit(-1);
//	}
//
//	while(!feof(fp)){
//		if((t=fgetc(fp))!=EOF){
//			printf("%c",t);
//		}
//	}
//	
//	fclose(fp);
//	
//	return 0;
//}
	

	
	
	
	
	
	
	
	
	
	




