#include "List.h"
#include <stdio.h>

void InitHead(List *Head)
{
	Head->Head = NULL;
	Head->Tail = NULL;
	Head->Count = 0;
}

void AddTail(List* Head, ListNode* Node)
{
	Head->Count++;
	Node->Prev = NULL;
	Node->Next = NULL;
	if (!Head->Tail)
	{
		Head->Head = Node;
		Head->Tail = Node;
		return;
	} 
	Head->Tail->Next = Node;
	Node->Prev = Head->Tail;
	Head->Tail = Node;
}

void ClearList(List* Head)
{
	while (!Head->Head)
	{
		ListNode* HeadNode = Head->Head;
		Head->Head = HeadNode->Next;
		Head->Head->Prev = NULL;
		Head->Count--;
	}
}