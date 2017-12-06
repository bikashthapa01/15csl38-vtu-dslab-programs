//singly linked list

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	char name[20],usn[10],branch[10],phone[20];
	int sem;
	struct node *link;

};

typedef struct node *NODE;
NODE first = NULL;

NODE getNode(){
	NODE x;

	x = (NODE)malloc(sizeof(struct node));
	if(x==NULL){
		printf("Not Enough Memory is available.\n");
		exit(0);
	}

	return x;
}




// Following operation can be performed is sll
// 1. Insert / delete at front / rear 
// 2. display



NODE createStudentNode(){
	

	NODE temp;
	temp = getNode();

	char name[20],usn[10],phone[20],branch[10];
	int sem;

	//getting student infos

	printf("Enter Name:\n");
	//gets(name);
	scanf("%s",name);
	printf("Enter USN:\n");
	//gets(usn);
	scanf("%s",usn);
	printf("Enter Branch:\n");
	// gets(branch);
	scanf("%s",branch);
	printf("Enter Sem.\n");
	scanf("%d",&sem);
	printf("Enter Phone No.\n");
	// gets(phone);
	scanf("%s",phone);


	//copying data to node

	strcpy(temp->name,name);
	strcpy(temp->usn, usn);
	strcpy(temp->branch,branch);
	temp->sem  = sem; 
	strcpy(temp->phone,phone);

	return temp;
}
NODE insertAtFront(){

	NODE temp;
	temp = createStudentNode();

	if(first==NULL){
		
		return temp;

	}

	temp->link = first;

	return temp;

}

NODE deleteAtFront(){
	NODE cur;

	if(first == NULL){
		printf("List is Empty.\n");
		return first;
	}

	if(first->link == NULL){
		printf("The Studnet With usn %s is deleted.\n",first->usn);
		free(first);
		return NULL; //???
	}

	cur = first;
	first = first->link;

	printf("The student with usn %s is deleted.\n",first->usn);
	free(cur);

	return first;


}

NODE insertAtRear(){
	NODE temp,cur;
	temp = createStudentNode();

	if(first==NULL){
		
		return temp;

	}

	cur = first;

	while(cur->link != NULL){
		cur = cur -> link;
	}

	cur->link = temp;
	temp->link = NULL;

	return first;

}

NODE deleteAtRear(){
	NODE cur,prev;
	if(first == NULL){
		printf("List is Emplty as F***.\n");
		return NULL;
	}

	if(first->link == NULL){ // If True Contains ony one node
		printf("Student with usn %d is deleted.\n",first->usn);
		free(first);
		return NULL; 
	}

	cur = first->link;
	prev = NULL;

	while( cur != NULL){

			prev = cur;
			cur = cur->link;
	}

	prev->link = NULL;
	printf("Studnet with USN %s is deleted.\n",cur->usn);
	return first;
}

void display(){
		NODE cur;
int count = 1;
		if(first == NULL){
			printf("Nothing Exists.\n");
			return;
		}

		cur = first;
		printf("Content of SLL are: \n");
		while(cur != NULL){
			
			//printf("\n Name: %s \t USN: %s \t Branch: %s \t Semester: %d \t Phone no.: %s \n",cur->name,cur->usn,cur->branch,cur->sem,cur->phone);
			cur = cur->link;
		}

		printf("Total Number of Node is: %d \n",count);
}

// stack demo

void stack(){
	int ch,n;
	while(1){

		printf("\t Stack Demo using SLL\n");
		printf("1. push \n 2. pop 3. display \n 4.exit\n");
		printf("Enter Your Choice:\n");
		scanf("%d",&ch);

		switch(ch){
			case 1:  first = insertAtFront();
					break;
			case 2: first = deleteAtRear();
					break;
			case 3: display();
					break;
			case 4: return;
			default:printf("Invalid Choice.\n");;
		}
	}
}

int main(){
	int ch,n,i;

	while(1){
		printf("\t MENU \n");
		printf("1. Insert At Front \n 2. Insert at Rear \n 3. Delete at Front \n 4.Delete at rear \n 5. Display \n 6.Stack demo \n 7. Exit\n");
		printf("Enter Your Choice;\n");
		scanf("%d",&ch);

		switch(ch){
				case 1: printf("Enter No of student:\n");
						scanf("%d",&n);
						for(i=0;i<n;i++){
							first = insertAtFront();
						}
						break;
				case 2: printf("Enter No of student:\n");
						scanf("%d",&n);
						for(i=0;i<n;i++){
							first = insertAtRear();
						}
						break;
				case 3: first = deleteAtFront(); break;
				case 4: first = deleteAtRear(); break;
				case 5: display(); break;
				case 6: stack(); break;
				case 7: exit(0);
				default:printf("invalid Choice.\n");
		}
	}

	return 0;
}