#include "BinaryTree.h"

TreeNode* BuyTreeNode(int x)
{
	TreeNode* newnode = (TreeNode*)malloc(sizeof(TreeNode));
	assert(newnode);

	newnode->data = x;
	newnode->left = newnode->right = NULL;
}

TreeNode* CreateTree()
{
	TreeNode* node1 = BuyTreeNode(1);
	TreeNode* node2 = BuyTreeNode(2);
	TreeNode* node3 = BuyTreeNode(3);
	TreeNode* node4 = BuyTreeNode(4);
	TreeNode* node5 = BuyTreeNode(5);
	TreeNode* node6 = BuyTreeNode(6);
	TreeNode* node7 = BuyTreeNode(7);


	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	node5->right = node7;

	return node1;
}

void PrevOrder(TreeNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	printf("%d ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}

void InOrder(TreeNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}


void BackOrder(TreeNode* root)
{
	if (root == NULL)
	{
		printf("N");
		return;
	}

	BackOrder(root->left);
	BackOrder(root->right);
	printf("%d ", root->data);
}

int TreeSize(TreeNode* root)
{
	if (root == NULL)
		return 0;

	return 1 + TreeSize(root->left) + TreeSize(root->right);
}

int TreeLeafSize(TreeNode* root)
{
	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return 1;

	return TreeLeafSize(root->left) +
		TreeLeafSize(root->right);
}

int TreeHeight(TreeNode* root)
{
	if (root == NULL)
		return 0;

	int Heightleft = TreeHeight(root->left);
	int HeightRight = TreeHeight(root->right);

	return Heightleft > HeightRight ?
		Heightleft + 1 : HeightRight + 1;
}

int TreeLevelK(TreeNode* root, int k)
{
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	int Left = TreeLevelK(root->left, k - 1);
	int right = TreeLevelK(root->right, k - 1);

	return Left + right;
}

TreeNode* TreeFind(TreeNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;

	if (root->data == x)
		return root;

	TreeNode* left = TreeFind(root->left, x);
	TreeNode* right = TreeFind(root->right, x);

	return NULL;
}