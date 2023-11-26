#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};


int add(struct Node *head, int data){
	struct Node *n = head;
	struct Node *node = malloc(sizeof(struct Node*));
	node -> data = data;
	while(n->next != NULL){
		n = n->next;
	}
	n->next = node;
}

void del(struct Node *head, int pos){
	struct Node *n = head;
	while(n->next != NULL){
		if(!pos){
			n->next = n->next->next;
			return;
		}
		pos--;
		n = n->next;
	}
}

int print(struct Node *head){
	struct Node *n = head;
	while(n->next != NULL){
		n = n->next;
		printf("%d\t", n->data);
	}
}

int main() {
	struct Node *head = malloc(sizeof(struct Node*));
	int n, elem;

	printf("Enter size of list: ");
	scanf("%d", &n);

	for(int i=0; i<n; i++){
		printf("Enter number: ");
		scanf("%d", &elem);
		add(head, elem);
	}	
	print(head);
	printf("\n");

	printf("Enter position: ");
	scanf("%d", &elem);
	del(head, elem-1);

	print(head);
	printf("\n");
}