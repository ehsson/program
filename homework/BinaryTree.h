typedef int BTData;

typedef struct _bTreeNode {
	BTData data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
} BTreeNode;

BTreeNode* makeBTreeNode();
BTData getData(BTreeNode* bt);
void setData(BTreeNode* bt, BTData data);

BTreeNode* getLeftSubTree(BTreeNode* bt);
BTreeNode* getRightSubTree(BTreeNode* bt);

void makeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void makeRightSubTree(BTreeNode* main, BTreeNode* sub);
