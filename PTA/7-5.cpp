
#include <iostream>
#include <vector>
using namespace std;
template <class T>
class Heap :public vector<T> {
private:
	int _length;
public:
	Heap();
	void BuildHeap();
	void ToDown(int);
	void Input(int);
	void Swap(int, int);
	void PrintPath(int i);
	void Print();
	void Insert(int);
	int  getLen();
};
template <typename T>
Heap<T>::Heap() {
	this->_length = 0;
	this->push_back(0);
}

template <typename T>
void Heap<T>::Insert(int x) {
	this->_length += 1;
	this->push_back(x);
	int j = this->_length;
	while (j > 1) {
		if ((*this)[j] < (*this)[j / 2]) Swap(j, j / 2);
		j /= 2;
	}
}
template <typename T>
void Heap<T>::Swap(int i, int j) {
	T temp;
	temp = (*this)[j];
	(*this)[j] = (*this)[i];
	(*this)[i] = temp;
}
template <typename T>
void Heap<T>::ToDown(int t) {
	int len = this->_length;
	if (t > len || 2 * t>len) return;
	if (2 * t + 1 > len) {
		if ((*this)[2 * t] < (*this)[t]) Swap(2 * t, t);
		return;
	}
	int idx = (((*this)[2 * t] < (*this)[2 * t + 1]) ? 2 * t : (2 * t + 1));
	if ((*this)[t] > (*this)[idx]) {
		Swap(t, idx);
		ToDown(idx);
	}
}

template <typename T>
void Heap<T>::BuildHeap() {
	int t = this->_length;
	for (int i = t / 2; i >= 1; i = i / 2) {
		Heap::ToDown(i);
	}
}
template <typename T>
void Heap<T>::Input(int n) {
	T t;
	for (int i = 1; i <= n; i++) {
		cin >> t;
		Insert(t);
	}
}

template <typename T>
void Heap<T>::PrintPath(int i) {
	for (int t = i; t > 1; t = t / 2)
		cout << (*this)[t] << ' ';
	cout << (*this)[1] << endl;
}

template <typename T>
void Heap<T>::Print() {
	for (int i = 1; i <= this->_length; i++)
		cout << (*this)[i] << ' ';
	cout << endl;
}
template <typename T>
int Heap<T>::getLen() {
	return this->_length;
}
int main()
{
	int M, N;
	cin >> N >> M;
	Heap<int> H;
	H.Input(N);
//	H.BuildHeap();
//	H.Print();
	for (int i = 1; i <= M; i++) {
		int temp;
		cin >> temp;
		H.PrintPath(temp);
	}
	cin;
	return 0;
}
