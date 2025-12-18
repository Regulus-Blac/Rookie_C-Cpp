#include <stdio.h>
int main()
{
	char p; 
	while((p=getchar())!=EOF ){
        if (p>64&&p<91){
            p=p+32;
        }
	   putchar(p);
    }   
	
	return 0;
}
