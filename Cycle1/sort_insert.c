/*
5)Mark of the students in an exam are stored in an integer array marks.Sort the marks in descending order using bubble sort. Implement a function insert(int m) that inserts the given mark m  into the marks  array. The inserted value should maintain a sorted order in the collection.
( understand the complexities involved)
*/

#include <stdio.h>

void display(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("%d\t", arr[i]);
    } 
    printf("\n");
}

void sort(int arr[], int n){
    int temp;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]<arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void insert(int arr[], int n, int m){
    int j;
    for(int i=0; i<n; i++){
        if(arr[i]<m){
            for(j=n; j>i; j--){
                arr[j]=arr[j-1];
            }
            arr[j] = m;
            break;
        }
    }
}

int main(){ 
    //Reading array and other inputs
    int n, m;
    printf("Enter total number: ");
    scanf("%d",&n);
    int arr[n+1];
    for(int i=0; i<n; i++){
        printf("Enter number: ");
        scanf("%d",&arr[i]);
    }
    
    // Sorting
    sort(arr,n);
    printf("Sorted array: ");
    display(arr,n);
    
    // Inserting
    printf("Enter number to insert: ");
    scanf("%d",&m);
    insert(arr,n,m);
    printf("Array after inserting %d: ",m);
    display(arr,n+1);
}

/*
Output:
Enter total number: 5
Enter number: 1
Enter number: 3
Enter number: 2
Enter number: 5
Enter number: 6
Sorted array: 6	5	3	2	1	
Enter number to insert: 4
Array after inserting 4: 6	5	4	3	2	1	
*/
