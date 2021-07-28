typedef int Data;

typedef struct _node {
	Data data;
	struct _node* next;
} Node;

typedef struct _CLL {
	Node* tail;
	Node* cur;
	Node* before;
	int numOfData;
} CList;

typedef CList List;

void listInit(List* plist);
void LInsert(List* plist, Data data);
void LInsertFront(List* plist, Data data);

bool LFirst(List* plist, Data* pdata);
bool LNext(List* plist, Data* pdata);

Data LRemove(List* plist);
int LCount(List* plist);
