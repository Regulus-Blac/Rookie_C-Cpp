/*递归函数01~字符串倒序（from KIMI）*/
//#include <stdio.h>
//#include <strings.h>
//
//void reversePrint(char *str, int index);/*注意这里虽然输入数组，但是直接用指针！*/
//
//int main() {
//    char str[100]; // 假设输入的字符串不超过99个字符
//    printf("请输入一行字符：\n");
//    fgets(str, 100, stdin); // 读取一行输入，包括空格
//
//    // 计算字符串长度，因为fgets会将换行符也读入
//    int length = strlen(str);
//    if (str[length - 1] == '\n') {
//        str[length - 1] = '\0'; // 替换换行符为字符串结束符
//        length--; // 减去换行符
//    }
//    // 调用递归函数，从字符串的末尾开始
//    reversePrint(str, length - 1);
//    printf("\n"); // 逆序输出后换行
//    return 0;
//}
//// 递归函数定义
//void reversePrint(char *str, int index) {
//    // 递归的基本情况：如果索引小于0，则返回
//    if (index < 0) {
//        return;
//    } else {
//        // 打印当前字符
//        putchar(str[index]);
//        // 递归调用，处理前一个字符
//        reversePrint(str, index - 1);
//    }
//}


/*递归函数02~兔子数列以及改进*/
//#include <stdio.h>
//#include <time.h>
//
//clock_t start,stop;
//
//long F(int n) {
//    if(n==1||n==2)
//        return 1;
////从此改进 
//    else if(n==3)
//    	return 2;
//    else if(n==4)
//   		return 3;
//    else if(n==5)
//    	return 5;
//    else if(n==6)
//    	return 8;
//    else if(n==7)
//    	return 13;
//    else if(n==8)
//    	return 21;//到此结束 
//    else
//        return F(n-1)+F(n-2);	 
//}
//
//int main()
//{
//    int n;	double gap;
//    scanf("%d",&n);
//    start=clock();
//    printf("%ld\n",F(n) );    
//    stop=clock();
//    gap= ((double)(stop-start))/CLK_TCK;
//    //CLK_TCK就是当前所用的机器时钟每秒所走的时钟打点数,也可以用CLOCKS_PER_SEC 
//    
////只有12	30-0.004	35-0.035	40-0.532	45-5.889	50-65.797 
////加了3 	30-0.004	35-0.035	40-0.395	45-4.604	50-\ 
////加到34	30-0.005	35-0.019	40-0.239	45-2.883	50-31.611
////加到8 	30-0.000	35-0.004	40-0.051	45-0.629	50-6.886
//    printf("计算所需时间为%f",gap);
//    return 0;
//}

/*递归函数03~兔子数列换方法简化*/
#include <stdio.h>
#include <time.h>
#include <math.h>
clock_t start,stop;
# define A (sqrt(5)+1)/2
# define B (1-sqrt(5))/2

long F(int n) {
    if(n==1||n==2)
        return 1;
    else
        return A*F(n-1)+(2-A)*pow(B,n-3); 
}

int main()
{
    int n;	double gap;
    scanf("%d",&n);
    start=clock();
    printf("%ld\n",F(n) );    
    stop=clock();
    gap= ((double)(stop-start))/CLK_TCK;
 
//	30-0.000	35-0.000	40-0.000	45-0.000	50-0.000 

    printf("计算所需时间为%f",gap);
    return 0;
}



