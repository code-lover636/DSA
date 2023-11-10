/*
2.Read and polynomial of degree n and store in an array. Evaluate this polynomial for a given value of x.
Eg: 3x^2+2x+1
x=2
evaluation=12+4+1=17
*/

#include <stdio.h>
#include <math.h>

int main(){
	int n, val, res=0;
	printf("Enter the degree of polynomial: ");
	scanf("%d",&n);
	
	int poly[n];
	
	
	for(int i=0; i<n; i++){
		printf("Enter cofficient of x^%d: ", i);
		scanf("%d",&poly[i]);
	}
	
	printf("Enter value for x: ");
	scanf("%d",&val);
	
	for(int i=0; i<n; i++){
		res += poly[i] * pow(val,i);
	}
	
	printf("%d\n",res);
	
}
