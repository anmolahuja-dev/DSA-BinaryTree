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
	
	cout << "\nWelcome to BINARY TREE Data Structure Program" << endl;
	cout << "\nLets start by creating a Binary Tree....." << endl;
	cout << "Choose an Option \n";
	cout << "[1] - Create a Tree from root"<<endl;
	cout << "[2]- Enter PreOrder and Inorder to generate a tree"<<endl;
	cout << "\nEnter Your choice : ";
	int ch_main;
	cin >> ch_main;
	
	BinaryTree T1;
	int* pre, * In;
	if (ch_main == 1) {
		T1.CreateTree();
	}

	else if (ch_main == 2) {

		int n;
		cout << "\nEnter the PreOrder and Inorder" << endl;
		cout << "Enter the number of elements in preOrder and InOrder : ";
		cin >> n;
		pre = new int[n];
		In = new int[n];

		cout << "Enter the elements in preOrder : ";
		for (int i = 0; i < n; i++) {
			cin >> pre[i];
		}
		cout << "\nNow enter the elements in InOrder : ";
		for (int i = 0; i < n; i++) {
			cin >> In[i];
		}

		T1.generateTree(pre, In, n);
	}
	else {
		cout << "\nInvalid Choice" << endl;
	}

	int ch_sub;

	cout << "\nNow Enter the Operation, you want to perform on this Binary Tree : <<endl";
	do {
		cout << "[1] - Get Preorder (Recurssive) " << endl;
		cout << "[2] - Get Inorder (Recurssive) " << endl;
		cout << "[3] - Get Postorder (Recurssive) " << endl;
		cout << "[4] - Get Preorder (Iterative) " << endl;
		cout << "[5] - Get Inorder (Iterative) " << endl;
		cout << "[6] - Get Postorder (Iterative) " << endl;
		cout << "[7] - Get Levelorder " << endl;
		cout << "[8] - Count the number of Nodes " << endl;
		cout << "[9] - Calculate Height of this Tree " << endl;
		cout << "[0] - Quit" << endl;
		cout << "\nEnter your choice : ";
		cin >> ch_sub;
		
		if (ch_sub == 1) {
			cout << "\nPreOrder : ";
			T1.PreOrder(T1.root);
			cout << endl<<endl;
		}
		else if (ch_sub == 2) {
			cout << "\nInOrder : ";
			T1.InOrder(T1.root);
			cout << endl<<endl;
		}

		else if (ch_sub == 3) {
			cout << "\nPostOrder : ";
			T1.PostOrder(T1.root);
			cout << endl<<endl;
		}
		else if (ch_sub == 4) {
			cout << "\nPreOrder : ";
			T1.itPreOrder(T1.root);
			cout << endl << endl;
		}
		else if (ch_sub == 5) {
			cout << "\nInOrder : ";
			T1.itInOrder(T1.root);
			cout << endl<<endl;
		}
		else if (ch_sub == 6) {
			cout << "\nPostOrder : ";
			T1.itPostOrder(T1.root);
			cout << endl << endl;
		}
		else if (ch_sub == 7) {
			cout << "\nLevel Order : ";
			T1.LevelOrder(T1.root);
			cout << endl<<endl;
		}
		else if (ch_sub == 8) {
			cout<<"\nNodes : "<<T1.CountNodes(T1.root);
			cout << endl<<endl;
		}
		else if (ch_sub == 9) {
			cout<<"\nHeight : "<<T1.Height(T1.root);
			cout << endl<<endl;
		}
		else if (ch_sub == 0) {
			cout << "\nThanks for using this Application :)" << endl<<endl;
		}

		else {
			cout << "\nInvalid choice" << endl<<endl;
		}

	} while (ch_sub != 0);

	
	return 0;
}


