#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DBS_CAPACITY 100
#define TEST 0U

typedef struct Student{
        char name[50];
        unsigned rollNo;
        unsigned age;
        char className[10];
        
        struct Student* next;
}Student;

//int TotalStudents=0;



void AddStudent(Student** end){
    static unsigned count = 0 ;
    if(count<DBS_CAPACITY){
        
        Student* newStudent = (Student*)malloc(sizeof(Student));
        
        if(newStudent != NULL){
            printf("\nName: ");
            scanf("%s", newStudent->name);

            printf("\nrollno: ");
            scanf("%d", &newStudent->rollNo);

            printf("\nage: ");
            scanf("%d", &newStudent->age);

            printf("\nclass name: ");
            scanf("%s", newStudent->className);
        
            newStudent->next = NULL;

            if(*end == NULL){
                #if TEST
                printf("\nend==NULL");
                #endif
                *end = newStudent;
            }else{
                #if TEST
                printf("\nend!=NULL");
                #endif
                (*end)->next = newStudent;
                //end = newStudent;
                //*end = *newStudent;
            }
            
             
            count++;
             
            
            #if TEST
                printf("\nnewStudent");
                printf("\nName: %s", newStudent->name);
                printf("\nrollno: %d", newStudent->rollNo);
                printf("\nage: %d", newStudent->age);
                printf("\nName: %s", newStudent->className);
                printf("%d", count);
            #endif

        }else{
            printf("\nMemory allocation failed");
        }
    }else{
        printf("\n Database is FULL");
    }

}

void GetStudentFromName(Student *head){
    char searchName[50];
    unsigned searchCount=0;
    printf("\nName to search for :");
    scanf("%s", searchName);

    
    
    if(head != NULL){
        Student* current = head ;


    
        while(current!= NULL){
            if(strcmp(current->name, searchName)==0){
                searchCount++;
                /*display the student details*/
                printf("\nName: %s", current->name);
                printf("\nrollno: %d", current->rollNo);
                printf("\nage: %d", current->age);
                printf("\nName: %s", current->className);
                break;
            }else{
                current = current->next;
            }
        }

        if(searchCount == 0){
            printf("\nDatabase is EMPTY.");
        }
        
    }else{
        printf("\nEmpty Database");
    }
}

int main() {
   
    Student* end = NULL;
    Student* studentDBS = NULL;
    //int count=0;
    
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
                AddStudent(&end);
                if(studentDBS==NULL){
                    studentDBS = end; 
                }  
                #if TEST
                    printf("\nend");
                    printf("\nName: %s", end->name);
                    printf("\nrollno: %d", end->rollNo);
                    printf("\nage: %d", end->age);
                    printf("\nName: %s", end->className);                  
                #endif 
                
                #if TEST
                    printf("\nstudentDBS");
                    printf("\nName: %s", studentDBS->name);
                    printf("\nrollno: %d", studentDBS->rollNo);
                    printf("\nage: %d", studentDBS->age);
                    printf("\nName: %s", studentDBS->className);
                   
                #endif  

                break;
            case '2':
                GetStudentFromName(studentDBS);
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
    while(studentDBS!=NULL){
        end = studentDBS;
        studentDBS = end->next;
        free(end);
    }

    return 0;

}