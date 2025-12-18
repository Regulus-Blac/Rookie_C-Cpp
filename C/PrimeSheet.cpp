// version 1.2	初学版，用根号 
//#include <stdio.h>
//#include <math.h>
//int main()
//{
//int n;scanf("%d",&n);
//int idx=0;
//int prime[n]; 
//for(int i=3;i<n;i++){
//	int code=0;
//	for(int j=2;j<=1+sqrt(i);j++){
//		if(i%j==0){
//			code=1;
//			break;}
//		}
//	if(code==0){
//		prime[idx]=i;
//		++idx;
//	 }
//	}
////2以外的素数库
//for(int k=0;k<idx;k++){
//	printf("%d\n",prime[k]);
//}
//
//return 0;
//}

//version 2.1	埃氏筛 
//#include <stdio.h>
//int main()
//{
//	int cap;
//	printf("请输入您想查询的素数表上界\n"); 
//	scanf("%d",&cap);
//	int Prime[cap];
//	int i,j;
//	
//	for(i=0;i<cap;i++){
//		Prime[i]=1;  //数组初始化全为素数 
//	}
//	for(i=2;i<cap;i++){
//		if(Prime[i] ) { //省略==1，因为1是TRUE 0是FALSE
//		 //注意不可以写=1，因为赋值表达式返回所赋的值，恒成立了 
//		for(j=2;i*j<cap;j++) {
//			Prime[i*j]=0;
//		} 
//	}
//}
//	for(i=2;i<cap;i++){
//		if(Prime[i] ) {
//			printf("%d\t",i);
//		}
//	
//	}
//return 0;
//}

//version 2.2	线性筛
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;	cin>>n;
	vector<bool>notprime(false,n+1);		//	全初始化为素数 
	vector<int>prime; 
	
	for(int i=2;i<=n;i++){
		if(!notprime[i]){
			prime.push_back(i);				//	不是合数就加到质数里 
		} 
		for(vector<int>::iterator it=prime.begin();it!=prime.end();it++){			//	筛掉它的倍数 
			int p=*it;
			if(i*p>n)	break;
			notprime[i*p]=true;
			
			if(i%p==0)	break;				//	i已经被筛过或将要被筛了，这里就不用再筛了 
	
		}	
	}
	for(vector<int>::iterator it=prime.begin();it!=prime.end();it++){
		cout<<*it<<"\n";
	} 
	
	
	return 0;
 } 







