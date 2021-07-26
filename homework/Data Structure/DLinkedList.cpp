#include <iostream>
#include "DLinkedList.h"
using namespace std;

void listInit(List* plist)
{
	plist->head = new Node;
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;
}

void FInsert(List* plist, LData data)
{
	Node* newNode = new Node;
	newNode->data = data;

	newNode->next = plist->head->next;
	plist->head->next = newNode;

	plist->numOfData++;
}

void SInsert(List* plist, LData data)
{

}

void LInsert(List* plist, LData data)
{
	if (plist->comp == NULL)
		FInsert(plist, data);
	else
		SInsert(plist, data);
}

bool LFrist(List* plist, LData* pdata)
{
	if (plist->head->next == NULL)
		return false;

	plist->before = plist->head;
	plist->cur = plist->head->next;

	*pdata = plist->cur->data;
	return true;
}

bool LNext(List* plist, LData* pdata)
{
	if (plist->cur->next == NULL)
		return false;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return true;
}

LData LRemove(List* plist)
{
	Node* rpos = plist->cur;
	LData rdata = rpos->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	delete rpos;
	plist->numOfData--;
	return rdata;
}

int LCount(List* plist)
{
	return plist->numOfData;
}

void setSortRule(List* plist, int (*comp)(LData d1, LData d2))
{

}
