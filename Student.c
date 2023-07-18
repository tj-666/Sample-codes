#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student{
        char name[50];
        int rollNo;
        int age;
        char className[10];
}Student;

/*global variables*/
Student *studentDBS = NULL;      //pointer to database
int studNo = 0;                         //total number of stduents

void addStudent(){

        Student newStudent;

        printf("\nName: ");
        scanf("%s", newStudent.name);

        printf("\nrollno: ");
        scanf("%d", &newStudent.rollNo);

        printf("\nage: ");
        scanf("%d", &newStudent.age);

        printf("\nclass name: ");
        scanf("%s", newStudent.className);

        //increment studNo after new student is added successfully
        studNo = studNo + 1;

        //reallocate the database on each new student
        studentDBS = (Student*)realloc(studentDBS, studNo*sizeof(Student)) ;

        if(studentDBS == NULL){
                printf("\nMemory allocation failed");
                exit(-1);
        }

        //add the new student to the database
        studentDBS[studNo-1] = newStudent;
        printf("\naddStudent SUCCESS\n");

}

void getStudentFromName(){
        char search[50];        //matchcase
        int flag = 0;           //flag indicating hit or miss
        printf("Enter the student name for searching: ");
        scanf("%s", search);

        //traversal to find matchcase
        for(int i=0; i<studNo; i++){
                if(strcmp(studentDBS[i].name, search)==0){
                        flag = 1;              //hit

                        /*display the student details*/
                        printf("\nName: %s", studentDBS[i].name);
                        printf("\nrollno: %d", studentDBS[i].rollNo);
                        printf("\nage: %d", studentDBS[i].age);
                        printf("\nName: %s", studentDBS[i].className);
                }
        }

        if(!flag){
                printf("\nStudent not in database");
        }

}

void main() {
    char choice;

    do {
        printf("\n\nStudent DBS\n");
        printf("\n1. Add student");
        printf("\n2. Get student details using Name");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%s", &choice);

        switch (choice) {
            case '1':
                addStudent();
                break;
            case '2':
                getStudentFromName();
                break;
            case '3':
                printf("Exit.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != '3');

    // Free Memory
    free(studentDBS);

}
