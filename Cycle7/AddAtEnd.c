#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};
struct Node *head = NULL;

struct Node* add(int data){
    struct Node *n = head;
    struct Node *node = malloc(sizeof(struct Node));
    if(node == NULL){
        printf("memory allocation failed");
        exit(EXIT_FAILURE);
    }

    node->data = data;
    node->next = NULL;

    if(head == NULL){
        head = node;
    }
    else{
        while(n->next != NULL){
            n = n->next;
        }
        n->next = node;
    }

    return head;
}


int print() {
    struct Node *n = head;
    while (n != NULL) {
        printf("%d\t", n->data);
        n = n->next;
    }
    return 0;
}

void main() {
    int n, elem;
    struct Node *current_head = NULL;

    printf("Enter size of list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter number: ");
        scanf("%d", &elem);
        current_head = add(elem);
    }

    head = current_head;  // Update the head after adding all elements

    print();
    printf("\n");

}
