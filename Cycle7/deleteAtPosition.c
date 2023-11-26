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


void del(int pos){
	struct Node *n = head;
	if(!pos){
		head = head->next;
		return;	
	}
	
	while(n->next != NULL){
		pos--;
		if(!pos){
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

	printf("Enter position: ");
	scanf("%d", &elem);
	del(elem-1);

	print();
	printf("\n");
}
