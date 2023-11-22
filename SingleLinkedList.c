#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TEST 0
#define MAX_CAPACITY 100

typedef struct Student{
    char name[50];
    unsigned RollNo;
    unsigned age;
    char className[20];
    struct Student* next;
}Student;

/*Global Variable*/
unsigned Count=0;

//Function to add students with the parameter being pointer of a pouinter 
void AddStudent(Student **Node){
    
    //Check if the database is at full capacity
    if(Count<MAX_CAPACITY){
        //Allocate memory and initialize with junk values
        Student *newStudent = (Student*)malloc(sizeof(Student));

        //Null check for mempory allocation
        if(newStudent!=NULL){
            //Recieve the inputs
            printf("\nName: ");
            scanf("%s", newStudent->name);
        
            printf("\nRollNo: ");
            scanf("%d", &newStudent->RollNo);

            printf("\nage: ");
            scanf("%d", &newStudent->age);

            printf("\nclass name: ");
            scanf("%s", newStudent->className);
        
            //Since we are adding the last node, the last node points to NULL.
            newStudent->next = NULL; 

            //Check if adding 1st node.
            if(*Node == NULL){
                
                //YES, then Node(pointing to NULL) points the the new node
                *Node = newStudent;

            }else{

                //NO, then traverse the loop to find the last node.
                Student* current = *Node;
                
                while(current->next!= NULL){
                current = current->next;
                }

                //The previous last node points to the new node.
                current->next=newStudent;

                //increment the count
                Count++;

            }

        }
    }else{

        //memory allocation failed
        printf("\nMemory allocatin failed");
    }
   
}

void GetStudentFromName(Student *Node){
    char nameSearch[50];

    //Get the name for searching
    printf("\nEnter the search:");
    scanf("%s", nameSearch);

    while(Node!=NULL){

        //search success, student found
        if(strcmp(Node->name, nameSearch)==0){

            //display the student details
            printf("\nName: %s", Node->name);
            printf("\nRollNo: %d", Node->RollNo);
            printf("\nAge: %d", Node->age);
            printf("\nClassName: %s", Node->className);
            
            //exit loop on successful match
            break;

        }else{

            //If name is not a match, traverse the list.
            Node=Node->next;
        }
        

    }
}

//Function to free memory 
void FreeMemory(Student *head){
    Student *current = NULL;
    while(head!=NULL){
        current = head;
        head = current->next;
        free(current);
    }
}

int main() {
   
    Student *studentDBS = NULL;
    
    char choice;

    do {
        printf("\n\nStudent DBS\n");
        printf("\n1. Add student");
        printf("\n2. Get student details using Name");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                //passing the address of StudentDBS(head) - the variable
                AddStudent(&studentDBS);    /*doubt while passing pointer arguments
                                            Maybe cuz call by reference*/
                break;
            case '2':

                //passing the address stored in studentDBS.
                GetStudentFromName(studentDBS);     /*doubt while passing pointer arguments
                                                    Maybe cuz call by value*/
                break;
            case '3':
                printf("Exit.\n");
                 //free memory 
                FreeMemory(studentDBS);
                //exit the program
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != '3');

   return 0;

    
}


