#include <stdio.h>
#include <stdlib.h>

int a[10][10],n,src,visited1[10]={0},visited2[10]={0};
void create();
void bfs(int src);
void dfs(int src);


int main(){
	int ch,src,i;
	while(1){
		printf("\n\t MENU\n");
		printf("1. Create \n 2. BFS \n 3. DFS \n 4. Exit\n");
		printf("Enter Your Choice:\n");
		scanf("%d",&ch);

		switch(ch){
			case 1: 
				create();
				break;
			case 2: printf("BFS Traversals:\n");
					printf("Enter Source Vertex:\n");
					scanf("%d",&src);
					bfs(src);
					break;
			case 3: printf("DFS Traversal:\n");
					printf("Enter Source Vertex:\n");
					scanf("%d",&src);
					dfs(src);
					for(i=0;i<n;i++){
						if(visited2[i] == 0){
							printf("Graph is Not Connected.\n");
							exit(0);
						}	
					}
					printf("Graph is Connected.\n");
					break;
				case 4: exit(0);
				default:printf("Invalid Choice\n");
		}
	}
}

void create(){
	int i,j;
	printf("Enter No Vertices:\n");
	scanf("%d",&n);
	printf("Enter Adjacency matrix:\n");
	for(i=0;i<n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
}


void bfs(int src){
	int q[10],f=0,r=-1,i,j;
	visited1[src] = 1;
	q[++r] = src;

	printf("Nodes Reachables are:\n");
	while(f<= r){
		i = q[f];
		f++;
		printf("%d \t",i);

		for(j=0;j<n;j++){
			if(a[i][j]==0 && visited1[j]==0){
				visited1[j] = 1;
				q[++r] = j;
			}
		}
	}

	printf("\n Nodes not Reachables are:\n");
	for(i=0;i<n;i++){
		if(visited1[i] == 0){
			printf("%d \t",i);
		}
		visited1[i] = 0;
	}
}

void dfs(int src){
	int j;

		visited2[src] = 1;

		for(j=0;j<n;j++){
				if(a[src][j] == 1 && visited2[j] == 0){
					
					printf("%d -----> %d \n",src,j);
					dfs(j);

				}
		}
}

