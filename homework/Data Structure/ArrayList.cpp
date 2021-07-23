#include <iostream>
#include "ArrayList.h"
using namespace std;

void LInit(List* plist)
{
	plist->numOfData = 0;
	plist->curPosition = -1;
}

void LInsert(List* plist, LData data)
{
	if (plist->numOfData >= LIST_LEN) {
		cout << "저장이 불가합니다.\n";
		return;
	}

	plist->arr[plist->numOfData] = data;
	plist->numOfData++;
}

bool LFirst(List* plist, LData* pdata)
{
	if (plist->numOfData == 0)
		return false;

	plist->curPosition = 0;
	*pdata = plist->arr[plist->curPosition];
	return true;
}

bool LNext(List* plist, LData* pdata)
{
	if (plist->curPosition >= plist->numOfData - 1)
		return false;

	plist->curPosition++;
	*pdata = plist->arr[plist->curPosition];
	return true;
}

LData LRemove(List* plist)
{
	int rpos = plist->curPosition;
	int num = plist->numOfData;
	LData rdata = plist->arr[rpos];

	for (int i = rpos; i < num - 1; i++)
		plist->arr[i] = plist->arr[i + 1];

	plist->numOfData--;
	plist->curPosition--;
	return rdata;
}

int LCount(List* plist)
{
	return plist->numOfData;
}

// using class

#include <iostream>
#include "ArrayList.h"
using namespace std;

ArrayList::ArrayList()
	:numOfData(0), curPosition(-1)
{}

void ArrayList::LInsert(LData data)
{
	if (numOfData >= LIST_LEN) {
		cout << "저장이 불가합니다.\n";
		return;
	}

	arr[numOfData] = data;
	numOfData++;
}

bool ArrayList::LFirst(LData &pdata)
{
	if (numOfData == 0)
		return false;

	curPosition = 0;
	pdata = arr[curPosition];
	return true;
}

bool ArrayList::LNext(LData &pdata)
{
	if (curPosition >= numOfData - 1)
		return false;

	curPosition++;
	pdata = arr[curPosition];
	return true;
}

void ArrayList::LRemove()
{
	int rpos = curPosition;
	int num = numOfData;
	LData rdata = arr[rpos];

	for (int i = rpos; i < num - 1; i++)
		arr[i] = arr[i + 1];

	numOfData--;
	curPosition--;
}

int ArrayList::LCount()
{
	return numOfData;
}
