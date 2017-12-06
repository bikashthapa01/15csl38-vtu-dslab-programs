#include <stdio.h>
#include <stdlib.h>

char STR[100],PAT[100],REP[100],ans[100];
int i=0,j=0,k=0,c=0,m=0,flag=0;


int main(){
printf("Enter Main String:\n");
gets(STR);

printf("Enter PAT String:\n");
gets(PAT);

printf("Enter Rep String\n");
gets(REP);


while(STR[c] != '\0'){


		if(STR[m] == PAT[i]){
			
			i++;
			m++;

				if(PAT[i] == '\0'){
					flag = 1;

					for(k=0; REP[k] !='\0';k++,j++)
						ans[j] = REP[k];
						i=0;
						c=m;
				}

		} else {
			ans[j] = STR[c];
			j++;
			c++;
			m=c;
			i=0;	
		}
}

if(flag == 0){
	printf("Pattern not Found.\n");
}else {
	ans[j] = '\0';
	printf("The Result after operation is: %s ",ans);
}
return 0;
}
