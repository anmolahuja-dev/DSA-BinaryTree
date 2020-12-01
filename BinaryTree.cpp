#include<iostream>
#include<queue>
#include <stack>
#include "Binarytree.h"

using namespace std;

void BinaryTree::CreateTree() {
	Node* p, * t;
	int x;
	queue<Node *>Q;
	root = new Node;
	cout << "Enter root data : ";
	cin >> root->data;
	root->lchild = NULL;
	root->rchild = NULL;
	Q.emplace(root);

	while (!Q.empty()) {
		p = Q.front();
		Q.pop();

		cout << "Enter left child data of " << p->data << " : ";
		cin >> x;

		if (x != -1) {
			t = new Node;
			t->data = x;
			t->lchild = NULL;
			t->rchild = NULL;
			p->lchild = t;
			Q.emplace(t);
		}

		cout << "Enter right child data of " << p->data << " : ";
		cin >> x;

		if (x != -1) {
			t = new Node;
			t->data = x;
			t->lchild = NULL;
			t->rchild = NULL;
			p->rchild = t;
			Q.emplace(t);
		}
	}
}

void BinaryTree::PreOrder(Node* p) {
	if (p) {
		cout << p->data << " ";
		PreOrder(p->lchild);
		PreOrder(p->rchild);
	}
}

void BinaryTree::PostOrder(Node* p) {
	if (p) {
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		cout << p->data << " ";
	}
}

void BinaryTree::InOrder(Node* p) {
	if (p) {
		InOrder(p->lchild);
		cout << p->data << " ";
		InOrder(p->rchild);
	}
}

void BinaryTree::itPreOrder(Node* t) {
	stack<Node*>s;
	while (t != NULL || !s.empty()) {
		if (t != NULL){
			cout << t->data << " ";
			s.push(t);
			t = t->lchild;
		}
		else {
			t = s.top();
			s.pop();
			t = t->rchild;
		}
	}
}

void BinaryTree::itInOrder(Node* t) {
	stack<Node*>s;
	while (t != NULL || !s.empty()) {
		if (t != NULL) {
			s.push(t);
			t = t->lchild;
		}
		else {
			t = s.top();
			s.pop();
			cout << t->data << " ";
			t = t->rchild;
		}
	}
}

void BinaryTree::itPostOrder(Node* t) {
	stack<long int>s;
	long int temp;
	while (t != NULL || !s.empty()) {
		if (t) {
			s.emplace((long int)t);
			t = t->lchild;
		}
		else {
			temp = (int)s.top();
			s.pop();
			if (temp > 0) {
				s.emplace(-temp);
				t = ((Node*)temp)->rchild;
			}
			else {
				cout << ((Node*)(-1 * temp))->data<<" ";
				t = nullptr;
			}
		}
	}
}

void BinaryTree::LevelOrder(Node* t) {
	queue<Node*>Q;
	cout << t->data << " " ;
	Q.emplace(t);
	while (!Q.empty()) {
		t = Q.front();
		Q.pop();
		if (t->lchild) {
			cout << t->lchild->data << " ";
			Q.emplace(t->lchild);
		}
		if (t->rchild) {
			cout << t->rchild->data << " ";
			Q.emplace(t->rchild);
		}
	}
}

//This function needs some improvement 
//The improvement needed is that it must take right and left child of a node into account using Queue
//Here it is just taking the left and right child of root node into account

void BinaryTree::generateTree(int* pre, int* In, int n) {

	queue<Node*>Q;
	Node* t;

	t = new Node;
	t->data = pre[0];
	t->lchild = NULL;
	t->rchild = NULL;
	root = t;

	Q.emplace(t);
	int i = 0;
	int k = 0;
	while (pre[i] != In[k]) {
		k++;
	}

	i = 1;
	int j = 0;
	int prev;
	while (i != n) {
		
		Node* p = new Node;
		p->data = pre[i];
		p->lchild = NULL;
		p->rchild = NULL;

		if (i == k+1) {

			while (pre[i] != In[k]) {
				k++;
			}

			t = Q.front();
			while (!Q.empty()) {
				Q.pop();
			}
		}
		
		prev = j;
		for (j = 0; j < n; j++) {
			if (pre[i] == In[j]) {
				break;
			}
		}


		if (j <= prev) {
			t->lchild=p;
			t = t->lchild;
			Q.emplace(t);
		}
		else {
			t->rchild = p;
			t = t->rchild;
			
			Q.emplace(t);
		}
		
		i++;
		
	}

}

int BinaryTree::CountNodes(Node* p) {
	if (p) {
		return CountNodes(p->lchild) + CountNodes(p->rchild) + 1;
	}
	return 0;
}

int BinaryTree::Height(Node* p) {
	int x, y;
	if (p) {
		x = Height(p->lchild);
		y = Height(p->rchild);

		if (x > y)return x + 1;
		else return y + 1;
	}
	return 0;
}

int main() {
	
	BinaryTree T1;
	T1.CreateTree();
	cout << endl;
	T1.InOrder(T1.root);
	cout << endl;
	cout << "Nodes : " << T1.CountNodes(T1.root) << endl;
	cout << "Height : " << T1.Height(T1.root) << endl;

	return 0;
}


