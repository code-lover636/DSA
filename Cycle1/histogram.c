/*
3) Find the frequency of occurrence of each character in the string ( histogram)

Eg: input: This is a test string
Output:t-3, h-1,i-3,s-4,’ ‘-4…….etc
*/

#include <stdio.h>
#include <string.h>

int In(char ch, char string[]){
    for(int i=0; i<strlen(string); i++){
        if(string[i]==ch)
            return 1;
    }
    return 0;
}

int main() {
    char str[100], duplicate[100];
    printf("Input string: ");
    scanf("%[^\n]s", &str);
    
    // Calculating and printing
    int count, i, j, k=0;
    for(i=0; i<strlen(str); i++){
        count = 0;
        // Checking if char already counted
        if(In(str[i],duplicate))
            continue;
        else
            duplicate[k++]=str[i];
        // Finding the count
        for(j=0; j<strlen(str); j++){
            if(str[i]==str[j]){
                count++;
            }
        }
        printf("%c=%d\n",str[i],count);
    }
}

/*
Output:
Input string: This is a test string
T=1
h=1
i=3
s=4
 =4
a=1
t=3
e=1
r=1
n=1
g=1
*/
