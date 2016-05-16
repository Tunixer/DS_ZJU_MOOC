#include <cstdio>
#include <iostream>
#include <queue>
#define N 15 

using namespace std;

void ListComponentsWithDFS();
void ListComponentsWithBFS();
void DFS(int V);
void BFS(int V);
void InitVisit(void);

int n;
bool Visited[N];
int G[N][N] = {0};

int main(){
	int E;
	cin>>n>>E;
	int a,b;
	for(int i = 0;i < E;i++){
		cin>>a>>b;
		G[b][a] = G[a][b] = 1;
	}
	ListComponentsWithDFS();
	InitVisit();
	ListComponentsWithBFS();
	
	return 0; 
}

void ListComponentsWithDFS(){
	for(int V = 0;V < n;V++){
		if(!Visited[V]){
			cout<<"{ ";
			DFS(V);
			cout<<"}"<<endl; 
		}
	}
}

void ListComponentsWithBFS(){
	for(int V = 0;V < n;V++){
		if(!Visited[V]){
			cout<<"{ ";
			BFS(V);
			cout<<"}"<<endl; 			
		}
	}
}

void DFS(int V){
	Visited[V] = true;
	cout<<V<<' ';
	for(int i = 0;i < n;i++){
		if(G[V][i] && !Visited[i])
		    DFS(i); 
	}
}

void BFS(int V){
	queue<int> q;
	q.push(V);
	Visited[V] = true;
	while(!q.empty()){
		int F = q.front();
		q.pop();
		cout<<F<<' ';
		for(int i = 0;i < n;i++){
			if(G[F][i] && !Visited[i]){
				q.push(i);
				Visited[i] = true;
			}
		}
	}
}

void InitVisit(){
	for(int i = 0;i < N;i++)
	    Visited[i] = false; 
}
