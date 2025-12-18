/*约瑟夫问题*/
#include<stdio.h>
int main()
{
	int i=0,total,num,ret=1;	
	printf("请输入总人数和所报的数：\n");
	scanf("%d%d",&total,&num);	
	int a[total]={0};
	
	while(ret<total)
	for(int j=0;j<num;j++){	//每次循环num遍 
	
		if(i>=total){
			i%=total;	}
				
		if(a[i]==0){

			if(j==num-1){
				ret++;
				a[i]=1;
				printf("第%d个人在第%d次出局\n",i+1,ret-1);	//出局 
			}
			
		}else{	j--;	}	//若已出局就跳过 
	
		i++; 		
	}
	
	for(int w=0;w<total;w++){
		if(a[w]==0){
			printf("最后留下的是第%d位\n",w+1);
		}
	}
	
	
	return 0;
}
