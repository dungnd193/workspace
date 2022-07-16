#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
int main()
{
	TREENODE *root;
	root = createTree('A');	
		
	insertLeft(root,'B');	
	insertRight(root,'F');	
	
	insertLeft(root->left,'C');
	insertRight(root->left,'D');
	insertLeft(root->right,'E');

	insertLeft(root->right->left,'G');	
	insertRight(root->right->left,'I');
	
	insertRight(root->right->left->right,'H');
	
	printf("\nPreOrder:");
	preorderTraversal(root);
	
	printf("\nInOrder:");
	inorderTraversal(root);
	
	printf("\nPostOrder:");
	postorderTraversal(root);
	
	printf("\nLevelTraversel:");
	levelTraversal(root);
	
	printf("\nHeight: %d\n",calHeight(root));
	
	
	return 0;
}
int main1()
{
	TREENODE *r1,*r2;
	r1 = createTree('A');	
	insertLeft(r1,'B');	
	insertRight(r1->left,'F');	
	insertLeft(r1->left,'I');
		
	r2 = createTree('D');	
	insertRight(r2,'E');
	insertLeft(r2->right,'F');
	
	if(isSymmetric(r1,r2))
	{
		printf("Hai cay nay la doi xung!\n");
	}
	else
		printf("KHONG doi xung!");
	return 0;
}