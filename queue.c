#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int arr[SIZE], front, rear, item;

void enqueue(){
	if(rear == SIZE - 1){
		printf("Queue is full\n");
		return;
	}
	else{ 
	if(front == -1)
	front = 0;
	printf("Enter the item to be inserted: ");
	scanf("%d",&item);
	rear++;
	arr[rear] = item;
	}
}

void dequeue(){
	int del_item;
	if(rear == -1){
		printf("Queue is empty\n");
		return;
	}
	else{
	printf("Deleted item is %d",arr[front]);
	front++;
	}
	if(front > rear){
		front = rear = -1;
	}
}

void display(){
	int i;
	if(rear == -1){
		printf("Queue is empty\n");
		return;
		}
	printf("Elements in the queue are: ");
	for(i = front; i <= rear; i++){
		printf("S[%d]:%d\n",i, arr[i]);
	}
}

void main(){
	front = -1;
	rear = -1;
	int ch;
	for(;;){	//infinite loop
		printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : enqueue();
				 break;
			case 2 : dequeue();
				 break;
			case 3 : display();
				 break;
			default : exit(0);
		}//end of switch statement
	}//end of for loop
}//end of main function
