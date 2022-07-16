#include <stdio.h>
#include "binarytree.h"

int main()
{
	BNODE *root = NULL;
	insert(&root, 12, "A12");
	insert(&root, 10, "B10");
	insert(&root, 7, "C7");
	insert(&root, 17, "D17");
	insert(&root, 3, "E3");
	insert(&root, 11, "F11");
	insert(&root, 15, "G15");
	inorder_traversal(root);
	
	printf("Do cao cua cay %d\n",height(root));
	
	BNODE *p = find(root,11);
	BNODE *parent = find_parent(root,p);
	printf("Parent cua %d la %d\n",p->key, parent->key);
	
	remove_key(&root,12);
	inorder_traversal(root);
	
	p = find(root,10);
	parent = find_parent(root,p);
	printf("Parent cua %d la %d\n",p->key, parent->key);
	
	return 0;
}