#include <stdio.h>
#include <stdlib.h>
		
struct node {
	int info;
	struct node *rlink;
	struct node *llink;
};

typedef struct node *NODE;

//create node

NODE create(NODE root){
	NODE temp,cur,prev;
	int item,i,n;

	printf("Enter no of Nodes:\n");
	scanf("%d",&n);

	for(i=0;i<n;i++){
			printf("Enter Node item to insert:\n");
			scanf("%d",&item);

			temp = (NODE)malloc(sizeof(struct node));
			temp->rlink = NULL;
			temp->llink = NULL;

			temp->info = item;

			if(root == NULL){
				root = temp;
			}else {
				cur = root;
				prev = NULL;

				while(cur != NULL){
					prev = cur;
						if(item < cur->info){
								cur = cur -> llink;
						}else if(item > cur->info){
								cur = cur->rlink;
						}
				}

				if(item < prev -> info){
					prev -> llink = temp;
				}else if(item > prev -> info){
					prev -> rlink = temp;
				}
			}
	}

	return root;

}

void preorder(NODE root){
	if(root == NULL) return;

	printf("%d \n",root->info);
	preorder(root->llink);
	preorder(root->rlink);

}

void inorder(NODE root){
	if(root == NULL) return;
	inorder(root->llink);
	printf("%d \n",root->info);
	inorder(root->rlink);

}
void postorder(NODE root){
	if(root == NULL) return;
	postorder(root->llink);
	postorder(root->rlink);
	printf("%d\n",root->info);
}

NODE search(NODE root){
	NODE cur;
	int key;

	if(root == NULL){
		printf("Tree is Empty.\n");
		return root;
	} else {

	printf("Enter Key to search:\n");
	scanf("%d",&key);

	cur = root;

	while(cur != NULL){

		if(key == cur->info) break;
		if(key < cur->info) cur = cur -> llink;
		if(key > cur->info) cur = cur -> rlink;
	}

	if(cur == NULL){
		printf("Note Found.\n");
	}else {
		printf("Yes. Item Found.\n");
	}

	}

	return root;
}

NODE delete_item(NODE root){
	int key;
	NODE cur,parent,suc,q;

	if(root == NULL){
		printf("Tree is Empty.\n");
		return root;
	}

	parent = NULL;
	cur = root;
	printf("Enter Elements to delete from tree:\n");
	scanf("%d",&key);

	while(cur != NULL){
			if(key == cur -> info) break;
			parent = cur;
			if(key < cur -> info) cur = cur -> llink;
			if(key > cur -> info) cur = cur -> rlink;

	}

	if(cur == NULL){
		printf("Key Not Found.\n");
		return root;
	}


	if(cur -> rlink == NULL){
			q = cur->llink;
	}else if(cur->llink == NULL){
			q = cur->rlink;
	}else {
		suc = cur->rlink;
		while(suc->llink != NULL){
			suc = suc->llink;
		}

		suc -> llink = cur->llink;
		q = cur -> llink;
	}

	if(parent == NULL){
		return q;
	}

	if(cur == parent->llink){
		parent->llink = q;
	}else {
		parent->rlink = q;
	}

	free(cur);

	return root;

}


int main(){
	int ch;
	NODE root = NULL;
	printf("Binary Search Tree:\n");
	while(1){
		int ch;
		printf("1. Create \n 2. Preorder \n 3. Inorder \n 4. Postorder \n 5. search \n 6. delete \n 7. exit\n");
		printf("Enter Your Choice.\n");
		scanf("%d",&ch);
		switch(ch){
			case 1: root = create(root);
					break;
			case 2: if(root == NULL){
							printf("Tree is Empty.\n");
						}else {
							preorder(root);
						}
					break;
			case 3 : if(root == NULL){
							printf("Tree is Empty.\n");
						}else {
							inorder(root);
						}
					break;

			case 4: if(root == NULL){
							printf("Tree is Empty.\n");
						}else {
							postorder(root);
						}
					break;
			case 5: search(root);
					break;
			case 6: delete_item(root);
					break;
			case 7: exit(0);
			default:printf("Invalid Choice.\n");

		}
	}
	return 0;

}

