/*Selection Sort*/
#include <stdio.h>
#define MAX 100
int main()
{
	int a[MAX],*p,temp;
	int *Max=a;
	int n;	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	for(int j=0;j<n-1;j++){
		Max=a;p=a;
		for(int i=0;i<n-j;i++,p++) {
			if(*p>=*Max)
				Max=p;
		}
		p--;
		temp=*p;
		*p=*Max;
		*Max=temp;		
	}
	
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
