/*
6.Find all local maximums of an array of unique elements. An element is considered to be local max if it is greater than the nearby elements

Eg; [ 3 2 5 7 8 1 6 9]

Here 8 and 9 are local maximums
*/

#include <stdio.h>

void findLocalMaximums(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        if(i==0){
            if((arr[i]>arr[size-1]) && (arr[i]>arr[i+1]))
                printf("%d is a local maximum.\n", arr[i]);
        }
        else if(i==size-1){
            if((arr[i]>arr[0]) && (arr[i]>arr[i-1]))
                printf("%d is a local maximum.\n", arr[i]);
        }
        else if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
            printf("%d is a local maximum.\n", arr[i]);
        }
    }
}

int main() {
    int n; 
    //Creating array
    printf("Enter total number of elements in the array: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0; i<n; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d",&arr[i]); 
    } 
    findLocalMaximums(arr, n);
}

/*
Output:
Enter total number of elements in the array: 8
Enter element 1: 3
Enter element 2: 2
Enter element 3: 5
Enter element 4: 7
Enter element 5: 8
Enter element 6: 1
Enter element 7: 6
Enter element 8: 9
8 is a local maximum.
9 is a local maximum.
*/
