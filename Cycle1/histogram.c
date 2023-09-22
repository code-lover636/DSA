/*
3) Find the frequency of occurrence of each character in the string ( histogram)

Eg: input: This is a test string
Output:t-3, h-1,i-3,s-4,’ ‘-4…….etc
*/

#include <stdio.h>
#include <string.h>

int main() {
    char histogram[] = "histogram";
    char str[100];
    printf("Input string: ");
    scanf("%[^\n]s", &str);
    
    // Calculating and printing
    int count, i, j;
    for(i=0; i<strlen(histogram); i++){
        count = 0;
        for(j=0; j<strlen(str); j++){
            if(histogram[i]==str[j])
                count++;
        }
        printf("%c=%d\n",histogram[i],count);
    }
}

/*
Output:
Input string: This is a test string
h=1
i=3
s=4
t=3
o=0
g=1
r=1
a=1
m=0
*/
