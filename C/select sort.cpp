#include<stdio.h>

int main()
{
	int a,n;
	scanf("%d",&n);
	int num[50];
	for(int l=0;l<n;l++){
		scanf("%d",&a);
		num[l]=a;
	}
	int *p=num;	int t;
	
	for(int j=0;j<n-1;j++){
		int *min=p+j;
		
		for(int i=j;i<n;i++){
			if(*min>p[i]) {
				min=&p[i];}
		}
		
		t=num[j];
		num[j]=*min;
		*min=t;
	}
	
	for(int k=0;k<n;k++)
	printf("%d ",num[k]);
	
	
	return 0;
}
