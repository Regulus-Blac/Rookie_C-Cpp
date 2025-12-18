#include <stdio.h>
void swap(char *a, char *b) {
    char *t = a;
    a = b;
    b = t;
}
int main()
{
	char str1[] = "hello";
char str2[] = "world";
char *p1 = str1;
char *p2 = str2;

swap(p1, p2);

    printf("%s %s",p1,p2);
	

	return 0; 
}
