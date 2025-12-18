#include <iostream>
#include <ctime>
#define MAX 10016
using namespace std;
int memory[MAX]={0};

long rabbit(int n)
{
	if(n==1||n==2)	return 1;
	if(memory[n])	return memory[n];
	// 已出现过，直接使用 
	return memory[n]=rabbit(n-1)+rabbit(n-2);
	// 将第n项标记上，若之后再次出现就不会反复递归了 
}

int main()
{
	int num;
	cin>>num;
	
	clock_t start=clock();
	
	cout<<"第"<<num<<"项为"<<rabbit(num)<<endl;
	
	
	clock_t end=clock();
	double duration=1.0*(end-start)/CLOCKS_PER_SEC;
	cout<<"代码所用时间为"<<duration<<"s.";
	return 0;
}
