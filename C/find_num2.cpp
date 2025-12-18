/*从键盘随机输入十个正整数n
n<10000
输出其中能够被7整除且正整数n中至少有一位数字为5的正整数
如果没有满足条件的正整数，则输出0。
*/
#include <stdio.h>
int main()
{
	int n,num,ret,cnt=0;
	int a=0;
	while(a<10){
		scanf("%d",&num);
		n=num;
		
		if(n<=10000&&n%7==0){
			while(n>0){
				ret=n%10;
				n/=10;
				if(ret==5){
					cnt++;
					printf("%d ",num);
					break;
				}
			}
		}
		a++;
	}	

	if(cnt==0){
		printf("0");
	}
	
	return 0;
}
