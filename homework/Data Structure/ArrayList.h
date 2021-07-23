#define LIST_LEN 100
typedef int LData;

typedef struct {
	LData arr[LIST_LEN];
	int numOfData;
	int curPosition;
} ArrayList;

typedef ArrayList List;

void LInit(List* plist);
void LInsert(List* plist, LData data);
bool LFirst(List* plist, LData* pdata);
bool LNext(List* plist, LData* pdata);
LData LRemove(List* plist);
int LCount(List* plist);
