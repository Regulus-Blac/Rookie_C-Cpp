/*任何一个大于等于4的偶数都是两个素数之和。要求设计一个函数，接受形参n，
以“n=n1+n2”的形式输出结果，若有多种分解情况，取n1最小的一个输出
main函数循环接收从键盘输入的整数n，如果n是大于或等于4的偶数，调用上述函数进行验证，直至输入Ctrl+Z程序结束。
*/
#include <stdio.h>

void guess(int n)
{
int sit,cnt=0;
int n1,n2;
int prime[10000];

while(n>=4&&n%2==0){

	for (int i=2;i<n;i++){
		
		for(int j=2;j<i;j++){
			if(i%j==0){
			sit=1;	break;
			}//筛选素数 
		}
		if(sit==0){
			prime[cnt++]=i;
		}	
		sit=0;//归零！！不然一旦成为1就一直是1了，cnt也会随之增加 FOCUS!!!		
	}	//收集n以内素数表 
	for(int i=0;i<cnt;i++){
		for(int j=i;j<cnt;j++){
			if(prime[i]+prime[j]==n){
				n1=prime[i] ;n2=prime[j];
				goto END;
			}
		}
	}

END:
	printf("%d=%d+%d\n",n,n1,n2);
	break; 
}
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		guess(n);
	
	}

	return 0;
}

