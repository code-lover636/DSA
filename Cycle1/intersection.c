/*
4)Consider two sets S1={1,2,3,4}, and S2={3,4,5}. 
Find the intersection of S1 and S2={3,4}.
Implement the set operation intersection using arrays.
*/

#include <stdio.h>

int main() {
    int n, m; 
    // Read set1
    printf("Enter total number of set1: ");
    scanf("%d",&n);
    int set1[n];
    for(int i=0; i<n; i++){
        printf("Enter number: ");
        scanf("%d",&set1[i]); 
    } 
    // Read set2
    printf("Enter total number of set2: ");
    scanf("%d",&m);
    int set2[m];
    for(int i=0; i<m; i++){
        printf("Enter number: ");
        scanf("%d",&set2[i]); 
    } 

    // Finding intersection and displaying
    printf("Intersection of set1 and set2: {");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(set1[i] == set2[j]) {
                printf("%d, ", set1[i]);
                break;
            }
        }
    }
    printf("\b\b}\n");
}

/*
Output:
Enter total number of set1: 4
Enter number: 1
Enter number: 2
Enter number: 3
Enter number: 4
Enter total number of set2: 3
Enter number: 3
Enter number: 4
Enter number: 5
Intersection of set1 and set2: {3, 4}
*/
