#include "binarytree.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int size(BNODE *root)
{
	if(root==NULL) return 0;
	else return 1 + size(root->left) + size(root->right);
}

int MAX(int a, int b)
{
	return a>b?a:b;
}

int height(BNODE *root)
{
	if(root==NULL) return 0;
	else return 1 + (MAX(height(root->left),height(root->right)));	
}

BNODE *find(BNODE *root, int key)
{
	if(root==NULL) return NULL;
	if(root->key==key) return root;
	if(root->key > key) return find(root->left, key);
	else return find(root->right,key);
}

// tim va tra ve nut cha cua nut node
BNODE * find_parent(BNODE *root, BNODE *node)
{
	// cay rong hoac nut goc thi khong ton tai nut cha
	if(root==NULL || root==node) return NULL;
	if(root->left == node || root->right == node) return root;
	if(root->key > node->key) return find_parent(root->left,node);
	else return find_parent(root->right,node);
}

void insert(BNODE **root, int key, char* value)
{
	// truong hop 1. cay ban dau rong
	if(*root==NULL){
		*root = (BNODE*) malloc(sizeof(BNODE));
		strcpy((*root->value),value);
		(*root)->key=key;
		(*root)->left=NULL;
		(*root)->right=NULL;
	}
	else {
		if((*root)->key > key)
			return insert(&((*root)->left),key,value);
		else 
			return insert(&((*root)->right),key,value);
	}
}

void inorder_traversal(BNODE * root)
{
	
}

void remove_node(BNODE **root, BNODE *node)
{
	BNODE *p = node;
	if(p==NULL) return;

	BNODE *parent = find_parent(*root,p);
	//Co 3 truong hop
	//TH1. Nut bi xoa la nut la
	if(p->left == NULL && p->right == NULL)
	{
		if(parent==NULL) //Nut bi xoa la nut goc, cay chi co 1 nut
			*root = NULL;
		else if(parent->left==p) parent->left==NULL;
		else parent->right==NULL;

		free(p);
	}

	//TH2. Nut bi xoa co con trai hoac con phai
	else if(p->left==NULL) //Co con phai
	{
		if(parent==NULL) //Nut bi xoa la nut goc
			*root = p->right;
		else if(parent->left==p) parent->left=p->right;
		else parent->right=p->right;
		free(p);
	}
	else if(p->right==NULL) //Co con trai
	{
		if(parent==NULL) //Nut bi xoa la nut goc
			*root = p->left;
		else if(parent->left==p) parent->left = p->left;
		else parent->right = p->left;
		free(p);
	}
	//Th3. Cay co du 2 con, THAY bang trai nhat tren con phai
	else
	{
		BNODE *leftmost = p->right;
		while (leftmost->left!=NULL) leftmost=leftmost->left;
		p->key = leftmost->key;
		strcpy(p->value,leftmost->value);
		remove_node(root,leftmost);
	}
}

void remove_key(BNODE **root, int key)
{
	BNODE *p = find(*root,key);
	remove_node(root,p);
}

BNODE *rightmost(BNODE *root) // tim va tra ve nut phai nhat tren con trai cua root
{
	BNODE *p = node;
	if(p==NULL) return;

	BNODE *parent = find_parent(*root,p);

	BNODE *maxright = p->left;
	while(maxright->right!=NULL) maxright=maxright->right;
	p->key = maxright->right;
	strcpy(p->value,maxright->value);
	remove_node(root,maxright);
}

void delete_tree(BNODE *root) // duyet theo thu tu sau
{
	if(root==NULL) return;
	delete_tree(root->left);
	delete_tree(root->right);
	free(root);
}
