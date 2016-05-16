/*
This program use methodology of union by size as the implimentation of SetUnion() 
*/ 
#include <iostream>
#include <cmath>
#define NumSets 10000
using namespace std;

typedef int DisjSet[NumSets + 100];
typedef int SetType;
typedef int ElementType;

void Initialize(DisjSet S);
void SetUnion(DisjSet S,SetType Root1,SetType Root2);
SetType Find(ElementType X,DisjSet S);

int main(){
	DisjSet DJS;
	int N,x,y;
	char s = '0';
	cin>>N;
	Initialize(DJS);
	while(s != 'S'){
		cin>>s;
		switch(s){
			case 'C':{
				cin>>x>>y;
				cout<<((Find(x,DJS) == Find(y,DJS))?"yes":"no")<<endl; 
				break;
			}
			case 'I':{
				cin>>x>>y;
				SetUnion(DJS,Find(x,DJS),Find(y,DJS));
				break;
			}
			case 'S':{
				int ans=0;
				for(int j = 1;j <= N;j++){
					if(DJS[j] <= 0) ans++;
				}
				if(ans == 1)
				    cout<<"The network is connected."<<endl;
				else
				    cout<<"There are "<<ans<<" components."<<endl;
				break;
			}
		} 
	}
}

SetType Find(ElementType X,DisjSet S){
	if(S[X] <= 0)
	    return X;
	else
	    return  S[X] = Find(S[X],S);
}

void Initialize(DisjSet S){
	for(int i = NumSets;i > 0;i--)
	    S[i] = -1;
}

//Input parameter should be root,so it should use Find() 
void SetUnion(DisjSet S,SetType Root1,SetType Root2){
	int temp;
	if(abs(S[Root1]) >= abs(S[Root2])){
		temp = abs(S[Root2]);
		S[Root2] = Root1;
		S[Root1] += temp;
	}
	else{
		temp = abs(S[Root1]);
		S[Root1] = Root2;
		S[Root2] += temp;
	}
}
