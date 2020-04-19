#include<stdio.h>
#include<stdlib.h>

struct key
{
	int data;
	struct key *next;
};

typedef struct key queue;

queue *s;

void insert(int k);
void print();
void delete();

int main()
{
	int n,k;
	s=NULL;
	while(1)
	{
		printf("Enter '0' for insert:\nEnter '1' for delete:\nEnter '2' for exit:\n");
		printf("Enter a number:\t");
		scanf("%d",&n);

		if(n == 0)
		{
			printf("Enter The Number That you want to enter:\t");
			scanf("%d",&k);
			insert(k);
			print();
		}

		if(n == 1)
		{
			if(s!=NULL)
			{
				delete();
				print();
			}
			else
			{
				printf("The stack is NULL\n");
				exit (0);
			}
		}

		if(n != 0 && n != 1)
			exit (0);
		
	}
}

void insert(int k)
{
	queue *new,*q;
	new=(queue *)malloc(sizeof(queue));
	
	new->data=k;
	new->next=NULL;
	
	if(s == NULL)
		s=new;

	else
	{
		q=s;
		while(q->next!=NULL)
			q=q->next;
		q->next=new;
	}
	
}

void print()
{
	queue *q;
	q=s;
	if(q == NULL)
		printf("The stack is NULL\n");
	else
	{
		printf("The list is given by:\n");
		while(q!=NULL)
		{
			printf("%d\t",q->data);
			q=q->next;
		}
		printf("\n");
	}
}

void delete()
{
	s=s->next;
}
