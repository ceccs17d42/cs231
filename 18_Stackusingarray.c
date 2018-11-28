/*
 * 18
 * Stack using array
 * Name: Ritty Thomas
 * Roll no: 42
 */
 #include <stdio.h>
int stack[100], n=100, top;

int push(int data) {
	if (top >= n-1) {
		printf("Stack overflow\n");
		return 0;
	} else {
		stack[++top] = data;
		return 1;
	}
}
int pop() {
	if (top == -1) {
		printf("Stack underflow\n");
		return 0;
	} else {
		printf("Popped element is %d\n", stack[top]);
		top--;
		return 1;
	}
}
int display() {
	int i;
	printf("\n\nStack contents\n");
	if (top == -1) {
		printf("Empty stack\n");
	} else {
		for (i=top; i>=0; i--) {
			printf("%d\n", stack[i]);
		}
	}
	printf("\n");
}
int main() {
	top = -1;
	char ans;
	int data;
	do {
		printf("\n\n\tStack Using array\n");
		printf("1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice : ");
		scanf(" %c", &ans);
		switch (ans) {
			case '1':
				printf("Enter data to be pushed : ");
				scanf(" %d", &data);
				push(data);
				break;
			case '2':
				pop();
				break;
			case '3':
				display();
				break;
			default:
				printf("Invalid choice.\n");
		}
	} while (ans != '4');
}

OUTPUT:

	Stack Using array
1. Push
2. Pop
3. Display
4. Exit
Enter your choice : Enter data to be pushed : 

	Stack Using array
1. Push
2. Pop
3. Display
4. Exit
Enter your choice : Enter data to be pushed : 

	Stack Using array
1. Push
2. Pop
3. Display
4. Exit
Enter your choice : Enter data to be pushed : 

	Stack Using array
1. Push
2. Pop
3. Display
4. Exit
Enter your choice : 

Stack contents
2
9
8



	Stack Using array
1. Push
2. Pop
3. Display
4. Exit
Enter your choice : Popped element is 2


	Stack Using array
1. Push
2. Pop
3. Display
4. Exit
Enter your choice : Popped element is 9


	Stack Using array
1. Push
2. Pop
3. Display
4. Exit
Enter your choice : Popped element is 8


	Stack Using array
1. Push
2. Pop
3. Display
4. Exit
Enter your choice : Stack underflow
