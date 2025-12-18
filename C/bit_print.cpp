#include "stdio.h"
#include<limits.h>

void bit_print(short x)
{
    int i = 0;
    int n = sizeof(short) * CHAR_BIT; /* CHAR_BIT 在limits.h中定义 */
    int mask = 1 << (n-1);         /* 逻辑尺mask=100……0 */

    for ( i=1; i<=n; ++i ) {
         putchar ( ! ( x & mask ) ? '0': '1');
         x<<=1;
         if ( ! ( i % CHAR_BIT ) && i<n )
             putchar(' ');
    }
}
int main(void)
{
	short h;
	scanf("%hd",&h);
    bit_print(h); 
    return 0;
 
}

