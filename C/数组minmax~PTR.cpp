#include <stdio.h>

void minmax (int a[],int len,int *min,int *max)
{
	int i=1;
	for(i;i<len;i++)
	{
		if(*max<a[i])
		*max=a[i];
		
		if(*min>a[i])
		*min=a[i];	
	}
	
}

int main()
{
	int min,max;
	int a[]={0,1,1,2,3,5,8,13,21,34,55,89,144};
	int len=sizeof(a)/sizeof(a[0]);
	minmax(a,len,&min,&max);
	printf("min=%d,max=%d,len=%d\n",min,max,len);
	
	return 0;
}
