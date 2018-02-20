
#include <iostream>
#include <vector>
#include <set>
using namespace std;

void PrintArray(vector<int> &T) {
	for (int i = 0; i < T.size(); i++) {
		cout << T[i] << ' ';
	}
	cout << endl;
}
class Graph {
private:
	int N;
	int **GM;
	int count,MinDist,maxres,accres,accDist;
	vector<int> NumEm,res,dist,path;
	vector<bool> IsVisit,IsShort,IsRes;
public:
	Graph(int n = 0){
		if (n > 0) {
			maxres = 0;
			count = 0;
			accres = 0;
			N = n;
			GM = new int*[n];
			for (int i = 0; i < n; i++)
				GM[i] = new int[n];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (i == j)
						GM[i][j] = 0;
					else
						GM[i][j] = 0xffff;
				}
			}
		}
	}
	void getRes(vector<int> &r) {
		NumEm = r;
	}
	void input(int i, int j, int w) {
		GM[i][j] = w;
		GM[j][i] = w;
	}
	int MinPath(int S, int T) {
		for (int i = 0; i < N; i++) {
			dist.push_back(0);
			path.push_back(0);
			res.push_back(0);
			IsShort.push_back(false);
			IsRes.push_back(false);
			IsVisit.push_back(false);
		}
		res[S] = NumEm[S];
		IsShort[S] = true;
		IsRes[S] = true;
		for (int i = 0; i < N; i++) {
			dist[i] = GM[S][i];
			if (GM[S][i] < 0xffff / 2 && GM[S][i] != 0) {
				path[i] = S;
				res[i] = res[S] + NumEm[i];
			}
		}
		for (int i = 1; i < N; i++) {
			int idx = ArrayMin(dist);
			for (int j = 0; j < N; j++) {
				if (dist[j] > dist[idx] + GM[idx][j] && GM[idx][j]!=0xffff) {
					dist[j] = dist[idx] + GM[idx][j];
					path[j] = idx;
				}
			}
		}
		MinDist = dist[T];
		return dist[T];
	}
//i为访问第i个节点
//dt为destination
	void DFS(int i,int dt) {
		if (accDist > MinDist) return;
		IsVisit[i] = true;
		accres += NumEm[i];
		if (i == dt) {
			count++;
			if (accres >= maxres) maxres = accres;
			IsVisit[i] = false;
			accres -= NumEm[i];
			return;
		}
		for (int j = 0; j < N; j++) {
			if ((GM[i][j] != 0xffff) && (i != j)&&(IsVisit[j] != true)) {
				accDist += GM[i][j];
				DFS(j,dt);
				accDist -= GM[i][j];
			}
		}
		IsVisit[i] = false;
		accres -= NumEm[i];
	}
	int ArrayMin(vector<int> &s) {
		int idx;
		int temp = 0xffff+10;
		for (int i = 0; i < N; i++) {
			if ((s[i] <= temp) && (IsShort[i] == false)) {
				idx = i;
				temp = s[i];
			}
				
		}
		IsShort[idx] = true;
		return idx;
	}
	int ArrayMax(vector<int> &s) {
		int idx;
		int temp = -0xffff - 10;
		for (int i = 0; i < N; i++) {
			if ((s[i] >= temp) && (IsRes[i] == false)) {
				idx = i;
				temp = s[i];
			}
		}
		IsRes[idx] = true;
		return idx;
	}
	//顺序是颠倒的
	vector<int> getPath(int S,int T,vector<int> &P) {
		int j = T;
		vector<int> Path;
		while (j != S) {
			Path.push_back(j);
			j = P[j];
		}
		Path.push_back(S);
		return Path;
	}
	int getWeight(int i, int j) {
		return GM[i][j];
	}
	int getCount() {
		return count;
	}
	int getRes() {
		return maxres;
	}
};

int main()
{
	int N, M, C1, C2;
	cin >> N >> M >> C1 >> C2;
	Graph G(N);
	vector<int> res;
	for (int i = 1; i <= N; i++) {
		int temp;
		cin >> temp;
		res.push_back(temp);
	}
	G.getRes(res);
	for (int i = 1; i <= M; i++) {
		int s, t, w;
		cin >> s >> t >> w;
		G.input(s, t, w);
	}
	vector<int> path;
	
	G.MinPath(C1, C2);
	G.DFS(C1, C2);

	path.push_back(G.getCount());
	path.push_back(G.getRes());
	cout << path[0] << ' ' << path[1]<<endl;
    return 0;
}


