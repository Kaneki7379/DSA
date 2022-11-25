#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node *next;
};

void linkedlistTraversal(struct Node *ptr)
{
    while(ptr!=NULL){
    printf("Element : %d\n",ptr->data);
    ptr=ptr->next;
    }
}
int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    // Allocate Memory For nodes in Heap
    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    // Linking first node to second node
    head->data=7;
    head->next=second;

    // Linking second node to third node
    second->data=11;
    second->next=third;
    //    Linking third node to NULL
    third->data=66;
    third->next=NULL;

    linkedlistTraversal(head);
    return 0;
}