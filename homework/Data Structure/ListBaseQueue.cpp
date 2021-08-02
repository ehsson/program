#include <iostream>
#include "ListBaseQueue.h"
using namespace std;

void QueueInit(Queue* pq)
{
	pq->front = NULL;
	pq->rear = NULL;
}

bool QIsEmpty(Queue* pq)
{
	if (pq->front == NULL)
		return true;
	else
		return false;
}

void Enqueue(Queue* pq, Data data)
{
	Node* newNode = new Node;
	newNode->next = NULL;
	newNode->data = data;

	if (QIsEmpty(pq)) {
		pq->front = newNode;
		pq->rear = newNode;
	}
	else {
		pq->rear->next = newNode;
		pq->rear = newNode;
	}
}

Data Dequeue(Queue* pq)
{
	Node* delNode;
	Data retData;

	if (QIsEmpty(pq)) {
		cout << "Queue Memory Error!\n";
		exit(-1);
	}
	
	delNode = pq->front;
	retData = delNode->data;
	pq->front = pq->front->next;

	delete delNode;
	return retData;
}

Data QPeek(Queue* pq)
{
	if (QIsEmpty(pq)) {
		cout << "Queue Memory Error!\n";
		exit(-1);
	}

	return pq->front->data;
}
