/*
6.Given a list of non-negative integers, arrange them to form the largest number.
*/

#include <stdio.h>
#include <string.h>

int main(){
	int size;
	
	//Read array
	printf("Enter size of array: ");
	scanf("%d", &size);
	char arr[size][1000];
	for(int i=0; i<size; i++){
		printf("Enter element %d: ", i+1);
		scanf(" %[^\n]", &arr[i]);
	}
	
	
	for(int i=0; i<size-1; i++){
		for(int j=0; j<size-i-1; j++){
			if(strcmp(arr[j],arr[j+1])<0){
				char temp[100];
				strcpy(temp, arr[j]);
				strcpy(arr[j], arr[j+1]);
				strcpy(arr[j+1], temp);
			}
		}
	}
	
	printf("Largest number: ");
	for(int i=0; i<size; i++){
		printf("%s", arr[i]);
	}
	
}
/*
Output:
Enter size of array: 5
Enter element 1: 2
Enter element 2: 32
Enter element 3: 9
Enter element 4: 0
Enter element 5: 22
Largest number: 9322220
*/
