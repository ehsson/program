typedef int Data;

typedef struct _node {
	Data data;
	struct _node* prev;
	struct _node* next;
} Node;

typedef struct _DLinkedList {
	Node* head;
	Node* cur;
	int numOfData;
} DBLinkedList;

typedef DBLinkedList List;

void listInit(List* plist);
void LInsert(List* plist, Data data);

bool LFirst(List* plist, Data* pdata);
bool LNext(List* plist, Data* pdata);
bool LPrevious(List* plist, Data* pdata);

int LCount(List* plist);
