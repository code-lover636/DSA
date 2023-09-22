/*
2) Find the mean, median and mode of list of elements. Use array to implement the same.(assume Unimode ). Write separate functions.

l=[1,2,3,5,4,5,6,3,1,1]
Mean-3.1
Median-3.0
Mode-1
*/

#include <stdio.h>

// Function to calculate mean
double mean(int arr[], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return (double)sum / n;
}

// Function to calculate median
double median(int arr[], int n) {
    // Sort the array using bubble sort
    int temp;
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    if(n&1) {
        return arr[n / 2];
    } 
    else {
        return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    }
}

// Function to calculate mode
int mode(int arr[], int n) {
    int maxValue = 0, maxCount = 0, i, j;
    for (i = 0; i < n; i++) {
        int count = 0;
        for (j = 0; j < n; j++) {
            if (arr[j] == arr[i])
                count++;
        }
        if (count > maxCount) {
            maxCount = count;
            maxValue = arr[i];
        }
    }
   return maxValue;
}

int main() {
    int n;
    //Reading array
    printf("Enter total number: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0; i<n; i++){
        printf("Enter number: ");
        scanf("%d",&arr[i]);
    }
    // Calculating and displaying
    printf("Mean: %lf\n", mean(arr,n));
    printf("Median: %lf\n", median(arr,n));
    printf("Mode: %d\n", mode(arr,n));
}

/*
Output:
Enter total number: 5
Enter number: 2
Enter number: 2
Enter number: 88
Enter number: 12
Enter number: 22
Mean: 25.200000
Median: 12.000000
Mode: 2
*/
