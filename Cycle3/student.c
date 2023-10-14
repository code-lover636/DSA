/*
4.Students grade book system keeps rollno, name,mark(out of 100) of 'n' students in an array of structures( Hint : Create an structure student with above mentioned fields).
Read the details of 'n' students and perform the following
a)read a rollno and display the student details
b)display the list in the order of name
c)print a rank list in the descending order of mark
d)display the list of passed students ( marks >=50)
*/

#include <stdio.h>
#include <string.h>

struct Student{
	int rollno;
	char name[100];
	double mark;
};
int main(){

	int n, roll;
	printf("Enter total no. of students: ");
	scanf("%d", &n);
	struct Student student[n];
	
	for(int i=0; i<n; i++){
		printf("Enter roll no of student %d: ", i+1);
		scanf("%d", &student[i].rollno);
		printf("Enter name of student %d: ", i+1);
		scanf(" %[^\n]s", &student[i].name);
		printf("Enter mark of student %d: ", i+1);
		scanf("%lf", &student[i].mark);
	}
	
	//a
	printf("\nEnter roll no: ");
	scanf("%d", &roll);
	for(int i=0; i<n; i++){
		if(student[i].rollno==roll){
			printf("Roll no: %d\nName: %s\nMark: %lf\n", student[i].rollno, student[i].name, student[i].mark);
		}
	}
	//b
	printf("\nSorted by names:\n");
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-i-1; j++){
			if(strcmp(student[j].name,student[j+1].name)>0){
				struct Student temp = student[j];
				student[j] = student[j+1];
				student[j+1] = temp;
				
			}
		}
	}
	for(int i=0; i<n; i++){
		printf("%d\t%s\t%lf\n", student[i].rollno, student[i].name, student[i].mark);
	}
	//c
	printf("\nRank list:\n");
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-i-1; j++){
			if(student[j].mark<student[j+1].mark){
				struct Student temp = student[j];
				student[j] = student[j+1];
				student[j+1] = temp;
				
			}
		}
	}
	for(int i=0; i<n; i++){
		printf("%d. %d\t%s\t%lf\n", i+1, student[i].rollno, student[i].name, student[i].mark);
	}
	//d
	printf("\nPassed students:\n");
	for(int i=0; i<n; i++){
		if(student[i].mark>50){
			printf("Roll no: %d\tName: %s\tMark: %lf\n", student[i].rollno, student[i].name, student[i].mark);
		}
	}
	
}

/*
Output:
Enter total no. of students: 3
Enter roll no of student 1: 3
Enter name of student 1: Rahul
Enter mark of student 1: 88
Enter roll no of student 2: 2
Enter name of student 2: Arun
Enter mark of student 2: 45
Enter roll no of student 3: 1
Enter name of student 3: Aravind
Enter mark of student 3: 100

Enter roll no: 1
Roll no: 1
Name: Aravind
Mark: 100.000000

Sorted by names:
1       Aravind 100.000000
2       Arun    45.000000
3       Rahul   88.000000

Rank list:
1. 1    Aravind 100.000000
2. 3    Rahul   88.000000
3. 2    Arun    45.000000

Passed students:
Roll no: 1      Name: Aravind   Mark: 100.000000
Roll no: 3      Name: Rahul     Mark: 88.000000
*/
