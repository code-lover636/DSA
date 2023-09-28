/*
 4. Implement Insertion Sort
Sort by repeatedly taking the next item and inserting it into the final data set in its proper order with respect to items already inserted (sorted).

Time complexity: O(n^2)
*/

#include<stdio.h>

void insertionsort(int arr[],int n){
    int i,j,key;
    for(i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j] > key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main() {
    int n;
    printf("Enter size of the array: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter number:");
        scanf("%d",&arr[i]);
    }
    
    insertionsort(arr,n);
    printf("\nSorted array: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}


/*
Output:
Enter size of the array: 5
Enter number:2
Enter number:1
Enter number:3
Enter number:1
Enter number:5
Sorted array: 1 1 2 3 5	
*/
