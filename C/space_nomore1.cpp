/*输入一段以!结尾的短文(最多5行,每行不超过50个字符)
要求将它复制到输出
复制过程中将每行连续一个以上的空格字符用一个空格代替。
*/

# include <stdio.h>
int main()
{
	char c,d ; 
ORI:
	while(c=getchar()){
	if(c=='!'){
		putchar(c);
		goto END;
	}
		if (c==' '){
			putchar(c);
			goto LEAP;
		}
		putchar(c);
	}
	LEAP:
		while(d=getchar()){
			if(d=='!'){
			putchar(d);
			goto END;  		}
			if(d==' '){
				goto LEAP;	}	
			else{
				putchar(d);	
				goto ORI;}
		}
	END:
	return 0;
}//注意何时用“==”何时用“=”！！！ 
