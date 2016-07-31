/*
*Program:To implement binary search. 
*Author:Dhiraj Dhungana
*Date:07/31/2014
*Ref:Data structure Using C and C++, chapter 4, page 187
*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *next;
};
typedef struct node *nodeptr;

nodeptr getnode();
void freenode(nodeptr);
void insertatirst(nodeptr *,int);
int deletefromfirst (nodeptr*);
void displaylist();

nodeptr getnode()
{
	return (nodeptr) malloc(sizeof(struct node));
}

void freenode(nodeptr p)
{
	free(p);
}

void insertatfirst(nodeptr *p,int x)
{
	nodeptr q;
	q=getnode();
	q->info=x;
	q->next=*p;
	*p=q;
}

void displaylist(nodeptr p)
{
	nodeptr ptr=p;
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->info);
		ptr=ptr->next;
	}
}

deletefromfirst (nodeptr *p)
{
	int n;	
	nodeptr q;
	q=*p;
	if(q==NULL)
		{
			printf("Condition of Underflow!\n");
			exit(0);
		}
	else
		{
		n=q->info;
		*p=q->next;
		free(q);
		return (n);
		}
}

int main()
{
	nodeptr list;
	list=NULL;
	insertatfirst(&list,6);
	insertatfirst(&list,5);
	insertatfirst(&list,6);
	deletefromfirst(&list);
	deletefromfirst(&list);
	deletefromfirst(&list);
	deletefromfirst(&list);
	displaylist(list);
}
