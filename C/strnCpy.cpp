/*编写一个将十六进制数字串转换成为对应整数的函数int atoh（const char nstr[]）
其中nstr是十六进制数字串，函数返回转换后的值。
具体实现时，main函数应首先读入n，再循环读入要处理的数字，
输入数字间以换行作为区分，输出数字间以空格作为区分。*/
//#include <stdio.h>
//		 
//#define MAXLEN 18
//int atoh(const char nstr[])
//{
//	const char *j=nstr;
//	char c;	int ret=0;
//	for(j=&nstr[2];*j!='\0';j++){
//		c=*j;	
//		if(c>64&&c<71){
//			c=c-'A'+10;
//		}else if(96<c&&c<103){
//			c=c-'a'+10;
//		}else{
//			c=c-'0';
//		}				//别忘了char中的'1''2'等数字也不是原来的！ 
//		ret= ret*16+c;
//	}
//	return ret;
//}
//
//
//int main()
//{
//	int n,i;	char c,nstr[MAXLEN];
//	scanf("%d",&n);	getchar();
//	while(n>0){
//		
//		for( i=0;i<MAXLEN-1;i++){
//			c=getchar();
//			if(c=='\n')
//			break;
//			nstr[i]=c;
//		}
//		nstr[i]='\0'; 
//		printf("%d ",atoh(nstr));
//		
//		for(int i=0;i<MAXLEN;i++)
//		nstr[i]=0;
//		
//		n--;
//	}
//	return 0;
//}

#include <stdio.h>
		 
#define MAXLEN 18
int atoh(const char *nstr)
{
	const char *j=nstr;
	char c;	int ret=0;
	for(j=nstr+2;*j!='\0';j++){
		c=*j;	
		if(c>64&&c<71){
			c=c-'A'+10;
		}else if(96<c&&c<103){
			c=c-'a'+10;
		}else{
			c=c-'0';
		}				//别忘了char中的'1''2'等数字也不是原来的！ 
		ret= ret*16+c;
	}
	return ret;
}


int main()
{
	int N,n,i,b[10];	char c,nstr[MAXLEN];
	scanf("%d",&n);	getchar();
    N=n;
	while(n>0){
		
		for( i=0;i<MAXLEN-1;i++){
			c=getchar();
			if(c=='\n')
			break;
			nstr[i]=c;
		}
		nstr[i]='\0'; 
		b[N-n]=atoh(nstr);
		
		for(int i=0;i<MAXLEN;i++)
		nstr[i]=0;
		
		n--;
	}
        for(int k=0;k<N;k++)
            printf("%d ",b[k]);
	return 0;
}





// #include <stdio.h>
// #include <strings.h>
// /*编写函数void strnCpy（char s[]，const char t[]， int n）
// 该函数的功能是：t是已知字符串，如果t的长度不大于n，则将t完整复制到字符数组s中;
// 否则，仅将t中的前n个字符复制到字符数组中，并形成字符串。
// (调用函数中，字符串s对应的数组所占的字节数大于等于字符串t对应的数组所占的字节数。)*/
// void strnCpy(char s[], const char t[], int n)
// {
// 	if(strlen(t)>n){
// 		for(int i=0;i<n;i++){
// 			s[i]=t[i];
//		 }
//	 }else{
//	 	char *p=s;
//		const char*q=t;
//	 	while(*q!='\0'){
//	 		*p++=*q++;
//		}
//		
//	 }
// }
// int main(void)
// {
//	char s[50];	char t[50];
//	int n;
//	scanf("%s",s);	scanf("%s",t);
// 	scanf("%d",&n);
// 	
// 	strnCpy(s,t,n);
// 	
// 	printf("%s",s);
// 	return 0;
// }
 
 
 
