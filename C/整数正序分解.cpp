#include <stdio.h>
int main()
{
	int x,t,ret;int d=1;

    scanf("%d",&x);
    t=x;
    while(t>9)
	{
    	t/=10;d*=10;
	}
   
  	while(d>0)
  	{
  		ret=x/d;
  		x%=d;
  		d/=10;
  		printf("%d",ret);
  		
  		if(d>0)
  			printf(" ");
	  }
    
    //此处不用x作为while 和 if 的判断是因为当输入8000这种带0的数时，只会输出个位数 
	
	//翁恺nb!!! 
	
	return 9;
}
