#include "BinaryTree.h"

TreeNode* BuyTreeNode(int x)
{
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	if (node == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}

	node->data = x;
	node->left = node->right = NULL;

	return node;
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
		return NULL;
	}

	printf("%d ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}

void InOrder(TreeNode* root)
{
	if (root == NULL)
	{
		return NULL;
	}

	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}

void BackOrder(TreeNode* root)
{
	if (root == NULL)
	{
		return NULL;
	}

	BackOrder(root->left);
	BackOrder(root->right);
	printf("%d ", root->data);
}

int TreeSize(TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	return 1 + TreeSize(root->left) + TreeSize(root->right);
}


int TreeLeafSize(TreeNode* root)
{
	//树为空树
	if (root == NULL)
	{
		return 0;
	}
	
	//结点对应左右节点都为空
	if (root->left == NULL && root->right == NULL)
		return 1;

	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

int TreeHeight(TreeNode* root) {
	if (root == NULL)
		return 0;

	int leftHeight = TreeHeight(root->left);
	int rightHeight = TreeHeight(root->right);

	return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

//求第K层的节点数
int TreeLevelK(TreeNode* root, int k)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (k == 1)
		return 1;

	return TreeLevelK(root->left, k - 1) + TreeLevelK(root->right, k - 1);
}
