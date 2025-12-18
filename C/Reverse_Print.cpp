/*反向输出字符串*/
/*	01全反 
#include<stdio.h>
int main()
{
	char arr[50];
	char c,t;	int i=0;
	while((c=getchar())!=EOF&&c!='\n'){
		arr[i]=c;
		i++;
	}
	for(int j=0,k=--i;j<k;j++,k--){
		t=arr[j];
		arr[j]=arr[k];
		arr[k]=t;
	}
	for(int a=0;a<=i;a++){
		printf("%c",arr[a]);
	}
 } 
 */
 /*	02词正顺序反 无空格 */
#include<stdio.h>
#define LIMIT 50

int Getword(char*p)
{
	char c;
	while((c=getchar())!=' '&&c!='\n'&&c!='\t'&&c!=EOF){
		*p++=c;	//将连续内容写入数组 
	}
//	if(c==' '||c=='\t'){
//		*p++=c;
//	} 
	*p='\0';	//为输出字符串而结尾补0
	return c; 
}
int reverse()
{
	char arr[LIMIT];
	int c;
	if((c=Getword(arr)!='\n'&&c!=EOF)){
		reverse()!=EOF;
	}
	printf("%s",arr);
	return c;
 } 

int main()
{
	while(reverse()!=EOF){
		printf("\n");	//调用函数，并以换行结束整个程序 
	}
	return 0;
 }
