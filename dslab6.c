//Cricular Queue
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int item,q[20],i,rear=-1,front=0,count=0;

void insert(){
	if(count == SIZE ){
		printf("Circular Queue Overflow.\n");
		return;
	}
	printf("Enter item to insert:\n");
	scanf("%d",&item);
	rear = (rear+1)%SIZE;
	q[rear] = item;
	count++;

}

void delete(){
	if(count == 0){
		printf("Queue Underflow.\n");
		return;		
	}
	item = q[front];
	front = (front+1)%SIZE;
	count--;
	printf("The Deleted Item is: %d\n",item);
}

void display(){
	int f;
	if(count == 0){
		printf("The Queue is empty.\n");
		return;
	}

	printf("The Content of the Queue are:\n");
	f = front;
	for(i=0;i<=rear;i++){
		printf("%d\t",q[f]);
		f = (f+1)%SIZE;
	}
printf("\n");

}

int main(){
	int ch;
	while(1){
		printf("\t MENU\n");
		printf("1. insert \n 2. Delete \n 3. display \n 4. exit \n");
		printf("Enter your choice:\n");
		scanf("%d",&ch);
		switch(ch){
				case 1: insert(); break;
				case 2: delete(); break;
				case 3: display(); break;
				case 4: exit(0);
				default:printf("Enter valid choice:\n");
		}
	}

	return 0;
}