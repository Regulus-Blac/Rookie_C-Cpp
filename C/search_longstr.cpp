/*编写一个函数，从n个字符串中找出最长的串，如果有多个则取最先找到的那一个
n和表示n个字符串的指针数组由参数提供，指向最长串的指针通过函数返回，最长串的长度由参数带回*/
# include<stdio.h>
# include<stdlib.h>
# define MAX 100			//最多100个字符串 
# define MAX_LEN 30			//字符串最长有30个字符 
char *SrchLong(int n,char *text[],int *max)
{
	char *strlong,*t,*src;
	int len;
	for(int i=0;i<n;i++) {
		t=text[i];
		src=t;
		len=0;
		while(*t!='\0'){
			len++;
			t++;
		}
		if(len>*max){
			strlong=src;
			*max=len;
		}
	}	
	return strlong;
}

int main()
{
	char *text[MAX],c,*longret;
	int i=0,max=0,*MAXp;
	MAXp=&max;
	//在 C 语言中，声明一个指针数组如果想用它来存储字符串的话 
	//要用 malloc 分配内存
	for(i=0;i<MAX;i++){
		text[i] = (char *)malloc(MAX_LEN * sizeof(char));
		if((scanf("%s",text[i]))==EOF)break;
		c=getchar();
		
		if(c=='\n') break;		
	}
	
	longret=SrchLong(i+1,text,MAXp);
//若输出字符指针数组的*p，则是字符串中的第几个字符，若输出p，则是第几个字符串
//这里的指针其实就是字符数组（字符串）
	printf("%s %d",longret,max);
	
 	for(int k=0;k<i;k++)
 		free(text[k]);
 		
	return 0;
}

















