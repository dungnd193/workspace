typedef struct TreeNode
{
	int key; // gia tri khoa
	char data; // de demo
	struct TreeNode *left, *right;
} TREENODE;

// tao ra cay voi nut goc dau tien la key
TREENODE * createTree(int key, char data);
// them nut co gia tri key vao con trai neu no rong
void insertLeft(TREENODE *root, int key, char data);
// them nut co gia tri key vao con phai neu no rong
void insertRight(TREENODE *root, int key, char data);

void deleteTree(TREENODE *root);

// Duyet cay va in ra nhan cac nut theo thu tu truoc
void preorderTraversal(TREENODE *root);
void inorderTraversal(TREENODE *root);
void postorderTraversal(TREENODE *root);
// Duyet cay va in ra nhan cac nut theo muc
// het muc hien tai moi den cac nut o muc sau hon -> queue
void levelTraversal(TREENODE *root);

// dem so nut
int countNodes(TREENODE *root);

// dem so nut la tren cay
int countLeaves(TREENODE *root);

// dem so nut trong tren cay
int countInternalNodes(TREENODE *root);


// Tinh chieu cao
int calHeight(TREENODE *root);

// kiem tra 2 cay doi xung
int isSymmetric(TREENODE *r1,TREENODE *r2);

// kiem tra 2 cay dong hinh
int isSynonym(TREENODE *r1,TREENODE *r2);

// tim va tra ve dia chi nut co chua gia tri key tren cay root
TREENODE *findKey(TREENODE *root, int key);
// kiem tra cay r2 co phai cay con cua r1
// *****
int isSubtree(TREENODE *r1,TREENODE *r2);

// tra ve nut cha cua nut hien tai
TREENODE *findParent(TREENODE *r);

// check cay nhi phan tim kiem
int isBinarySearchTree(TREENODE *r);