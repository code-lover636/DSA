/*
3. Implement Selection Sort
Find the smallest element in the list and place it in the first position. Repeatedly looks through remaining items to find the least one and moves it to its final location.

Time complexity: O(n^2)
*/

#include<stdio.h>

void selectionsort(int a[],int n){
    int i,j,temp,min;
    
    for(i=0;i<n-1;i++){
        min = i;
        for(j=i+1;j<n;j++){
            if(a[j]<a[min])
                min=j;
        }
        if(min!=i){
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;
        }
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
    
    selectionsort(arr,n);
    printf("\nSorted array: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}


/*
Output:
Enter size of the array: 5
Enter number:2
Enter number:3
Enter number:1
Enter number:9
Enter number:6
Sorted array: 1 2 3 6 9 	
*/
