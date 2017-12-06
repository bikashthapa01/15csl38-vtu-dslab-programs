#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node {
	int coef,px,py,pz,flag;
	struct node *link;
};

typedef struct node *NODE;

NODE read_poly(NODE head);
NODE insert_rear(int coef,int px,int py, int pz,NODE head);
NODE add_poly(NODE head1,NODE head2, NODE head3);
void evaluate(NODE head);
void display(NODE head);

NODE getnode(){
	NODE x;
	x = (NODE)malloc(sizeof(struct node));
	if(x==NULL){
		printf("Out of Memory.\n");
	}
	return x;
}

NODE read_poly(NODE head){
	int coef,px,py,pz;
	char ch;
	do{
		printf("Enter Coefficient:\n");
		scanf("%d",&coef);

		printf("Enter Power of X:\n");
		scanf("%d",&px);

		printf("Enter Power of Y:\n");
		scanf("%d",&py);

		printf("Enter Power of Z:\n");
		scanf("%d",&pz);
		head = insert_rear(coef,px,py,pz,head);
		printf("Do you want to Add more terms ? y/n :\n");
		scanf(" %c",&ch);

	}while(ch !='n');

	return head;


}

NODE insert_rear(int coef,int px,int py, int pz,NODE head){
	NODE temp,cur;
	temp = getnode();

	temp->coef = coef;
	temp->px = px;
	temp->py = py;
	temp->pz = pz;
	temp->link = NULL;

	cur = head->link;
	while(cur->link != head){
		cur = cur->link;
	}

	cur->link = temp;
	temp->link = head;

	return head;
}


NODE add_poly(NODE head1,NODE head2, NODE head3){
	int coef,coef1,coef2,x1,x2,y1,y2,z1,z2;
	NODE temp1,temp2;

	temp1 = head1->link;
	while(temp1 != head1){
			x1 = temp1->px;
			y1 = temp1->py;
			z1 = temp1->pz;
			coef1 = temp1->coef;

			temp2 = head2 -> link;

			while(temp2 != head2){

				x2 = temp2->px;
				y2 = temp2->py;
				z2 = temp2->pz;
				coef2 = temp2->coef;

				if(x1==x2 && y1==y2 && z1 == z2) break;

				temp2 = temp2->link;
			}

			if(temp2 != head2){
				coef = coef1+coef2;
				temp2->flag = 1;

				if(coef != 0){
					 head3 = insert_rear(coef,x1,y1,z1,head3);
					}
			}else 
					head3 = insert_rear(coef1,x1,y1,z1,head3);
					temp1 = temp1->link;
		}

		temp2 =  head2 -> link;
		while(temp2 != head2){
			if(temp2->flag == 0){
				head3 = insert_rear(temp2->coef,temp2->px,temp2->py,temp2->pz,head3);
			}

			temp2 = temp2->link;
		}

		return head3;
}


void evaluate(NODE head){
	int x,y,z;
	NODE temp;
	double results = 0;

	printf("Enter Values of X, Y, Z :\n");
	scanf("%d%d%d",&x,&y,&z);

	temp = head->link;
	while(temp != head){
		results = results + (temp->coef * pow(x,temp->px)*pow(y,temp->py)*pow(z,temp->pz));
		temp = temp->link;
	}

	printf("Polyomial Results is: %f\n",results);

}

void display(NODE head){
	NODE temp;

	if(head->link  == head){
		printf("Nothing to show.\n");
	}else {
		temp = head->link;
		while(temp != head){
			printf("%dx^%dy^%dz^%d",temp->coef,temp->px,temp->py,temp->pz);
			if(temp->link != head){
				printf("+");
			}
			temp = temp->link;
		}

		printf("\n");
	}
}

int main(){
	NODE head,head1,head2,head3;
	int ch;
	head = getnode();
	head1 = getnode();
	head2 = getnode();
	head3 = getnode();

	head->link = head;
	head1->link = head1;
	head2->link = head2;
	head3->link = head3;

	while(1){
		printf("\t MENU\n");
		printf("1. Evaluate Polynomial.\n 2. Add Two polynomials \n 3. exits \n");
		printf("Enter Your Choice:\n");
		scanf("%d",&ch);

		switch(ch){
				case 1: 
					printf("Enter Polynomial to Evaluate:\n");
					head = read_poly(head);
					display(head);
					evaluate(head);
					break;
				case  2: 
						printf("Enter First Polynomial:\n");
						head1 = read_poly(head1);
						printf("Enter Second Polynomial:\n");
						head2 = read_poly(head2);
						head3 = add_poly(head1,head2,head3);
						printf("First Polynomial is:\n");
						display(head1);
						printf("Second Polynomial is:\n");
						display(head2);
						printf("Sum of Two polynomials is:\n");
						display(head3);
						break;
					case 3: exit(0);
					default:printf("Enter Valid Choice.\n");
		}
	}



return 0;
}