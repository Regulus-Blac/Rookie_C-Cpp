#include <stdio.h>

int MySLen(char a[])
{
	int x=sizeof(a);
	return (x-1);
}
int main()
{
	
	char line[100];
	scanf("%s",line);
	printf("%d",MySLen(line));
	return 0;
}
