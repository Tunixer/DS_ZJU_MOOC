#include <iostream>
#include <cstdio>
#define MAX 100000
using namespace std;
int seq[MAX+10];
int MaxSubseqSum(const int *,int N,int&,int&);

int main(){
	int k,ans,head = 0,tail = 0;
	cin>>k;
	for(int i=0;i<=k-1;i++){
		scanf("%d",&seq[i]);
	}
	ans = MaxSubseqSum(seq,k,head,tail);
	cout<<MaxSubseqSum(seq,k,head,tail);
	cout<<' '<<head<<' '<<tail<<endl;
/*
	if(ans == 0) cout<<0<<' '<<seq[0]<<' '<<seq[k-1]<<endl;
	else{
	    cout<<ans;
		cout<<' '<<head<<' '<<tail<<endl;		
	}
*/
	return 0;
} 

int MaxSubseqSum(const int A[],int N,int& head,int& tail){
	int ThisSum,MaxSum,j,temp = 0;
	ThisSum = A[0];
	MaxSum = A[0];
	for(j = 0;j <= N-1;j++){
		ThisSum += A[j];
		if(ThisSum > MaxSum){
		   MaxSum = ThisSum;
		   head = temp;
		   tail = j;			
		}
		else if(ThisSum < 0){
		   ThisSum = 0;
		   temp = j + 1; 
		}
	}
	return MaxSum;
}
