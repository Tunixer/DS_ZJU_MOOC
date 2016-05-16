//05-Ê÷9 Huffman Code
#include <iostream>
#include <cstring> 
#include <cstdlib>
#define MAXSIZE 100;
using namespace std;

typedef struct TreeNode *HuffmanTree;
struct TreeNode{
	int Weight;
	HuffmanTree Left,Right;
};
template<typename X>
HuffmanTree Huffman(priority_queue<X> H){
	int i; HuffmanTree T;
	for(i = 1;i < H.size()-1;i++){
		T = malloc(sizeof(struct TreeNode));
		T->Left = H.top();
		H.pop();
		T->Right = H.top();
		H.pop();
		T->Weight = T->Left->Weight + T->Right->Weight;
		H.push(T);
	}
	T = H.top();
	return T;
}

int WPL(HuffmanTree T,int Depth){
    if(!T->Left && !T->Right)
	    return (Depth*T->Weight);
	else
	    return(WPL(T->Left,Depth+1)) + WPL(T->Right,Depth+1));
}



int getWPL(int*);
int EvaWPL(string *);
bool IsPreCode(string *); 

int getWPL(){
	HuffmanTree T = Huffman(w);
	return WPL(T,0); 
}

int M,N;
int frq[150];// frequency of character
priority_queue<int> w;
string  data[150];
int hash[150]
int main(){
	char s;
	int f;
	string temp;
	
	cin>>N;
	for(int i = 0;i < N;i++){
		cin>>s>>f;
		frq[s] = f;
		hash[i] = s;
		w.push(f);
	}
	
	
	int MinWpl = getWPL(feq[150]);
	
	cin>>M;
	for(int i = 0;i < M;i++){
		int tempWPL = 0;
		for(int j = 0;i < M;i++{
		    cin>>s>>temp;
		    tempWPL += temp.size()*frq[s];
		    data[j] = temp;
		}
		if(tempWPL == MinWpl) && IsPreCode(data)){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}
	return 0;
} 

bool IsPreCode(string * d){
	sort(d,d+M,cmp);
	int i,j;
	for(i = 1;i < M;i++){
		for(j = 0;j < i;j++){
			if(d[i].find(d[j]) == 0) return true
		}
	}
	return false;
}

bool cmp(string i,string j){
	return (i.size() < j.size());
}
