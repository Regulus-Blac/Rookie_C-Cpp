/*完全数是它的所有真因子（即除了自身以外的约数，包括1）之和恰好等于它本身
例如6=1+2+3，28=1+2+4+7+14等。
要求设计一个函数，判定形参n是否为完全数，如果是，返回1，否则返回0。
在main函数中调用该函数求10000以内的所有完全数，并以完全数的真因子之和的形式输出结果
例如“6=1+2+3”,程序输出中，每个完全数单独占一行*/
# include <stdio.h>

int mark[100];	int len=0;
//不用指针，用全局变量就可以使len和数组通用了！ 
int Isperfect(int a );

int main(void)
{
	int n ;
	for (n=2 ;n<10000;n++ ){
	
		if(Isperfect(n )){
			printf("%d=1",n);
			for(int k=1;k<len;k++) {
				
				printf("+%d",mark[k]);
			}
			printf("\n");
		}//也可以在这里（if之外，for之内）归零 
	}
	return 0;
}

int Isperfect(int a )
{
	int ret=0,sum=0; 
	len= 0;//最重要一步！不能在函数最后归零，因为刚出函数就要用；也不能在主函数 if里归零，or只会在发现一个完美数之后
	//每循环一次都会调用Isperfect函数，会导致len激增，所以要归零 
	for(int j=1;j<a;j++){
		if(a%j==0){
		sum+=j;	
		mark[len]=j;
		len++;		//数组长度 
		}
	} //求真因子之和 ，并把真因子存到数组当中去 
	if(sum==a) ret=1;
	
	return ret;//单一出口 
}

