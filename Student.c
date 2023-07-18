#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NO_STUDENTS 100

typedef struct Student{
        char name[50];
        int rollNo;
        int age;
        char className[10];
}Student;

/*global variables*/
Student *StudentDBS = NULL;      //pointer to database
int TotalStudents = 0;           //total number of students

void AddStudent(){
    if(TotalStudents<=MAX_NO_STUDENTS){

        Student newStudent;

        printf("\nName: ");
        scanf("%s", newStudent.name);

        printf("\nrollno: ");
        scanf("%d", &newStudent.rollNo);

        printf("\nage: ");
        scanf("%d", &newStudent.age);

        printf("\nclass name: ");
        scanf("%s", newStudent.className);

        //reallocate the database on each new student
        StudentDBS = (Student*)realloc(StudentDBS, (TotalStudents+1)*sizeof(Student)) ;

        if(StudentDBS != NULL){
            TotalStudents = TotalStudents+1;

            //add the new student to the database
            StudentDBS[TotalStudents-1] = newStudent;
            printf("\nAddStudent SUCCESS\n");
        }else{
                printf("\nMemory allocation failed");
        }
    }
    else{
        printf("\nMaximum number of students in the database.");
    }

}

void GetStudentFromName(){
        char search[50];        //matchcase
        int flag = 0;           //flag indicating hit or miss
        printf("Enter the student name for searching: ");
        scanf("%s", search);

        /*traversal to find matchcase, exit loop on first hit, program 
        ignores the successive students with similar names*/
        /* remove "&&flag!=1" for considering students with same name*/
        for(int i=0; i<TotalStudents && flag!=1; i++){
                if(strcmp(StudentDBS[i].name, search)==0){
                        flag = 1;              //hit

                        /*display the student details*/
                        printf("\nName: %s", StudentDBS[i].name);
                        printf("\nrollno: %d", StudentDBS[i].rollNo);
                        printf("\nage: %d", StudentDBS[i].age);
                        printf("\nName: %s", StudentDBS[i].className);
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
                AddStudent();
                break;
            case '2':
                GetStudentFromName();
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
    free(StudentDBS);

}
