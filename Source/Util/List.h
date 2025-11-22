#pragma once

typedef struct ListNode
{
	 struct ListNode* Prev;
	 struct ListNode* Next;
}ListNode;

typedef struct List
{
	ListNode* Head;
	ListNode* Tail;
	unsigned int Count;
}List;

void InitHead(List* Head);
void AddTail(List* Head, ListNode* Node);