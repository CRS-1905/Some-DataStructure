#include<stdio.h>
#include<stdlib.h>

struct key
{
	int data;
	struct key *next;
};

typedef struct key stack;

stack *s;

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
	stack *new;
	new=(stack *)malloc(sizeof(stack));
	
	new->data=k;
	new->next=s;
	s=new;

}

void print()
{
	stack *q;
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
