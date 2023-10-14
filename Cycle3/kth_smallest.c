/*
1.Find the K'th smallest element in the array.
solve this problem efficiently using a sorting algorithm The goal is to find the K'th smallest element without fully sorting the entire array.
*/


#include <stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int low, int high){
	int pivot = arr[high], i = low-1;
	
	for(int j=low; j<high; j++){
		if(arr[j]<=pivot){
			swap(&arr[j], &arr[++i]);
		}
	}
	swap(&arr[high], &arr[i+1]);
	return i+1;
}


int quickSort(int arr[], int low, int high, int k){
	if(low<=high){
		int pivot_index = partition(arr, low, high);
		
		if(pivot_index==k){
			return arr[k];
		}
		else if(pivot_index<k){
			quickSort(arr, pivot_index+1, high, k);
		}
		else{
			quickSort(arr, low, pivot_index-1, k);
		}
	}
}

void main(){
	int size, k;
	
	//Read array
	printf("Enter size of array: ");
	scanf("%d", &size);
	int arr[size];
	for(int i=0; i<size; i++){
		printf("Enter element %d: ", i+1);
		scanf("%d", &arr[i]);
	}	
	
	printf("Enter k to find kth smallest element: ");
	scanf("%d", &k);
	
	if(k<1 || k>size){
		printf("Invalid value for k.\n");
		return;
	}
	
	int smallest = quickSort(arr, 0, size-1, k-1);
	printf("kth(%d) smallest element: %d\n", k, smallest);
}

/*
Output:
Enter size of array: 5
Enter element 1: 1
Enter element 2: 0
Enter element 3: 9
Enter element 4: 5
Enter element 5: 4
Enter k to find kth smallest element: 3
kth(3) smallest element: 4
*/
