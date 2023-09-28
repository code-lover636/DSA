/*
1. Implement Linear Search
Search an array or list by checking items one at a time.
Time complexity ……………O(n)
*/

#include <stdio.h>

void linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            printf("Element is found at index %d.\n", i);
            return;
        }
    }
    printf("Element is not found in the array.\n");
    return;
}

int main(){
    int n, i, target, result;
    // Read array
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    for(i=0; i<n; i++){
        printf("Enter number: ");
        scanf("%d", &arr[i]);
    }
    // Input search key
    printf("\nEnter the element to search: ");
    scanf("%d", &target);
    
    linearSearch(arr, n, target);
}

/*
Output:
Enter size of array: 5
Enter number: 1
Enter number: 2
Enter number: 3
Enter number: 6
Enter number: 7
Enter the element to search: 3
Element is found at index 2.
*/
