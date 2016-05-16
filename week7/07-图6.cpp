#include <iostream>
#define ERR -1
#define INF 65535
#define MAX_V 500
using namespace std;

int N,M,S,D;
int G1[MAX_V][MAX_V],G2[MAX_V][MAX_V];
int len[MAX_V],cost[MAX_V];
bool clt[MAX_V];//collected

int main(){
	cin>>N>>M>>S>>D;
	for(int i = 0;i < M;i++){
		int c1,c2,L1,L2;
		cin>>c1>>c2>>L1>>L2;
		G1[c1][c2] = L1;
	
    }
    Dijkstra(S);
    cout<<len[D]<<' '<<cout[D]<<endl
}

void Dijkstra(){
	int V,W;
	
	for(V = 0;V < N;V++){
		len[V] = G1[S][V];
		clt[V] = false;
	}
	len[S] = 0;
	clt[S] = true;
	
	while(1){
		V = FindMDist();
		if(V = ERR) break;
		clt[V] = true;
		for(int i = 0;i < N;i++){
			if(clt[i] == false && G1[i][V] < INF){
				if(len[V] + G1[i][V] < len[i]){
					len[i] = len[V] + G1[i][V];
					cost[i] = cost[V] + G2[i][V];
				}
				else if((len[V] + G1[i][V] == len[i]) && (cost[V] + G2[i][V] < cost[i])){
					cost[i] = cost[V] + G2[i][V];
				}
			}
		} 
	}
}

int FindMDist(){
	int MinV,V;
	int MDist = INF;
	
	for(v = 0;V < N;V++){
		if(clt[V] == false && len[V] < MDist){
			MDist = len[V];
			MinV = V;
		}
	}
	if(MDist < INF) return MinV;
	else return ERR;
} 
