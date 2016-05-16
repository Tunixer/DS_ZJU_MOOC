#include <iostream>
#include <cstdio>
#include <cstdlib>
#define MaxVertexNum 100
#define INFINITY 65535
using namespace std;

typedef int Vertex;
typedef int WeightType;
typedef char DataType;
//definition of edges 
typedef struct ENode *PtrToENode;
struct ENode{
	Vertex V1,V2;
	WeightType Weight;
};
typedef PtrToENode Edge;

//definition of Graph
typedef struct GNode *PtrToGNode;
struct GNode{
	int Nv; //number of vertex
	int Ne;//number of edges
	WeightType G[MaxVertexNum][MaxVertexNum];//adjacent matrix
	DataType Data[MaxVertexNum];//data in vertex
};
typedef PtrToGNode MGraph;//point to Graph

void FindAnimal(MGraph Graph);
MGraph CreateGraph(int VertexNum);
void InsertEdge(MGraph Graph,Edge E);
MGraph BuildGraph();
void Floyd(MGraph Graph,WeightType D[][MaxVertexNum]/*,Vertex Path[][MaxVertexNum]*/);
MGraph BuildGraph();
WeightType FindMaxDist(WeightType D[][MaxVertexNum], Vertex i, int N);

int main(){
	MGraph G = BuildGraph();
	FindAnimal(G);
	return 0; 
}

void FindAnimal(MGraph Graph){
	WeightType D[MaxVertexNum][MaxVertexNum],MaxDist,MinDist;
	Vertex Animal,i;
	
	Floyd(Graph,D);
	
	MinDist = INFINITY;
	for(i = 0;i < Graph->Nv;i++){
		MaxDist = FindMaxDist(D ,i ,Graph->Nv);
		if(MaxDist == INFINITY){
			cout<<"0"<<endl;
			return; 
		}
		if(MinDist > MaxDist){
			MinDist = MaxDist;
			Animal = i+1; 
		}
	} 
	printf("%d %d\n",Animal,MinDist);
}

MGraph CreateGraph(int VertexNum){
	Vertex V,W;
	MGraph Graph;
	
	Graph = (MGraph)malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	for(V = 0;V <= Graph->Nv;V++)
	    for(W = 0;W <= Graph->Nv;W++)
		    Graph->G[V][W] = INFINITY;
	return Graph; 
}

void InsertEdge(MGraph Graph,Edge E){
	Graph->G[E->V1][E->V2] = E->Weight;
	Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph BuildGraph(){
	MGraph Graph;
	Edge E;
	int Nv,i;
	
	cin>>Nv;
	Graph = CreateGraph(Nv);
	
	cin>>Graph->Ne;
	if(Graph->Ne != 0){
		E = (Edge)malloc(sizeof(struct ENode));
		for(i = 0;i < Graph->Ne;i++){
			cin>>E->V1>>E->V2>>E->Weight;
			E->V1--; E->V2--;
			InsertEdge(Graph,E); 
		}
	}
	/*
	for(V = 0;V < Graph->Nv;V++)
	    cin>>Graph->Data[V];
	*/
	return Graph;
}

WeightType FindMaxDist( WeightType D[][MaxVertexNum], Vertex i, int N ){
    WeightType MaxDist;
	Vertex j;
	MaxDist = 0;
	for( j=0; j<N; j++ ) /* 找出i到其他动物j的最长距离*/ 
	    if( i!=j && D[i][j]>MaxDist) MaxDist= D[i][j];
	return MaxDist;
}

void Floyd(MGraph Graph,WeightType D[][MaxVertexNum]/*,Vertex Path[][MaxVertexNum]*/){
	Vertex i,j,k;
	for(i = 0;i < Graph->Nv;i++)
	    for(j = 0;j < Graph->Nv;j++){
	    	D[i][j] = Graph->G[i][j];
	    }
	for(k = 0;k < Graph->Nv;k++)
		for(i = 0;i <Graph->Nv;i++)
		    for(j = 0;j < Graph->Nv;j++)
		        if(D[i][k] + D[k][j] < D[i][j]){
		        	D[i][j] = D[i][k] + D[k][j];
		        	//if(i == j && D[i][j]<0)
		        	    //return false;
		        	//path[i][j] = k;
		        }
	//return true;
}
