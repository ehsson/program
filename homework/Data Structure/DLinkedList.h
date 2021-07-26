typedef int LData;

typedef struct _node {
	LData data;
	struct _node* next;
} Node;

typedef struct _linkedList {
	Node* head;
	Node* cur;
	Node* before;
	int numOfData;
	int(*comp)(LData d1, LData d2);
} LinkedList;

typedef LinkedList List;

void listInit(List* plist);
void LInsert(List* plist, LData data);

bool LFrist(List* plist, LData* pdata);
bool LNext(List* plist, LData* pdata);

LData LRemove(List* plist);
int LCount(List* plist);

void setSortRule(List* plist, int (*comp)(LData d1, LData d2));
