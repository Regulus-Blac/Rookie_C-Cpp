/*空格的数目，每个数字占位4格，例如，1位数后补3个空格,2位数后补2个空格。
第N行行首为N个空格（每向上一行，行首空格数对应增加2个）。
每行末尾换行。*/

#include <stdio.h>
int fac(int a)
{
	int ret=1;
	if(a!=0){
		for (int i=a;i>0;i--)
		{ ret*=i; }
	}
	return ret;
}//定义阶乘 
void space(int a)
{
for(a;a>0;a--){
	printf(" ");
	}
	return;
}//空格个数 

int main()
{
int N,n,i,ret;
scanf("%d",&N);


	for( n=0;n<=N;n++) {//C下方 
	int s=N+(N-n)*2;	space(s);
	
	for( i=0;i<=n;i++){//C上方 
		ret=fac(n)/fac(n-i)/fac(i);
		printf("%-4d",ret);//题目中想让我们往右补空格，这就需要左对齐，而不加“-”默认为右对齐！ 
	}
	if(n<N)
	printf("\n"); 
}

	
	return 0;
}

