/* 输入十六进制的无符号短整数x，m，n（0 ≤m≤ 15， 1 ≤ n≤ 16-m），取出二进制下x从第m位开始向左的n位
（m从右至左编号为0~15），并使其向左端（第15位）靠齐。要求：
（1）检查m和n的范围;（2）x的值以十六进制输入，m和n以十进制输入;（3）结果以十六进制输出。*/
#include <stdio.h>
#include <math.h>
int main()
{
	const short int NUM=16;
	unsigned short int x,m,n;
	scanf("%hx %hd %hd",&x,&m,&n);	//scanf很严格，一定要按格式写。一开始用的 %x %d,检查了半个多小时... //最扯的is他还不报错...... 
	int jinzhi[NUM];int each,sum=0;//别忘了初始化sum 
	
	for(int i=0;i<NUM;i++){
		jinzhi[i]=x%2;
		x/=2;	
	}//用数组转化为二进制了
if(m>=0&&m<=15&&n>=1&&n<=16-m){	
	for(int j=0;j<n;j++){
		each=jinzhi[n+m-1-j]*pow(2.0,15-j);
		sum+=each;
	}
	
	printf("%x",sum);
	
}else{ printf("error");
}
	

	return 0;
}
