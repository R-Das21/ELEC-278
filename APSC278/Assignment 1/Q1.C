//Q1_Das_Rishit
#include <stdio.h>
#include <stdlib.h>

//Declaring struct
struct node{
    int data;
    struct node *previous;  
    struct node *next;  
};

struct node *head, *tail = NULL; 
//Display linked list
void display() {  
 
    struct node *current = head;  
    while(current != NULL) {  
        printf("%d ", current->data);  
        current = current->next;  
        
    }  
}  

void create(int data){
    //Allocating memory
    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    //Assigning value to new node
    newNode->data = data;  
    
    //If linked list is empty make new node head and tail
    if(head == NULL) {  
        head = tail = newNode;  
        head->previous = NULL;  
        tail->next = NULL;  
    }  
    //Add node to end
    else {  
        tail->next = newNode;  
        newNode->previous = tail;  
        tail = newNode;  
        tail->next = NULL;  
        }
}
    //Insert node to front of linked list
    void insertfirst(int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    newNode->data = data;  
    
    if(head == NULL) {  
        head = tail = newNode;  
        head->previous = NULL;  
        tail->next = NULL;  
        }  
    else {  
        head->previous = newNode;  
        newNode->next = head;  
        head = newNode;  
        head->previous = NULL;  
        }
}
// Delete first node
void deletefirst(){
    //Shifts current head
    struct node *headref;  
    headref = head;  
    head = head -> next;  
    head -> previous = NULL;  
    //Frees removed node
    free(headref);  
}


void insertpos(int data){
    //Allocating memory
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    //Add data to new node
    newNode->data = data;
    //Create temp node
    struct node *temp = head;
    //Moves temp node down
    temp = temp->next;
    //Insert node into postion
    newNode->next = temp->next;
    temp->next = newNode;
}

void merge(int data){
    //Declaring counters
    int counter = 0;
    int n = 0;
    //Allocating memory
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    //Add data to new node
    newNode->data = data;
    //Create temp node
    struct node *temp = head;
    //While node is not inserted
    while(counter == 0){
        // Determines where to place node
        if(temp->data < data){
            temp = temp->next;
            n++;
        }
        else{
            //Reassign temp to head
            temp = head;
            //Move temp into position to add new node
            for(int i = 0; i < n - 1; i++){
                temp = temp->next;
            }
            //Add new node
            newNode->next = temp->next;
            temp->next = newNode;
            //Counter for node added
            counter += 1;
        }
    }
}

int main()
{
    //Prints and creates List A
    printf("List A\n");
    create(10);
    create(20);
    create(50);
    display();
    printf("\n");
    
    //Prints and creates List B
    printf("List B\n");
    insertfirst(5);
    display();
    printf("\n");
    
    //Prints and creates List C
    printf("List C\n");
    deletefirst();
    display();
    printf("\n");
    
    //Prints and creates List D
    printf("List D\n");
    insertpos(30);
    display();
    printf("\n");
    
    //Prints and creates List E
    printf("List E\n");
    merge(36);
    merge(25);
    merge(24);
    display();
    printf("\n");
    
    return 0;
}



