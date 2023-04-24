#include<stdio.h>
#include<stdlib.h>
//#include<alloc.h>

//creating a structure node

struct node
{
	int info;
	struct node *link;
};

typedef struct node* NODE;

NODE getnode()
{
	NODE new;
	new = (NODE)malloc(sizeof(struct node));
	if(new == NULL)
	{
		printf("Out of Memory\n");
		exit(0);
	}
	return new;
}

//C function to insert a node at first
NODE insert_first(int item, NODE first)
{
	NODE temp;
	temp = getnode();
	temp->info = item;
	temp->link = first;
	return temp;
}

//C function to display exixting SLL

void display(NODE first)
{
	NODE temp;
	if(first == NULL)
	{
		printf("List is Empty\n");
		return;
	}
	else
	{
		temp = first;
		while(temp != NULL)
		{
			printf("%d\t %p\n",temp->info, temp->link);
			temp = temp->link;
		}
	}
}

//C function to add a new node at the rear end

NODE insert_rear(int item, NODE first)
{
	NODE temp, cur;
	temp = getnode();
	temp->info = item;
	temp->link = NULL;
	if(first == NULL)
	{
		return first;
	}
	cur = first;
	while(cur->link != NULL)
	{
		cur = cur->link;
	}
	cur->link = temp;
	return first;
}

//C function to delete node at first

NODE delete_front(NODE first)
{
	NODE temp;
	if(first == NULL)
	{
		printf("List is empty\n");
		return first;
	}
	else
	{
		temp = first;
		temp = temp->link;
		printf("deleted item is %d\n",first->info);
		free(first);
		return temp;
	}
}

//C function to delete a existing node at the rear end

NODE delete_rear(NODE first)
{
	NODE cur, prev;
	if(first == NULL)
	{
		printf("list is empty\n");
		return first;
	}
	if(first->link == NULL)//deleting very first node
	{
		printf("deleted item is %d\n",first->info);
		free(first);
		return NULL;
	}
	prev = NULL;
	cur = first;
	while(cur->link != NULL)
	{
		prev = cur;
		cur = cur->link;
	}
	printf("deleted item is %d\n",cur->info);
	free(cur);
	prev->link = NULL;
	return first;
}

//C function to show all the basic operation

void main()
{
	NODE first = NULL;
	int ch, item;
	for(;;)
	{
		printf("SINGLE LINKED OPERATIONS\n");
		printf("1.INSERT_FRONT\n2.INSERT_REAR\n3.DELETE_FRONT\n4.DELETE_REAR\n5.DISPLAY\n6.EXIT\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : printf("Enter the item to be inserted: ");
				 scanf("%d",&item);
				 first = insert_first(item, first);
				 break;
			case 2 : printf("Enter the item to be inserted: ");
				 scanf("%d",&item);
				 first = insert_rear(item, first);
				 break;
			case 3 : first = delete_front(first);
				 break;
			case 4 : first = delete_rear(first);
				 break;
			case 5 : display(first);
				 break;
			default : exit(0);
		}
	}
}
