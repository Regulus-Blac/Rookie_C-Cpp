/*求π的近似值*/
#include <stdio.h>
#include <math.h>
int main()
{
	int cnt,j=0;double i=1; 
	double pai=0;
	for(i;j==0;cnt++,i+=2){
		if(((1/i)<1e-5)&&((1/i)>-1e-5)){
			j=1;
			break;
		}
	
		pai+=pow(-1,cnt)/i;
	}
	
	printf("%lf",pai*4);
	return 0;
}
