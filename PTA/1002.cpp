//要小心两个浮点数加出一个0来 
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main(){
	float A[1005],B[1005];
	int H[1005];
	for(int i = 0;i < 1005;i++){
		A[i] = B[i] = 0.0;
		H[i] = 0;
	}
	int N1,N2;
	cin>>N1;
	for(int i = 1;i<=N1;i++){
		int exp;
		float cof;
		cin>>exp>>cof;
		A[exp] = cof;
		H[exp] = 1;
	}
	cin>>N2;
	for(int i = 1;i<=N2;i++){
		int exp;
		float cof;
		cin>>exp>>cof;
		B[exp] = cof;
		H[exp] = 1;
	}
	int count = 0;
	for(int i = 0;i < 1005;i++){
		if(H[i] == 1){
			A[i] += B[i];
			if (abs(A[i])>1e-2) count++;
		}
	}
	int i,j;
	cout<<count;
	for(i =1004,j=0;i >=0 && j!=count;i--){
		if(H[i] == 1 && abs(A[i])>1e-2) {
			printf(" %d %.1f",i,A[i]);
			j++;
		}
	}
	return 0;
}
