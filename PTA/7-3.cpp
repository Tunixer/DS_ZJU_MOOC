/*
https://pintia.cn/problem-sets/15/problems/711
7-3 Ê÷µÄÍ¬¹¹
Author of This Answer£ºtunixer@gmail.com Nankai University 
*/ 
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
using namespace std;

struct TNode{
	char value;
	int left,right;
};

class IptData:public std::string{
	public:
		TNode getinfo();
}; 
int dealStr(string match,int x){
	stringstream tmp;
	tmp.str(match);
	int tint;
	char tchar;
	if (x==0){
		tmp.str(match);
		if (tmp>>tchar){
			return tchar;
		}
	}
	tmp.str(match);
	if (!match.compare("-")){
		return -1;
	}
	tmp.str(match);
	if (tmp>>tint){
		return tint;
	}

}
TNode IptData::getinfo(){
	string tmp,ptn,match;//temp,pattern and match
	int idx1,idx2;
	idx1 = 0;
	idx2 = 0;
	tmp = *this;
	ptn = " ";
	TNode ans;

	idx2 = tmp.find(ptn,idx1);
	match = tmp.substr(idx1,idx2-idx1);
	ans.value = dealStr(match,0);
	
	idx1 = idx2+1;
	idx2 = tmp.find(ptn,idx1);
	match = tmp.substr(idx1,idx2-idx1);
	ans.left = dealStr(match,1);
	
	idx1 = idx2+1;
	match = tmp.substr(idx1,tmp.length()-idx1);
	ans.right = dealStr(match,1);
	return ans;
}

class Tree{
private:
	TNode *data;
	int size,root;
public:
	Tree(){
		this->data = NULL;
		root = -1;
	}
	Tree(int _size){
		this->size = _size;
		this->data = (TNode*)malloc(sizeof(TNode)*_size);
	}
	~Tree(){
		TNode *p = this->data;
		free(p);
	}
	friend bool TG(Tree &T1,int idx1,Tree &T2,int idx2);
	void Input();
	int getRoot();
};
void Tree::Input(){
	int _size = this->size;
	TNode *arr = this->data; 
	for(int i = 0;i < _size;i++){
		IptData mystr;
		getline(cin,mystr);
		cin.clear(); 
		TNode haha;
		haha = mystr.getinfo();
		arr[i] = haha;
	}
	int idx = 0;
	for(int i = 0;i < _size;i++){
		if (arr[i].value<=arr[idx].value)
			idx = i;
	}
	this->root = idx;
}

bool TG(Tree &T1,int idx1,Tree &T2,int idx2){
	bool temp;
	TNode *arr1,*arr2;
	arr1 = T1.data;
	arr2 = T2.data;
	if((idx1 == -1) && (idx2 == -1))
		return true;
	if((idx1 == -1) || (idx2 == -1))
		return false;
	temp = (arr1[idx1].value == arr2[idx2].value);
	if(!temp)
		return false;
	bool ans1 = TG(T1,arr1[idx1].left,T2,arr2[idx2].left)&&TG(T1,arr1[idx1].right,T2,arr2[idx2].right);
	bool ans2 = TG(T1,arr1[idx1].right,T2,arr2[idx2].left)&&TG(T1,arr1[idx1].left,T2,arr2[idx2].right);
	return ans1||ans2;
}

int Tree::getRoot(){
	return this->root;
}
int main(){
	int N1,N2;
	string temp; 
	cin>>N1;
	Tree T1(N1);
	getline(cin,temp);
	if(N1!=0){
		T1.Input();			
	}

	cin>>N2;
	Tree T2(N2);
	getline(cin,temp);
	if(N2!=0){
		T2.Input();			
	}

	bool ans = 0;
	if(N1==0&&N2==0){
		cout<<"Yes"<<endl;
		return 0;
	}
	ans = TG(T1,T1.getRoot(),T2,T2.getRoot());
	if(ans ==1)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}
