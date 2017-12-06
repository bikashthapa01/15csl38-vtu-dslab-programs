#include <stdio.h>
#include <stdlib.h>
#include <math.h>



void tower(int n, char source, char temp, char dest){

	if(n==0) return;

	tower(n-1,source,dest,temp);
	printf("Moving Disk %d from %c to %c \n",n,source,dest);
	tower(n-1,temp,dest,source);

}

int main(){
	int n;

	printf("Enter No of Disks:\n");
	scanf("%d",&n);
	tower(n, 'A','B','C');
	printf("The Total no. Of Moves is: %d \n", (int)pow(2,n)-1);
}