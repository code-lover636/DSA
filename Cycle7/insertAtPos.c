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

void insert(struct Node *head, int data, int pos){
	struct Node *n = head;
	struct Node *node = malloc(sizeof(struct Node*));
	node -> data = data;
	while(n->next != NULL){
		n = n->next;
		pos--;
		if(!pos){
			node->next = n->next;
			n->next = node;
			return;
		}
	}
	n->next = node;
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
	int n, elem, pos;

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
	scanf("%d", &pos);
	printf("Enter data to insert: ");
	scanf("%d", &elem);
	insert(head, elem, pos-1);
	
	print(head);
	printf("\n");
}
