/* 输入无符号短整数k
输出将k的高4位和低四位交换后的结果。 */
#include <stdio.h>
int main()
{
	unsigned short k,ret;
	scanf("%hd",&k);

	ret=(k&0xF000)>>12|k&0xFF0|(k&0xF)<<12;
	
	printf("%d",ret);
	
	return 0;
}
