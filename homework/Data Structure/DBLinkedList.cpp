#include <iostream>
#include "DBLinkedList.h"
using namespace std;

void listInit(List* plist)
{
	plist->head = NULL;
	plist->cur = NULL;
	plist->numOfData = 0;
}

void LInsert(List* plist, Data data)
{
	Node* newNode = new Node;
	newNode->data = data;

	newNode->next = plist->head;
	if (plist->head != NULL)
		plist->head->prev = newNode;

	newNode->prev = NULL;
	plist->head = newNode;

	plist->numOfData++;
}

bool LFirst(List* plist, Data* pdata)
{
	if (plist->head == NULL)
		return false;

	plist->cur = plist->head;
	*pdata = plist->cur->data;
	return true;
}

bool LNext(List* plist, Data* pdata)
{
	if (plist->cur->next == NULL)
		return false;

	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;

	return true;
}

bool LPrevious(List* plist, Data* pdata)
{
	if (plist->cur->prev == NULL)
		return false;

	plist->cur = plist->cur->prev;
	*pdata = plist->cur->data;

	return true;
}

int LCount(List* plist)
{
	return plist->numOfData;
}
