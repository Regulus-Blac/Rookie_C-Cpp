#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
	srand(time(0));
	int a=rand()%100+1;int n=0;int b;
	//按正确方法最多7次就可以猜出来【二分法】，2^7>100 
	printf("我们来玩猜数游戏吧，我想一个1~100的数让你来猜\n我只会回答你“大了”或者“小了”，最后我会告诉你一共猜了多少次哦\n现在请开始猜吧！\n");
	scanf("%d",&b);
	n++;

	while(b!=a)
	{n++;
		if(b>a){
		printf("大了\n"); 
	}else if(b<a){
		printf("小了\n");	} 
		scanf("%d",&b);
	 } 
printf("恭喜你猜对了，一共尝试了%d次，再接再厉吼:)",n);
	
	return 0;
}
