/*输入自然数N输出N以内所有这样的完全平方数：
N=a2=b2*10+c2;N<10000
*/
#include <stdio.h>
#include <math.h>
int main()
{
	int n;int a,b,c;
	scanf("%d",&n);
	
	for(a=4;a<sqrt(n);a++){
		
		for(b=1;b<=(sqrt(n/10))/2;b++){
		
			for(c=a;c>-1;c-=2){
				if(a*a-c*c==40*b*b){
					printf("%d ",a*a);
				}
			}
		}
	}
	
	return 0;
	
}


