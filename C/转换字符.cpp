/*从终端输入一个字符，如果该字符是十六进制数字，
则输出它对应的整数，否则输出它的字符码（原字符）*/
#include <stdio.h>

int main()
{
	char c;
	scanf("%c",&c);
	if(c>64&&c<71){
		 c-=55;printf("%d",c);
	} else if(c>96&&c<103){
		c-=87;
	printf("%d",c);
	} else{  printf("%c",c);
	}


	return 0;
}
