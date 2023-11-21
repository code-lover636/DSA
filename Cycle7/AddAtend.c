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

int print(struct Node *head){
	struct Node *n = head;
	while(n->next != NULL){
		n = n->next;
		printf("%d\t", n->data);
	}
}

int main() {
	struct Node *head = malloc(sizeof(struct Node*));
	add(head, 1);
	add(head, 2);
	add(head, 4);
	add(head, 9);
	print(head);
}
