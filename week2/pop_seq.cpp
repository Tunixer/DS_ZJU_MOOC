#include <iostream>
#include <vector>

using namespace std;


int main(){
	vector<int> st;
	int M, N, k;
	cin >> M >> N >> k;
	while (k--){
		st.clear();
		vector<int> tmp;
		vector<int> tmpin;
		for (int ii = 1; ii < N + 1; ii++){
			int tt;
			cin >> tt;
			tmp.push_back(tt);
			tmpin.push_back(ii);
		}
		vector<int>::iterator i, j;
		for (i = tmp.begin(), j = tmpin.begin(); i != tmp.end();){
			if (st.empty()) {
				st.push_back(*j);
				j++;
			}
			if (st.size() > M) break;
			if (*i == st.back()){
				i++;
				if (st.empty()) break;
				st.pop_back();
			}
			else if (*i > st.back()){
				while (1){
					st.push_back(*j);
					if (*j == *i){
						j++;
						break;
					}
					else
						j++;
				}
			}
			else if (*i < st.back()){
				break;
			}

		}
		if (i != tmp.end())
			cout << "NO\n";
		else
			cout << "YES\n";

	}
}
