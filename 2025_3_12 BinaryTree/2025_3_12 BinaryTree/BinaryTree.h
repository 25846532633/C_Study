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

TreeNode* BuyTreeNode(int x);
TreeNode* CreateTree();
void PrevOrder(TreeNode* root);
void InOrder(TreeNode* root);
void BackOrder(TreeNode* root);
//求树的大小
int TreeSize(TreeNode* root);
//求叶子结点的大小
int TreeLeafSize(TreeNode* root);
//求树的高度
int TreeHeight(TreeNode* root);
//求第k层的结点树
int TreeLevelK(TreeNode* root, int k);
//寻找值为x的结点
TreeNode* TreeFind(TreeNode* root, BTDataType x);
// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
TreeNode* TreeCreate(char* a, int* pi)
