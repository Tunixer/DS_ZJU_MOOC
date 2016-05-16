#include <iostream> 
#include <cstdlib>
#define MAXN 1001
#define MINH -1001
using namespace std;

int H[MAXN],size;
void Create(){
	size = 0;
	H[0] = MINH;
}

void Insert(int X){
	int i;
	for(i = ++size;H[i/2] > X;i /= 2)
	    H[i] = H[i/2];
	H[i] = X;
}

int main(){
	int n,m,i,j,x;
	cin>>n>>m;
	Create();
	for(i = 0;i < n;i++){
		cin>>x;
		Insert(x);
	}
	for(i = 0;i < m;i++){
		cin>>j;
		cout<<H[j];
		while(j>1){
			j /= 2;
			cout<<' '<<H[j];
		}
		cout<<endl;
	}
}
