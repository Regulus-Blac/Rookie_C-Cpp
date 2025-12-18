/*自幂数是指一个n位数，它每位数字的n次幂之和等于它本身
编写一个函数，判断其参数n是否为自幂数，如果是，返回1;否则，返回0。
要求main函数能反复接收从键盘输入的整数k，k代表位数，然后调用上述函数求所有k位的自幂数
输出相应信息并换行 “3位的水仙花数有：153,370,371,407，共4个”
当k=0时程序结束执行。*/
#include <stdio.h>
#include <math.h>
int judge(int n,int a);

int main()
{

	int code,num,n;	scanf("%d",&num);
	int a;	n=num;
	while(n>0){
		int cnt=0;
		switch(n){
			case 3:
				printf("3位的水仙花数有:");
				break;
			case 4:	
				printf("4位的四叶玫瑰数有:");	
				break;
			case 5:	
				printf("5位的五角星数有:");
				break;	
			case 6:	
				printf("6位的六合数有:");	
				break;	
			case 7:		
				printf("7位的北斗星数有:");
				break;	
			case 8:	
				printf("8位的八仙数有:");
				break;	

		}
		int b=1;
		while(num>1){
			b*=10;
			num--;
		}//构造n位数的起始 
	
		for(a=b;a<b*10;a++){
			
			code=judge(n,a);
			if(code==1){
				printf("%d,",a);
				cnt++;
			}
			code=0;//归零 
		}
		
		if(a==b*10){
			printf("共%d个\n",cnt);
		}
	
		scanf("%d",&num);	
		n=num;
	}		
	return 0;
}

int judge(int n,int a)
{
	int k=a;
	int ret=0,i=0,each;
	double sum=0;
	
	while(k>0){
		each=k%10;
		sum+=pow((double)each,(double)n);
		k/=10;
	}
	if((int)sum==a){
		ret=1;
	}

	return ret;
}

