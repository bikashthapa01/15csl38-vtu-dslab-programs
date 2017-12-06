#stack operation

//palindrome


for(i=0;i<=top-1;i++){
	if(s[top] == s[top-i]){
		status = 1;
		break;
	}
}

if(status == 0){
	printf("Stack is not a palindrome.\n");
}else {
	printf("Stack is palindrome.\n");
}