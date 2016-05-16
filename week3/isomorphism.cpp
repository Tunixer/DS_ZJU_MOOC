//this program is to determine whether two trees are iosmorphic
#include <iostream>
#include <cstdlib>
#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1
using namespace std;

struct TreeNode{
	ElementType Element;
	Tree Left;
	Tree Right;
}T1[MaxTree],T2[MaxTree];

Tree BuildTree(struct TreeNode T[]);
int isomorphic(Tree R1,Tree R2);

int main(){
	Tree R1,R2;
	
	R1 = BuildTree(T1);
	R2 = BuildTree(T2);
	isomorphic(R1,R2)?cout<<"Yes"<<endl:cout<<"No"<<endl; 
}

Tree BuildTree(struct TreeNode T[]){
	int N,i,Root,check[MaxTree];
	char cl,cr;
	cin>>N;
	if(N){
		for(i = 0;i<N;i++) check[i] = 0;
		for(i = 0;i<N;i++){
			cin>>T[i].Element>>cl>>cr;
			if(cl != '-'){
				T[i].Left = cl-'0';
				check[T[i].Left] = 1;
			}
			else T[i].Left = Null;
			if(cr != '-'){
				T[i].Right = cr-'0';
				check[T[i].Right] = 1;
			}
			else T[i].Right = Null;
		}
		for(i = 0;i<N;i++)
		    if(!check[i]) break;
		Root = i;
	}
	return Root;
}

int isomorphic(Tree R1,Tree R2){
	if((R1 == Null)&&(R2 == Null))
	    return 1;
	if(((R1 == Null)&&(R2 != Null))||(R1 != Null)&&(R2 == Null))
	    return 0;
	if(T1[R1].Element != T2[R2].Element)
	    return 0;
	if((T1[R1].Left == Null)&&(T2[R2].Left == Null))
	    return isomorphic(T1[R1].Right,T2[R2].Right);
	if((T1[R1].Left != Null)&&(T2[R2].Left != Null)&&
	        (T1[T1[R1].Left].Element == T2[T2[R2].Left].Element))
	    return (isomorphic( T1[R1].Left, T2[R2].Left ) &&
		       isomorphic( T1[R1].Right, T2[R2].Right ));
	else
	return (isomorphic( T1[R1].Left, T2[R2].Right) && 
	isomorphic( T1[R1].Right, T2[R2].Left )); 
} 
