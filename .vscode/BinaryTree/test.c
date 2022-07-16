#include <stdio.h>
#include "tree.c"
int main()
{
	TREENODE *root;
	root = createTree(7,'A');	
		
	insertLeft(root,3,'B');	
	insertRight(root,10,'C');	
	
	insertLeft(root->left,2,'D');
	insertRight(root->left,1,'E');

	if(isBinarySearchTree(root))
		printf("Day la cay nhi phan tim kiem!\n");
	else
		printf("Khong phai cay nhi phan tim kiem!\n");
	return 0;
}