typedef struct NODE
{
	int key;
	char value[50];
	struct NODE *left, *right;
} BNODE;

int size(BNODE *root);
int height(BNODE *root);
BNODE *find(BNODE *root, int key);
BNODE *find_parent(BNODE *root, BNODE *node);
void insert(BNODE **root, int key, char* value);
void remove_node(BNODE **root, BNODE* node);
void remove_key(BNODE **root, int key);
void inorder_traversal(BNODE * root);

// can hoan thien ham
void delete_tree(BNODE *root); // duyet theo thu tu sau
BNODE *rightmost(BNODE *root); // tim va tra ve nut phai nhat tren con trai cua root
