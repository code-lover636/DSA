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

int findSmallest(){
	int smallest = head->next->data;
	struct Node *n = head;
	while(n != NULL){
		if(n->data < smallest){
			smallest = n->data;
		}
		n = n->next;
	}
	return smallest;
}

void del(int data){
	struct Node *n = head;
	
	if(n->data == data){
		head = head->next;
		return;	
	}
	
	while(n->next != NULL){
		if(n->next->data==data){
			n->next = n->next->next;
			return;
		}
		n = n->next;
	}
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

	elem = findSmallest();
	del(elem);

	print();
	printf("\n");
}
