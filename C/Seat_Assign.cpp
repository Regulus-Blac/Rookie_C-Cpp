/*实现一个铁路购票系统的简单分配算法，用来处理一节车厢的座位分配
假设一节车厢有20排，每一排有5个座位，用A、B、C、D、F表示，第一排是1A、1B、1C、1D、1F，第二排是2A、2B、2C、2D、2F，以此类推，第20排是20A、20B、20C、20D、20F
购票时，每次最多购买5张，座位的分配策略是：
如果这几张票能安排在同一排相邻座位，则应该安排在编号最小的相邻座位；否则，应该安排在编号最小的几个空座位中（不考虑是否相邻*/
//	4				/*购票次数 
//	2 5 4 2			/*每次购票张数

//	1A 1B			/*第1次购票分配的位置*/
//	2A 2B 2C 2D 2F	/*第2次购票分配的位置*/
//	3A 3B 3C 3D		/*第3次购票分配的位置*/
//	1C 1D			/*第4次购票分配的位置*/

#include <stdio.h>

const int COL=5,ROW=20;
char seat[ROW][COL]={0};
	
int ISall(int r,int need)
{
	int flag,cnt=0;
	for(int i=0;i<COL;i++) {
		if(seat[r][i]==0){
			cnt++;
		}
	}
	if(cnt>=need){
		flag=1;
	}else{
		flag=0;
	}
	return flag;
}
//检查r排是否need个空座 
int main()
{
	int n,need;	int code;
	scanf("%d",&n);
	
	for(int j=n;j>0;j--){

		scanf("%d",&need);	//一共查询几次 
		
		for(int row=0;row<ROW;row++){
			code=0;
			int sit=ISall(row,need);
			
			if(sit){
				int cnt=0;	//查询每一行是否有所需连续空位 
				for(int i=0;i<COL;i++) {
					
					if(seat[row][i]==0){
						seat[row][i]=1;
						cnt++;						
							if(i==4) {printf("%dF",row+1) ;}
							else{ printf("%d%c",row+1,(char)(65+i));	}

						if(cnt==need){code=1;
							break;}else{
								printf(" ");
							}
					}
				}
				break;	
			}				//若没有就继续往后看 
		}
		
		if(code==0){
			int	cnt=0;		//直至20行全部没有连续的了，就开始零星地坐 
			for(int r=0;r<ROW;r++) {
				
				for(int i=0;i<COL;i++) {
					if(seat[r][i]==0){
						seat[r][i]=1;
						cnt++;
							if(i==4){ printf("%dF",r+1) ;}
							else {printf("%d%c",r+1,(char)(65+i));}
						if(cnt==need){break;
						}else{
								printf(" ");
							}	
					}
				}
				if(cnt==need){
					break;	
				}		
			}
		} 
//最后一行不可输出回车（题目规定） 
		if(j!=1)printf("\n");
	}
	return 0;
}

