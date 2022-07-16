#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
using namespace std;

TREENODE *createTREE(char key) 
{
    TREENODE *newTree = (TREENODE *)malloc(sizeof(TREENODE));
    newTree->left = NULL;
    newTree->right = NULL;
    newTree->data = key;
    return newTree;
}

// Thêm nút có giá trị key vào con trái nếu nó rỗng
void insertLefT(TREENODE *root, char key)
{
    if(root->left!=NULL) return;
    TREENODE *newTree = (TREENODE *)malloc(sizeof(TREENODE));
    newTree->left=NULL;
    newTree->right=NULL;
    newTree->data=key;
    root->left = newTree;
}

//Thêm nút có giá trị key vào con phải nếu nó rỗng
void insertRight(TREENODE *root, char key)
{
    if(root->right!=NULL) return;
    TREENODE *newTree = (TREENODE *)malloc(sizeof(TREENODE));
    newTree->left=NULL;
    newTree->right=NULL;
    newTree->data=key;
    root->right = newTree;
}

//Duyệt cây và in ra nhãn các nút theo thứ tự trước
void preorderTraversal(TREENODE *root)
{
    if(root==NULL) return;
    printf("%c", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

//Duyệt cây và in ra nhãn các nút theo thứ tự giua
void inorderTraversal(TREENODE *root)
{
    if(root==NULL) return;
    inorderTraversal(root->left);
    printf("%c", root->data);
    inorderTraversal(root->right);
}

//Duyệt cây và in ra nhãn các nút theo thứ tự sau
void postorderTraversal(TREENODE *root)
{
    if(root==NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%c", root->data);
}

//dem so nut
int countNodes(TREENODE *root)
{
    if (root==NULL) return 0;
    else return( countNodes(root->left)+countNodes(root->right))+1;
}

//dem so nut la tren cay
int countLeaves(TREENODE *root)
{
    if (root==NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    else 
        return countLeaves(root->left) + countLeaves(root->right);
}

//Tinh chieu cao
int calHeight(TREENODE *root)
{
    if (root==NULL) return -1;
    if(root->left==NULL && root->right==NULL) return 0;
    int l = calHeight(root->left);
    int r = calHeight(root->right);
    return 1+ (l>r?l:r);
}

//Kiem tra 2 cay doi xung
int isSymmetric(TREENODE *r1, TREENODE *r2)
{
    if (r1==NULL && r2==NULL) return 1;
    if (r1==NULL && r2!=NULL) || (r1!=NULL && r2==NULL);
    return isSymmetric(r1->left,r2->right) && isSymmetric(r1->right,r2->left);
}


