#include <iostream>
using namespace std;

struct AVLNode
{
	AVLNode* left;
	AVLNode* right;
	int data;
	int height;
};
class AVLTree
{
public:
	AVLNode* root=NULL;

	AVLTree()
	{

	}

	AVLNode* newNode(int val)
	{
		AVLNode* temp = new AVLNode;
		temp->data = val;
		temp->height = 1;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}

	int getHeight(AVLNode* node)
	{
		if (node == NULL)
			return 0;
		return node->height;
	}

	int max(int a, int b) 
	{
		return (a > b) ? a : b;
	}

	int getBalanceFactor(AVLNode* N) 
	{
		if (N == NULL)
			return 0;
		return getHeight(N->left) - getHeight(N->right);
	}

	int getDiameter()
	{
		return getHeight(root->left) + getHeight(root->right) ;
	}

	AVLNode* getRoot()
	{
		return root;
	}

	AVLNode* nodeWithMimumValue(AVLNode* node) 
	{
		AVLNode* temp = node;
		while (temp->left != NULL)
			temp = temp->left;
		return temp;
	}

	AVLNode* RightRotate(AVLNode* t1)
	{
		AVLNode* t2 = t1->left;
		t1->left = t2->right;
		t2->right = t1;
		t1->height = max(getHeight(t1->left), getHeight(t1->right)) + 1;
		t2->height = max(getHeight(t2->left), getHeight(t2->right)) + 1;
		return t2;
	}

	AVLNode* LeftRotate(AVLNode* t1)
	{
		AVLNode* t2 = t1->right;
		t1->right = t2->left;
		t2->left = t1;
		t1->height = max(getHeight(t1->left), getHeight(t1->right)) + 1;
		t2->height = max(getHeight(t2->left), getHeight(t2->right)) + 1;
		return t2;
	}

	AVLNode* AVLinsert(int val, AVLNode* node)
	{
		//--------------------for simple left right insertion----------------------------//
		//
		if (node == NULL)
		{
			//cout << val << "\n";
			return (newNode(val));

		}
		else if (val < node->data)
			node->left = AVLinsert(val,node->left);
		else if (val > node->data)
			node->right = AVLinsert(val, node->right);
		else
			return node;

		node->height = max(getHeight(node->left) , getHeight(node->right))+1;

		int BalanceFactor(getBalanceFactor(node));
		if (BalanceFactor > 1)
		{
			if (val < node->left->data)
			{
				return RightRotate(node);
			}
			else if (val > node->left->data)
			{
				node->left=LeftRotate(node->left);
				return RightRotate(node);
			}
		}
		if (BalanceFactor < -1)
		{
			if (val > node->right->data)
			{
				return LeftRotate(node);
			}
			else if (val < node->right->data)
			{
				node->right = RightRotate(node->right);
				return LeftRotate(node);
			}
		}
		return node;
	}

	void insert(int val)
	{
		root = AVLinsert(val, root);
	}

	AVLNode* AVLdelete(int val, AVLNode* root)
	{
		if (root == NULL)
			return root;
		else if (val < root->data)
			root->left = AVLdelete(val, root->left);
		else if (val > root->data)
			root->right = AVLdelete(val, root->right);
		else
		{
			if ((root->left == NULL) || (root->right == NULL))
			{
				AVLNode* temp = root->left ? root->left : root->right;
				if (temp == NULL)
				{
					temp = root;
					root = NULL;
				}
				else
					*root = *temp;
			}
			else
			{
				AVLNode* temp = nodeWithMimumValue(root->right);
				root->data = temp->data;
				root->right = AVLdelete(temp->data, root->right);
			}
		}
		if (root == NULL)
			return root;

		root->height = 1 + max(getHeight(root->left), getHeight(root->right));
		int BalanceFactor(getBalanceFactor(root));
		if (BalanceFactor > 1)
		{
			if (val < root->left->data)
			{
				return RightRotate(root);
			}
			else if (val > root->left->data)
			{
				root->left = LeftRotate(root->left);
				return RightRotate(root);
			}
		}
		if (BalanceFactor < -1)
		{
			if (val > root->right->data)
			{
				return LeftRotate(root);
			}
			else if (val < root->right->data)
			{
				root->right = RightRotate(root->right);
				return LeftRotate(root);
			}
		}
		return root;
	}

	void remove(int val)
	{
		root = AVLdelete(val, root);
	}

	void inorder(AVLNode* temp)
	{
		if (temp == NULL)
			return;
		inorder(temp->left);
		cout << temp->data << " ";
		inorder(temp->right);
	}

	void display()
	{
		cout << "In-order traversal: ";
		inorder(root);
		cout << "\n";
	}

	AVLNode* finder(int val, AVLNode* root)
	{
		if (root == NULL)
			return root;
		else if (val < root->data)
			root->left = AVLdelete(val, root->left);
		else if (val > root->data)
			root->right = AVLdelete(val, root->right);
		else
		{
			return root;
		}

	}

	void splitTree(int val, AVLTree &A, AVLTree &B)
	{		
		AVLNode* temp = finder(val, root);
		A.root = temp->left;
		B.root = temp->right;	
	}

};