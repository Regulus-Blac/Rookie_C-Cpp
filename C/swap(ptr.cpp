#include <stdio.h>

void swap(int *a,int*b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
	
int main()
{
	int a,b;
	printf("交换前两个数分别为：\n");
	scanf("%d %d",&a,&b);
	swap(&a,&b);
	printf("交换后的两个数分别为%d %d\n",a,b);
	return 0;
}


