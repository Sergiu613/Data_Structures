#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node* next;
};

struct List{
    struct Node* head;
};

//create Node
struct Node* createNode(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

//create List
struct List* createList(){
    struct List* list = (struct List*)malloc(sizeof(struct List));
    list->head = NULL;
    return list;
}

//insert at beginning
void prepend(struct List* list, int value){
    struct Node* newNode = createNode(value);
    newNode->next =list->head;
    list->head = newNode;
}

//insert at end
void append(struct List* list, int value){
    struct Node* newNode = createNode(value);
    if(list->head == NULL){
        list->head = newNode;
        return;
    }
    
    struct Node* temp = list->head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

//insertion at a specific position
void insert(struct List* list, int value, int position){
    if(position<=0){
        prepend(list,value);
        return;
    }
    struct Node* newNode = createNode(value);
    struct Node* temp = list->head;
    int i=0;
    while(temp != NULL && i < position - 1){
        temp = temp->next;
        i++;
    }
    if(temp == NULL){
        append(list,value);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

//print
void print(struct List* list){
    struct Node* temp = list->head;
    while(temp != NULL){
        printf("%d , ",temp->value);
        temp = temp->next;
    }
}

//delete first node
void deleteFirst(struct List* list){
    if(list->head == NULL){
        return;
    }
    struct Node* temp = list->head;
    list->head = list->head->next;
    free(temp);
}

//delete last node
void deleteLast(struct List* list){
    if(list->head == NULL){
        return;
    }
    if(list->head->next == NULL){
        free(list->head);
        list->head = NULL;
        return;
    }
    struct Node* temp = list->head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

//deletion at a specific position
void delete(struct List* list, int position){
    if(list->head == NULL){
        return;
    }
    if(position == 0){
        deleteFirst(list);
        return;
    }
    struct Node* temp = list->head;
    for(int i = 0; temp->next != NULL && i < position - 1; i++){
        temp = temp->next;
    }
    if(temp->next == NULL){
        return;
    }
    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}

//searching
int search(struct List* list, int value){
    struct Node*temp = list->head;
    int pos= 0;
    while(temp != NULL){
        if(temp->value == value){
            return pos;
        }
        temp = temp->next;
        pos++;
    }
    return -1;
}
