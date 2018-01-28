
#include <cstdlib>
#include <iostream>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left, *right;
public:
	TreeNode(int x = 0) :val(x), left(NULL), right(NULL) {};
};

void TreeDelete(TreeNode *T) {
	if (T == NULL) return;
//	cout << T << endl;
	TreeDelete(T->left);
	TreeDelete(T->right);
	delete T;
}

void LeftTravel(TreeNode *T) {
	if (T == NULL) return;
	LeftTravel(T->left);
	cout << T->val << endl;
	LeftTravel(T->right);
}

class Tree {
private:
	TreeNode *root;
public:
	void Insert(int);
	void Print();
	void InsertTree(int, TreeNode*);
	friend bool operator == (Tree &T1, Tree &T2);
	friend bool IsEqual(TreeNode *T1, TreeNode *T2);
	~Tree();
	Tree();
};
bool IsEqual(TreeNode *T1, TreeNode *T2) {
	bool t1, t2, t3;
	if (T1 == NULL && T2 == NULL) return true;
	if (T1 != NULL && T2 != NULL) {
		t1 = (T1->val == T2->val);
		t2 = IsEqual(T1->left, T2->left);
		t3 = IsEqual(T1->right, T2->right);
		return t1&&t2&&t3;
	}
	else {
		return false;
	}
}
void Tree::Print() {
	LeftTravel(this->root);
}

void Tree::Insert(int x) {
	Tree::InsertTree(x, this->root);
	
}

void Tree::InsertTree(int x, TreeNode *T) {
	if (T == NULL) {
		this->root = new TreeNode(x);
		return;
	}
	if (x < T->val) {
		if (T->left == NULL) {
			T->left = new TreeNode(x);
			return;
		}
		Tree::InsertTree(x, T->left);
	}
	if (x > T->val) {
		if (T->right == NULL) {
			T->right = new TreeNode(x);
			return;
		}
		Tree::InsertTree(x, T->right);
	}
}
//we must use reference here in case shallow copy is triggered 
bool operator==(Tree &T1, Tree &T2) {
	return IsEqual(T1.root, T2.root);
}

Tree::~Tree() {
	TreeDelete(this->root);
}
Tree::Tree(){
	this->root = NULL;
}

int main() {
	int N, L;
	cin >> N;
	while (N != 0) {
		cin >> L;
		Tree T;
		for (int j = 0; j < N; j++) {
			int temp;
			cin >> temp;
			T.Insert(temp);
		}
//		T.Print();
		for (int i = 1; i <= L; i++) {
			Tree T2;
			for (int j = 0; j < N; j++) {
				int temp;
				cin >> temp;
				T2.Insert(temp);
			}
			if (T == T2) cout << "Yes" << endl; else cout << "No" << endl;
		}
		cin >> N;
	}
	return 0;
}

