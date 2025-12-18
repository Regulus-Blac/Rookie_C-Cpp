/*将数组中指定的两段数据交换
输入n个整数到数组a中，再输入正整数m1、n1、m2、n2   0≤m1≤n1<m2≤n2<n
将数组中由m1、n1指定的一段数据和由m2、n2指定的一段数据交换位置，其它数据位置不变
输出重新排列后的数组元素。
要求：1. 将交换数组中两段数据的功能定义为函数
2. 所有的操作都在数组a上完成，不允许使用其它数组
3.输出在main函数中完成，不能在自定义函数中完成。*/
#include <stdio.h>
#define MAX 100
int main()
{
    int n,t;scanf("%d",&n);
	int m1,n1,m2,n2;
	int a[MAX];
	for(int w=0;w<n;w++){
		scanf("%d",&t);
		a[w]=t;
	}
	scanf("%d%d%d%d",&m1,&n1,&m2,&n2);
	int cnt1=n2-m2+1;			//后一段的个数 
	int cnt2=m2-n1-1;			//中间的个数（易错为加一，看清楚！！） 
	int temp;
	
	for (int i=0;i<cnt1;i++) {
		temp=a[n2];				//保存最后一个 
		for(int j=n2;j>m1;j--)
			a[j]=a[j-1];				 
		a[m1]=temp;				//与第一个调换 

	}							//整体往后面移cnt2次 
	
	for(int i=0;i<cnt2;i++){
		temp=a[n2];
		for(int j= n2;j>m1+cnt1;j--)
			a[j]=a[j-1];
		a[m1+cnt1]=temp;
	}
	
    for(int k=0;k<n;k++){
		printf("%d ",a[k]);
	}
	return 0;
}
 
 
 //题变为只分为两段
//int main()
//{
//	int k,n,a;	int num[50];
//	scanf("%d%d",&n,&k);
//	for(int w=0;w<n;w++){
//		scanf("%d",&a);
//		num[w]=a;
//	} 
//
//	for(int j=0,temp;j<n-k;j++){
//		temp=num[k+j];
//		
//		for(int i=0;i<k;i++){
//			num[k-i+j]=num[k-1+j-i];
//		}				//中间平移 
//		num[j]=temp;	//最左侧与中间交换 
//	}
//	for(int b=0;b<n;b++)
//	printf("%d ",num[b]);
//	
//	return 0;
//}













//	（draft）统计字符数 
//{
//	int chararr[3]={0};	char c;
//	while((c=getchar())!=EOF&&c!='\n'){
//		if(c>=48&&c<=57){
//			chararr[0]++;
//		}else if(c>=65&&c<=90||c>=97&&c<=122){
//			chararr[1]++;
//		}else{
//			chararr[2]++;
//		}
//	}
// 
// 	for(int i=0;i<3;i++)
//	printf("%d ",chararr[i]);
//	
//	return 0;
//}
	
