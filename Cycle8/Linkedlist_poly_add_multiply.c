#include <stdio.h>
#include <stdlib.h>

struct Node{
	int coeff;
	int exp;
	struct Node *next;
} *head1=NULL, *head2=NULL, *head3=NULL;

void add(){
	if(head1==NULL && head2==NULL){
		printf("No terms in polynomials.\n");
		return;
	}
	struct Node *n1 = head1;
	struct Node *n2 = head2;
	while(n1 != NULL && n2 != NULL){
		if(n1->exp == n2->exp){
			printf("%dX^%d + ", n1->coeff + n2->coeff, n1->exp);
			n1 = n1->next;
			n2 = n2->next;
		}
		else if(n1->exp<n2->exp){
			printf("%dX^%d + ", n1->coeff, n1->exp);
			n1 = n1->next;
		}
		else{
			printf("%dX^%d + ", n2->coeff, n2->exp);
			n2 = n2->next;
		}
	}
	
	while(n1 != NULL){
			printf("%dX^%d + ", n1->coeff, n1->exp);
			n1 = n1->next;
	}
	while(n2 != NULL){
			printf("%dX^%d + ", n2->coeff, n2->exp);
			n2 = n2->next;
	}
	printf("\n");
}

void insert(struct Node **head, int c, int e){
	struct Node *node = malloc(sizeof(struct Node*));
	node->coeff = c;
	node->exp = e;
	node->next = NULL;
	if(*head == NULL){
		*head = node;
		printf("\nTerm added.\n");
		return;
	}

	struct Node *n = *head;
	while(n->next && n->next->exp < e){
		n = n->next;
	}
	if((*head)->exp < e){
		node->next = n->next;
		n->next = node;
	}
	else{
		node->next = *head;
		*head = node;
	}

	printf("\nTerm added.\n");
}

void print(struct Node **head){
	struct Node *n = *head;
	while(n){
		if(n->coeff != 0){
			printf("%dx^%d", n->coeff, n->exp);
			if(n->next){
				printf(" + ");
			}
		}
		n=n->next;
	}
	printf("\n");
}

void multiply(){
	if(head1==NULL && head2==NULL){
		printf("No terms in polynomials.\n");
		return;
	}
	struct Node *n1 = head1;
	struct Node *n2 = head2;
	while(n1 != NULL){
		n2 = head2;
		while(n2 != NULL){
			insert(&(head3), n1->coeff*n2->coeff, n1->exp+n2->exp);
			n2 = n2->next;
		}
		n1 = n1->next;
	}
	n1=head3;
	n2=head3;
	while(n1 != NULL){
		n2 = head3;
		while(n2 != NULL){
			if(n1->exp==n2->exp && n1!=n2){
				n1->coeff =  n1->coeff+n2->coeff;
				n2->coeff = 0;
			}
			n2 = n2->next;
		}
		n1 = n1->next;
	}
	print(&head3);
}

int main(){
	printf("<<< Polynomial >>>\n");
	int running = 1, choice, c, e;
	while(running){
		printf("1. Insert Term to polynomial1\n");
		printf("2. Insert Term to polynomial2\n");
		printf("3. Add polynomials\n");
		printf("4. Multiply polynomials\n");
		printf("5. Display polynomials\n");
		printf("6. Exit\n");
		printf("\n\nEnter choice: ");
		
		int n = scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter coefficient: ");
				n=scanf("%d",&c);
				printf("Enter exponent: ");
				n=scanf("%d",&e);
				insert(&(head1), c, e);
				break;
			case 2:
				printf("Enter coefficient: ");
				n=scanf("%d",&c);
				printf("Enter exponent: ");
				n=scanf("%d",&e);
				insert(&(head2), c, e);
				break;
			case 3:
				add();
				break;
			case 4:
				multiply();
				break;
			case 5:
				print(&(head1));
				print(&(head2));
				break;
			default:
				printf("Exiting...\n");
				running = 0;
				break;
		}
	}
}
