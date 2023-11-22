/*
A Linked List is a linear data structure that consists of two parts:
 one is the data part and the other is the address part. A Doubly Linked 
 List in contains three parts: one is the data part and the other two 
 are the address of the next and previous node in the list.
 */
#include<stdio.h>
#include<stdlib.h>

//maximul list of nodes
#define MAX_CAPACITY 100

typedef struct Node{
    int data;
    struct Node* pre;
    struct Node* next;
}Node;

/*Global varianble*/
unsigned count = 0 ;


/*INSERTION*/
void AddNodeAtHead(Node **oldHead){

    //check if no.of nodes less than capacity of DBS
    if(count < MAX_CAPACITY){
        
        //Memory alloc of new node
        Node *newHead = (Node*)malloc(sizeof(Node));

        //if allocated properly
        if(newHead!=NULL){

            //take the i/p
            printf("\nEnter the data: ");
            scanf("%d", &(newHead->data));

            //Set the next pointer to nodes as NULL
            newHead->pre = NULL;
            
            
            //
            if(*oldHead != NULL){
                newHead->next = *oldHead;
                (*oldHead)->pre = newHead;    
            }else{
                newHead->next = NULL;
            }
        
            *oldHead = newHead;
            count++;

            printf("\nSuccessfully added new head");

        }else{

            printf("\nAllocation Failed!");

        }
    }else{
        printf("\nDatabase at fullcapacity!");
    }
}

void AddNodeAtEnd(Node **oldEnd){

    if(count < MAX_CAPACITY){


        Node *newEnd = (Node*)malloc(sizeof(Node));

        if(newEnd!=NULL){

            printf("\nEnter the data: ");
            scanf("%d", &(newEnd->data));
           
            newEnd->next = NULL;
            newEnd->pre = NULL;

            if(*oldEnd != NULL){
                newEnd->pre = *oldEnd;
                (*oldEnd)->next = newEnd;                 
            }
            
            *oldEnd = newEnd;

            count++;

            printf("Successfully added node at end");

        }else{
        printf("\nAllocation Failed!");
        }
    }else{

        printf("\nDatabase at full capacity!");
    }  

}
/*END OF INSERTION*/

/*DELETION*/
void DeleteHead(Node **oldHead){
    
    if(*oldHead!=NULL){

        Node *current = *oldHead;
    
        *oldHead = (*oldHead)->next;
    
        if(*oldHead != NULL){
            (*oldHead)->pre = NULL;
        }

        //free memory of current
        free(current);

        count--;


        printf("\nDeletion SUCCESS!");
    }else{

        printf("\nDatabase is empty!");
    }
}

void DeleteEnd(Node **oldEnd){
    
    if(*oldEnd!=NULL){

        Node *current = *oldEnd;
    
        *oldEnd = (*oldEnd)->pre;
    
        if(*oldEnd != NULL){
            (*oldEnd)->next = NULL;
        }

        //free memory of current
        free(current);

        count--;


        printf("\nDeletion SUCCESS!");
    }else{

        printf("\nDatabase is empty!");
    }
}
/*END OF DELETION*/

/*SEARCH*/
void NameSearch(Node* Head) {
    //char nameSearch[50];
    int dataSearch;
    int pos=0;
    printf("\nEnter the search: ");
    scanf("%d", &dataSearch);

    while (Head != NULL) {
        //if (strcmp(Head->name, nameSearch) == 0) {
        if(Head->data == dataSearch){
            printf("\nName: %d found at position: %d", Head->data, pos);
            // Display other student details (if available)
            break; // Exit the loop when the student is found
        }
        Head = Head->next;
        pos++;
    }

    if (Head == NULL) {
        printf("\nStudent not found.");
    }
}
/*END OF SEARCH*/

/*FREE MEMORY*/
void FreeMemory(Node *head){
    Node *current = NULL;
    while(head!=NULL){
        current = head;
        head = current->next;
        free(current);
        count--;
    }
}

int main() {
   
    //Node *DBS = NULL; 
    Node *DBS_head = NULL;
    Node *DBS_end = DBS_head;

    
    char choice;

    do {
        printf("\n\nStudent DBS\n");
        printf("\n1. Add student at head");
        printf("\n2. Add student at end");
        printf("\n3. Delete student at head");
        printf("\n4. Delete student at end");
        printf("\n5. Name search");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {

            case '1':
                //passing the address of StudentDBS(head) - the variable
                AddNodeAtHead(&DBS_head);    

                if(DBS_head->next == NULL){
                    DBS_end = DBS_head;
                }         
                break;



            case '2':

                //passing the address stored in studentDBS.
                AddNodeAtEnd(&DBS_end);     
                if(DBS_end->pre == NULL){
                    DBS_head = DBS_end;
                }      
                break;

            case '3':

                DeleteHead(&DBS_head);
                break;

            case '4':

                DeleteEnd(&DBS_end);
                break;

            case '5':
                NameSearch(DBS_head);
                break;

  
            case '6':
                printf("Exit.\n");
                //free memory 
                FreeMemory(DBS_end);
                //exit the program
                exit(0);
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != '6');

   return 0;

    
}