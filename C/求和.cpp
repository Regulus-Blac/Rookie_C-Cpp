#include<stdio.h>
int main()
{
	//分母12358分子2358 
	double i=2;double j=1;//分子分母要用double!!!!!!!!!!!因为int范围太小，会超过边界返成负的 
	int n;
	scanf("%d",&n);
	double sum=0.00;
	int x=1;
	
	while(x<=n){
	sum+=i/j;
	int a=i;
	i+=j;//下一项分子 
	j=a;
	x++;
			}
	printf("%.2f\n",sum);
	
	return 3;	
}
