#pragma once
class Node
{
public:
	Node* lchild;
	int data;
	Node* rchild;
};


class BinaryTree {
public:
	Node* root;
	BinaryTree() { root = nullptr; }
	void CreateTree();
	void PreOrder(Node* p);
	void PostOrder(Node* p);
	void InOrder(Node* p);
	void itPreOrder(Node* t);
	void itInOrder(Node* t);
	void itPostOrder(Node* t);
	void LevelOrder(Node* p);
	void generateTree(int* pre, int* In,int n	);
	int Height(Node* p);
	int CountNodes(Node* p);
	//~BinaryTree();
};

