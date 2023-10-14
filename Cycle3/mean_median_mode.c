/*
3. Find the mean, median, mode, and range of the list of values ( This problem is done in cycle-1)
*/

#include <stdio.h>


// Functions for quick sorting array
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


int quickSort(int arr[], int low, int high){
	if(low<high){
		int pivot_index = partition(arr, low, high);
		
		quickSort(arr, pivot_index+1, high);
		quickSort(arr, low, pivot_index-1);
	}
}

// Functions for mean, median and mode
void mean(int arr[], int n){
	int sum=0;
	for(int i=0; i<n; i++){
		sum+=arr[i];
	}
	printf("Mean = %lf\n", (double)sum/n);
}

void median(int arr[], int n){
	quickSort(arr, 0, n-1);
	
	if(n&1){
		printf("Median = %d\n", arr[n/2]);
	}
	else{
		printf("Median = %lf\n", (double) (arr[n/2]+arr[n/2 -1] )/2);
	}
}

void mode(int arr[], int n){
	int arr2[n], count=1, maxCount=1, k=0, low=0;
	
	for(int i=0; i<n-1; i++){
		if(arr[i]==arr[i+1]){
			count++;
		}
		else if(maxCount<count){
			maxCount = count;
			count = 1;
			low=k;
			arr2[k++] = arr[i];
		}
		else if(maxCount==count){
			arr2[k++] = arr[i];
			count = 1;
		}
	}
	
	if(maxCount < count){
        printf("Mode = %d", arr[n-1]);
    }
    else{
        if(maxCount == count)
            arr2[k++] = arr[n-1];
        
        printf("Mode = ");
	    for(int i=low; i<k; i++)
			printf("%d ", arr2[i]);
    } 

	printf("\n");
}

void main(){
	int size, k, count=1;
	
	//Read array
	printf("Enter size of array: ");
	scanf("%d", &size);
	int arr[size];
	for(int i=0; i<size; i++){
		printf("Enter element %d: ", i+1);
		scanf("%d", &arr[i]);
	}	
	
	mean(arr, size);
	median(arr, size);
	mode(arr, size);
}

/*
Output:
Enter size of array: 5
Enter element 1: 1
Enter element 2: 2
Enter element 3: 2
Enter element 4: 3
Enter element 5: 3
Mean = 2.200000
Median = 2
Mode = 2 3 
*/

