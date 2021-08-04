#include <iostream>
#include "BinaryTree.h"
using namespace std;

BTreeNode* makeBTreeNode()
{
	BTreeNode* nd = new BTreeNode;
	nd->left = NULL;
	nd->right = NULL;
	return nd;
}

BTData getData(BTreeNode* bt)
{
	return bt->data;
}

void setData(BTreeNode* bt, BTData data)
{
	bt->data = data;
}

BTreeNode* getLeftSubTree(BTreeNode* bt)
{
	return bt->left;
}

BTreeNode* getRightSubTree(BTreeNode* bt)
{
	return bt->right;
}

void makeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->left != NULL)
		delete main->left;

	main->left = sub;
}

void makeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->right != NULL)
		delete main->right;

	main->right = sub;
}
