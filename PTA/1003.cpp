#include <iostream>
#include <vector>
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
	vector<int> NumEm,res,dist,path;
	vector<bool> IsShort,IsRes;
public:
	Graph(int n = 0){
		if (n > 0) {
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
		}
		res[S] = NumEm[S];
		IsShort[S] = true;
		IsRes[S] = true;
		for (int i = 0; i < N; i++) {
			dist[i] = GM[S][i];
			if (GM[S][i] != 0xffff && GM[S][i] != 0) {
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
		return dist[T];
	}
	int MaxRes(int S, int T) {
		for (int i = 1; i < N; i++) {
			int idx = ArrayMax(res);
			for (int j = 0; j < N; j++) {
				if ((dist[j] == dist[idx] + GM[idx][j]) && (res[j]< res[idx]+NumEm[j])&&(idx!=j)&&(GM[idx][j]!=0xffff)) {
					res[j] = res[idx] + NumEm[j];
				}
			}
		}
		
		return res[T];
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
	//Ë³ÐòÊÇµßµ¹µÄ
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
	path.push_back(G.MinPath(C1, C2));
	path.push_back(G.MaxRes(C1, C2));
	cout << path[0] << ' ' << path[1];
    return 0;
}


