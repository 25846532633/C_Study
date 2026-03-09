#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}TreeNode;

//创建结点和树
TreeNode* BuyTreeNode(int x);
TreeNode* CreateTree();

//前、中、后序遍历
void PrevOrder(TreeNode* root);
void InOrder(TreeNode* root);
void BackOrder(TreeNode* root);

//求树的高度、叶子树和大小
int TreeSize(TreeNode* root);
int TreeLeafSize(TreeNode* root);
int TreeHeight(TreeNode* root);

//求第K层的节点数
int TreeLevelK(TreeNode* root, int k);