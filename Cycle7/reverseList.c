#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};
struct Node *head = NULL;

int add(int data){
	struct Node *n = head;
	struct Node *node = malloc(sizeof(struct Node*));
	node -> data = data;
	
	if(head==NULL){
		head = node;
	}
	else{
		while(n->next != NULL){
			n = n->next;
		}
		n->next = node;
	}
}

int reverse(){
	struct Node *n = head;
	struct Node *prev = NULL;
	struct Node *next = NULL;
	while(n!= NULL){
		next = n->next;
		n->next = prev;
		prev = n;
		n = next;
	}
	head = prev;
}

int print(){
	struct Node *n = head;
	while(n != NULL){
		printf("%d\t", n->data);
		n = n->next;
	}
}

int main() {
	int n, elem;

	printf("Enter size of list: ");
	scanf("%d", &n);

	for(int i=0; i<n; i++){
		printf("Enter number: ");
		scanf("%d", &elem);
		add(elem);
	}	
	print();
	printf("\n");

	reverse();

	print();
	printf("\n");
}
