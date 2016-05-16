#include <iostream>
#include <cmath>
#define MaxVertexNum 100
#define YES 1
#define NO -1
using namespace std;

typedef struct ENode* PtrToNode;
typedef struct ENode* Graph;
typedef int Vertex;
struct ENode{
	int x,y;
};

int N,D;
bool visited[MaxVertexNum + 10];
int answer = NO;
struct ENode G[MaxVertexNum + 10];

void SaveJames();
bool IsSafe(Vertex V);
int DFS(Vertex V);
bool Jump(Vertex V,Vertex W);
bool FirstJump(Vertex V);

int main(){
	cin>>N>>D;
	for(int i = 0;i < N;i++){
		cin>>G[i].x>>G[i].y;
	}
	SaveJames(); 
	return 0;
} 

void SaveJames(){
	for(int V = 0;V < N;V++){
		if(!visited[V] && FirstJump(V)){
			answer = DFS(V);
			if(answer = YES) break;
		}
	}
	if(answer == YES)
	    cout<<"Yes"<<endl;
	else
	    cout<<"No"<<endl;
}

bool IsSafe(Vertex V){
	int dist = min(50 - abs(G[V].x),50 - abs(G[V].y));
	return (dist <= D)? true : false; 
} 

int DFS(Vertex V){
	visited[V] = true;
	if(IsSafe(V))
	    answer = YES;
	else{
		for(int W = 0;W < N;W++)
		    if(!visited[W] && Jump(V,W)){
		    	answer = DFS(W);
		    	if (answer == YES)
		    	    break;
		    }
	}
	return answer;
}

bool Jump(Vertex V,Vertex W){
	int temp = (G[V].x - G[W].x) * (G[V].x - G[W].x)
	          + (G[V].y - G[W].y) * (G[V].y - G[W].y);
	return (temp < D*D)? true : false;
}

bool FirstJump(Vertex V){
	int temp = G[V].x*G[V].x + G[V].y*G[V].y;
	return (temp < D*D) ? true : false;
}
