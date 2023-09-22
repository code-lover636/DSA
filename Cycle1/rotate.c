/*
1) Write a function rotate(int a[],int n,char d,int cr) to rotate given array elements.

The function will take the array, number of elements in the array, direction of rotation(l-left r-right) and count of rotation( how many times to rotate)
Eg:
input array a[]=2 3 4 5 6 7
rotate(a,6,l,2)
output:4 5 6 7 2 3
rotate(a,6,r,2)
output:6 7 2 3 4 5
*/


#include <stdio.h> 

// Function for rotating the elements of array
void rotate(int a[],int n,char d,int cr){
    int i, j, temp;
    if(d=='l'||d=='L'){
        for(i=0; i<cr; i++){
            temp = a[0];
            for(j=0; j<n-1; j++){
                a[j]=a[j+1]; 
            } 
            a[n-1]=temp; 
        } 
    } 
    else if(d=='r'||d=='R'){
        for(i=0; i<cr; i++){
            temp = a[n-1];
            for(j=n-1; j>0; j--){
                a[j]=a[j-1]; } a[0] = temp; 
        } 
    } 
    else{ 
        printf("Enter l/r for rotation."); 
    } 
} 

int main(){ 
    //Reading array and other inputs
    int n, cr; 
    char d;
    printf("Enter total number: ");
    scanf("%d",&n); int arr[n];
    
    for(int i=0; i<n; i++){
        printf("Enter number: ");
        scanf("%d",&arr[i]); 
    } 
    printf("Enter direction: ");
    scanf(" %c",&d);
    printf("Enter count of rotation: ");
    scanf("%d",&cr);

    rotate(arr,n,d,cr);
    
    //Displaying output 
    for(int i=0; i<n; i++){
        printf("%d\t", arr[i]);
    } 
    printf("\n");
}

/*
Output:
Enter total number: 5
Enter number: 1
Enter number: 2
Enter number: 3
Enter number: 4
Enter number: 5
Enter direction: l
Enter count of rotation: 2
3	4	5	1	2
*/
