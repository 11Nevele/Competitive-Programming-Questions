#include <iostream>
#include <stdio.h>
#define KEY(n) (n ? n->key : 0)
#define SIZE(n)(n ? n->size : 0)
using namespace std;

class Node
{
public:
	int key;
	Node* lchild, * rchild;
};

class Tree
{
public:
	Node* root;
	Tree(int val)
	{
		root = (Node*)malloc(sizeof(Node));
		root->key = val;
		root->lchild = root->rchild = NULL;
	}
	Tree()
	{
		root = (Node*)malloc(sizeof(Node));
		root->lchild = root->rchild = NULL;
	}
	void clear(Node* root)
	{
		if (root == NULL)
			return;
		clear(root->lchild);
		clear(root->rchild);
		free(root);
		return;
	}
	Node* search(Node* root, int val)
	{
		if (root == NULL)
			return NULL;
		if (root->key == val)
			return root;
		if (val < root->key)
			return search(root->lchild, val);
		else
			return search(root->rchild, val);
	}
	Node* insert(Node* root, int val)
	{
		if (root == NULL)
		{
			Node* p = (Node*)malloc(sizeof(Node));
			p->key = val;
			p->lchild = p->rchild = NULL;
			return p;
		}
		if (root->key == val)
			return root;
		if (val < root->key)
			root->lchild = insert(root->lchild, val);
		else
			root->rchild = insert(root->rchild, val);
		return root;
	}
	Node* predecessor(Node* root)
	{
		Node* temp = root->lchild;
		while (temp->rchild) temp = temp->rchild;
		return temp;
	}
	Node* erase(Node* root, int key)
	{
		if (root == NULL)
			return NULL;
		if (key < root->key)
			root->lchild = erase(root->lchild, key);
		else if (key > root->key)
			root->rchild = erase(root->rchild, key);
		else
		{
			if (root->lchild == NULL || root->rchild == NULL)
			{
				Node* temp = root->lchild ? root->lchild : root->rchild;
				free(root);
				return temp;
			}
			else
			{
				Node* temp = predecessor(root);
				root->key = temp->key;
				root->lchild = erase(root->lchild, temp->key);

			}
		}
		return root;
	}
	void output(Node* root)
	{
		if (root == NULL)
			return;
		output(root->lchild);
		printf("(%d, %d, %d)\n",
			KEY(root),  KEY(root->lchild), KEY(root->rchild)
		);
		output(root->rchild);
	}
};

/*Node* getNewNode(int key)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->size = 0;
	p->key = key;
	p->lchild = p->rchild = NULL;
	return p;
}
void update_size(Node* root)
{
	root->size = SIZE(root->lchild) + SIZE(root->rchild) + 1;
	return;
}
void clear(Node* root)
{
	if (root == NULL)
		return;
	clear(root->lchild);
	clear(root-> rchild);
	free(root);
	return;

}
bool search(Node* root, int val)
{
	if (root == NULL)
		return 0;
	if (root->key == val)
		return 1;
	if (val < root->key)
		return search(root->lchild, val);
	return search(root->rchild, val);
}
Node* insert(Node* root, int key)
{
	if (root == NULL)
		return getNewNode(key);
	if (root->key == key)
		return root;
	if (key < root->key)
		root->lchild = insert(root->lchild, key);
	else 
		root->rchild = insert(root->rchild, key);
	update_size(root);
	return root;
}
Node* predecessor(Node* root)
{
	Node* temp = root->lchild;
	while (temp->rchild) temp = temp->rchild;
	return temp;
}
Node* erase(Node* root, int key)
{
	if (root == NULL)
		return NULL;
	if (key < root->key)
		root->lchild = erase(root->lchild, key);
	else if (key > root->key)
		root->rchild = erase(root->rchild, key);
	else
	{
		if (root->lchild == NULL || root->rchild == NULL)
		{
			Node* temp = root->lchild ? root->lchild : root->rchild;
			free(root);
			return temp;
		}
		else
		{
			Node* temp = predecessor(root);
			root->key = temp->key;
			root->lchild = erase(root->lchild, temp->key);

		}
	}
	update_size(root);
	return root;
}
void output(Node* root)
{
	if (root == NULL)
		return;
	output(root->lchild);
	printf("(%d[%d], %d, %d)\n",
		KEY(root), SIZE(root), KEY(root->lchild), KEY(root->rchild)
	);
	output(root->rchild);
}*/
int main()
{
	int op, val;
	Tree t(5);
	while (~scanf_s("%d%d", &op, &val))
	{
		switch (op)
		{
		case 0: printf("search %d, result : %d\n", val, t.search(t.root, val));
			break;
		case 1:
			t.root = t.insert(t.root, val);
			break; 
		case 2:
			t.root = t.erase(t.root, val); 
			break;
		}
		if (op)
		{
			t.output(t.root);
			cout << "\n_____________" << endl;
		}
	}
	return 0;
}