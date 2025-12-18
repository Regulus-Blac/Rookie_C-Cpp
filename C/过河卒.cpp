#include <stdio.h>

int main(){

	int r,c,sqr=0,rec=0,temp;
	printf("请输入行数与列数（1-100）：\n");
	scanf("%d %d",&r,&c);
	
//	int max=(r>c?r:c);
//	int min=(r>c?c:r);
//	sqr=max-min+1;	temp=(sqr+1)*2;
//	for(int i=min;i>1;i--){
//		sqr+=temp;
//		temp=temp*2+2;
//	}
	if(r<=c){
		
	}


	printf("共%d个正方形，%d个长方形",sqr,rec);
	
	return 0;
	
}

