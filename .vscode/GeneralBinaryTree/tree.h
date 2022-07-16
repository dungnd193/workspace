#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include <queue>
using namespace std;

TREENODE * createTree(char key)
{
	TREENODE *newTree = (TREENODE *)malloc(sizeof(TREENODE));
	newTree->left = NULL;
	newTree->right = NULL;
	newTree->data = key;
	return newTree;
}

// chi them neu con trai cua goc la NULL
void insertLeft(TREENODE *root, char key)
{
	if(root->left!=NULL) return;
	TREENODE *newTree = (TREENODE *)malloc(sizeof(TREENODE));
	newTree->left = NULL;
	newTree->right = NULL;
	newTree->data = key;
	root->left = newTree;
}

// chi them neu con phai cua goc la NULL
void insertRight(TREENODE *root, char key)
{
	if(root->right!=NULL) return;
	TREENODE *newTree = (TREENODE *)malloc(sizeof(TREENODE));
	newTree->left = NULL;
	newTree->right = NULL;
	newTree->data = key;
	root->right = newTree;
}

void preorderTraversal(TREENODE *root)
{
	if(root==NULL) return;
	printf("%c ", root->data);
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

void inorderTraversal(TREENODE *root)
{
	if(root==NULL) return;	
	inorderTraversal(root->left);
	printf("%c ", root->data);
	inorderTraversal(root->right);
}

void postorderTraversal(TREENODE *root)
{
	if(root==NULL) return;	
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	printf("%c ", root->data);
}

void levelTraversal(TREENODE *root)
{
	if(root==NULL) return;
	queue<TREENODE *> Q;
	Q.push(root);
	while(!Q.empty())
	{
		TREENODE * node = Q.front();
		Q.pop();
		printf("%c ", node->data);
		if(node->left!=NULL)Q.push(node->left);
		if(node->right!=NULL)Q.push(node->right);
	}
}

int calHeight(TREENODE *root)
{
	if(root == NULL) return -1;
	if(root->left==NULL && root->right==NULL) return 0;
	return 1 + max(calHeight(root->left),calHeight(root->right));
}

// kiem tra 2 cay doi xung
int isSymmetric(TREENODE *r1,TREENODE *r2)
{
	if(r1 == NULL && r2== NULL) return 1;
	if((r1== NULL && r2!=NULL)||(r1!=NULL && r2==NULL)) return 0;
	return isSymmetric(r1->left, r2->right) &&
			isSymmetric(r1->right, r2->left);
}