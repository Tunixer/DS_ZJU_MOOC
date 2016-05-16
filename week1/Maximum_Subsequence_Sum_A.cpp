#include <iostream>
#include <cstdio>
#define MAX 100000
using namespace std;
int seq[MAX+10];
int MaxSubseqSum(const int *,int N);

int main(){
	int k;
	cin>>k;
	for(int i=0;i<=k-1;i++){
		scanf("%d",&seq[i]);
	}
	cout<<MaxSubseqSum(seq,k)<<endl;
	return 0;
} 

int MaxSubseqSum(const int A[],int N){
	int ThisSum,MaxSum,j;
	ThisSum = MaxSum = 0;
	for(j = 0;j <= N-1;j++){
		ThisSum += A[j];
		if(ThisSum > MaxSum)
		   MaxSum = ThisSum;
		else if(ThisSum < 0)
		   ThisSum = 0;
	}
	return MaxSum;
}
