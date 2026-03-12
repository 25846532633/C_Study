#include "BinaryTree.h"

int main()
{
	TreeNode* root = CreateTree();
	PrevOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	printf("%d\n", TreeSize(root));
	printf("%d\n", TreeLeafSize(root));
	printf("%d\n", TreeHeight(root));
	printf("%d\n", TreeLevelK(root,4));
	return 0;
}

