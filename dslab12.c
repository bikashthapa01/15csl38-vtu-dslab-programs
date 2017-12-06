//HASH TABLE 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HASH_SIZE 5


typedef struct employee{
	int id;
	char name[10];
}EMP;

void init(EMP a[]){
	int i;

	for(i=0;i<HASH_SIZE;i++){
		a[i].id = 0;
	}
}

int H(int k){
	return k%HASH_SIZE;
}

void insert_hash(int id, char name[],EMP a[]){

		int i,hvalue,index;
		hvalue = H(id);
		for(i=0;i<HASH_SIZE;i++){
			index = (hvalue+i)%HASH_SIZE;

			if(a[index].id == 0){
				a[index].id = id;
				strcpy(a[index].name,name);
				break;
			}

		}



}

int search_hash(EMP a[], int key){
	int i,hvalue,index;
	hvalue = H(key);

	for(i=0;i<HASH_SIZE;i++){
		index = (hvalue+i)%HASH_SIZE;
		if(a[index].id == key) return 1;
		if(a[index].id == 0) return 0;
	}


		if(i== HASH_SIZE){
			return 0;
		}


}

void display_table(EMP a[]){
	int i;

	for(i=0;i<HASH_SIZE;i++){
		if(a[i].id != 0)
			printf("id = %d \n Name: %s \n",a[i].id,a[i].name);
	}
}


int main(){
	EMP a[10];
	char name[10];

	int i,key=0,id,ch,n,flag=0;


	while(1){
		printf("\t MENU \n");
		printf("1. 1 Insert \n 2. Search \n 3. Display\n");
		printf("Enter Your Choice:\n");
		scanf("%d",&ch);
		switch(ch){
				case 1: printf("Enter No of Employee ? \n");
				scanf("%d",&n);
				for(i=0;i<n;i++){
						printf("Enter id:\n");
						scanf("%d",&id);
						printf("Enter Name:\n");
						scanf("%s",name);
						insert_hash(id,name,a);
				}
				break;
				case 2: printf("Enter Id to search:\n");
						scanf("%d",&key);
						flag = search_hash(a,key);
						if(flag == 1){
							printf("Employee Found on The Table.\n");

						}else {
							printf("Employee Not Found.\n");
						}
						break;
				case 3: display_table(a);
						break;

				case 4: exit(0);
				// default:printf("Invalid Choice.\n");



		}
	}
}