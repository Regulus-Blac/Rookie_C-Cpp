/*输入n行文本，每行不超过80个字符，用字符指针数组指向键盘输入的n行文本，且n行文本的存储无冗余。
然后执行如下操作：删除每一行中的前置空格（’ ‘）和水平制表符（’\t’），并将文本中多个空格合并为一个空格，如果有。
该操作要求单独定义成函数。在main函数中输出执行了以上操作的各行。
2			
  123    4   5  	 	等价于：##123@4###5## 
    5        6   789	 等价于：@5@@6###789 
123    4 5 		 		等价于：123@4#5# 
5        6 789			等价于：5@@6#789 */

/* 本题用伪代码先画一画效果奇佳 */ 
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 81			//每行最多字符 
#define LIMIT 10		//最多行数 

void onespace (char *text[LIMIT],int n)
{
	for(int i=0;i<n;i++){
		char *p=text[i];
		char *src=p,*t=p;
		int cnt=0,space=0;
		int len=strlen(text[i]);
		
		while(*p==' '||*p=='\t'){
			p++;
			cnt++;
		}
		
		for(int j=len-cnt;j>0;j--){
			*(src++)=*(p++);
		}
		*src='\0';
		p=t;				//回到开头
		while(*t!='\0') {
			
			if(*t==' '){
				if(*(t+1)!=' '||*(t+1)=='\0')
					*(p++)=*(t++);
				else{
					for(;*t==' '&&*t!='\0';t++);
					*p++=*(t-1);
					*p++=*t++;			//只计入一个空格，然后接着走 
				}
				
			} else {*(p++)=*(t++);	}
		}
		*p='\0';
	}		
}

int main(){
	int  n;	scanf("%d",&n);
	getchar();
	char temp[MAX];
	char *text[LIMIT];

	for(int i=0;i<n;i++){
		gets(temp);
		text[i]=(char *)malloc(sizeof(char)*(strlen(temp)+1));
		strcpy(text[i],temp);
	}							//01.存储无冗余 
	
	onespace(text,n);
	
	for(int i=0;i<n;i++)
		printf("%s\n",text[i]); 
		
	return 0;	
}

