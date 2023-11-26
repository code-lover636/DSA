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

void insert(int data, int key){
	struct Node *n = head;
	struct Node *node = malloc(sizeof(struct Node*));
	node -> data = data;
	
	if(n->data == key){
		node->next = head->next;
		head->next = node;
		return;	
	}
	
	while(n->next != NULL){
		n = n->next;
		if(n->data == key){
			node->next = n->next;
			n->next = node;
			return;
		}
	}
	printf("key is not found\n");
}

int print(){
	struct Node *n = head;
	while(n != NULL){
		printf("%d\t", n->data);
		n = n->next;
	}
}

int main() {
	int n, elem, key;

	printf("Enter size of list: ");
	scanf("%d", &n);

	for(int i=0; i<n; i++){
		printf("Enter number: ");
		scanf("%d", &elem);
		add(elem);
	}	
	print();
	printf("\n");
	
	printf("Enter key data: ");
	scanf("%d", &key);
	printf("Enter data to insert: ");
	scanf("%d", &elem);
	insert(elem, key);
	
	print();
	printf("\n");
}
