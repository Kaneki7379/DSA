#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void display(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}
 
//  Insert At End
struct Node * insertAtEnd(struct Node * head,int data){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node * p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    ptr->data=data;
    p->next=ptr;
    ptr->next=NULL;
    return head;
}
// Insert in Between
struct Node * insertAtBetween(struct Node * head,int data,int index){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node *p=head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}
// Insert At Beginning
struct Node * insertAtFirst(struct Node *head,int data){
struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
ptr->next=head;
ptr->data=data;
return ptr;
}

// Insert After Node
struct Node * insertAfterNode(struct Node *head,struct Node *prevNode,int data){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node *p=prevNode;
    ptr->data=data;

    ptr->next=p->next;
    p->next=ptr;
    return head;
}
int main()
{
    struct Node *head;
    struct Node *first;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head=(struct Node*)malloc(sizeof(struct Node));
    first=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = first;

    first->data = 11;
    first->next = second;

    second->data = 66;
    second->next = third;

    third->data = 41;
    third->next = fourth;

    fourth->data=74;
    fourth->next=NULL;

    display(head);
    printf("Now New Linked List : \n");
    // head=insertAtFirst(head,53);
    // head=insertAtBeginning(head,56,1);
    head=insertAfterNode(head,second,56);
    display(head);

    return 0;
}