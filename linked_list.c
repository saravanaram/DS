// linked_list.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

typedef struct node
{
	int data;
	struct node* next;

}NODE;

typedef struct list
{
	NODE* head;
}LIST;

void AddFirst(LIST* l, int d);
void AddLast(LIST* l,int d);
LIST* Initialize();
NODE* CreateNode(int d);
void PrintList(LIST* l);
void DeleteNode(LIST* l, int d);
void DestroyList(LIST* l);

int _tmain(int argc, _TCHAR* argv[])
{
	LIST* list;
	list = Initialize();
	AddFirst(list,1);
	AddFirst(list,2);
	AddLast(list,3);
	PrintList(list);
	DeleteNode(list,5);
	DeleteNode(list,2);
	PrintList(list);
	DestroyList(list);
	return 0;
}
LIST* Initialize()
{
	LIST* l;
	l = (LIST*) calloc(1,sizeof(LIST));
	l->head = NULL;
	return l;
}
void AddFirst(LIST* l, int d)
{
	NODE* n;
	if (l->head == NULL)
	{
		//List is empty
		l->head = CreateNode(d);
	}
	else
	{
		n = CreateNode(d);
		n->next = l->head;
		l->head = n;
	}
}

void AddLast(LIST* l, int d)
{
	NODE* current = NULL;
	
	if (l->head == NULL)
	{
		//List is empty
		l->head = CreateNode(d);
	}
	else
	{
		current = l->head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = CreateNode(d);
	}
}
NODE* CreateNode(int d)
{
	NODE* n;
	n = (NODE*) calloc(1,sizeof(NODE));
	if (n != NULL)
	{
		n->data = d;
		n->next = NULL;
	}
	return n;
}

void PrintList(LIST* l)
{
	NODE* list =l->head;
	while(list)
	{
		printf("%d -> ",list->data);
		list = list->next;
	}
	printf(" NULL\n");
}

void DeleteNode(LIST* l, int d)
{
	NODE* current = l->head;
	NODE* previous = current;
	bool isavailable = false;

	if (current == NULL)
	{
		printf("\n%d data not found in linked list",d);
		return;
	}

	while (current)
	{
		if (current->data == d)
		{
			isavailable=true;
			previous->next = current->next;
			if (current == l->head)
				l->head = current->next;
			free(current);
			break;
		}
		previous = current;
		current = current->next;
	}
	if (isavailable)
	{
		printf("\n%d deleted from linked list",d);
	}
	else
	{
		printf("\n%d data not found in linked list",d);
	}
}
void DestroyList(LIST* l)
{
	NODE* current = l->head;
	NODE* next = current;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(l);
}
