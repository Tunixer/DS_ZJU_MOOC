#include <iostream>
using namespace std;

int max(int a,int b,int c){
	int temp = -1000;
	if(a > temp) temp = a;
	if(b > temp) temp = b;
	if(c > temp) temp = c;
	return temp;
}

class Seq{
	private:
		int *data;
		int size;
	public:
		Seq();
		Seq(int n);
		int MaxSubSeq();
		int MaxSubSum(int,int);
		void Input();
};

Seq::Seq(int n){
	this->data = new int[n];
	this->size = n;
}

Seq::Seq(){
	this->size = 0;
}

void Seq::Input(){
	int _size = this->size;
	int *p = this->data;
	int temp;
	for(int i = 0;i < _size; i++){
		cin>>temp;
		p[i] = temp;
	}
}
int Seq::MaxSubSum(int Left,int Right){
	int *p = this->data;
	if(Left>Right) return 0; 
	if(Left == Right)
		return (p[Left]>0?p[Left]:0);
	
	int Med = (Left + Right)/2;
	int maxL = 0,temp = 0;
	for(int i=Med;i >= Left;i--){
		temp += p[i];
		maxL = (temp>maxL? temp:maxL);
	}
	temp = 0;
	int maxR = 0; 
	for(int i=Med+1;i <= Right;i++){
		temp += p[i];
		maxR = (temp>maxR? temp:maxR);
	}
	int tmax = maxL+maxR;
	return max(tmax,Seq::MaxSubSum(Left,Med),Seq::MaxSubSum(Med+1,Right));
} 

int Seq::MaxSubSeq(){
	return this->MaxSubSum(0,this->size-1);
}

int main(){
	int ans;
	int N;
	cin>>N;
	Seq ISeq(N);
	ISeq.Input();
	ans = ISeq.MaxSubSeq();
	cout<<ans<<endl;
	return 0; 
}
