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
// For deleting First Element in the list
struct Node *deleteFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
// For deleting Element at a given Index
struct Node *deletionAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}
// Deleting last Node
struct Node *deleteLastNode(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = p->next;
    while (q->next!= NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}

// Deleting node with a given Value
struct Node * deleteAtValue(struct Node * head,int value){
    struct Node *p=head;
    struct Node *q=p->next;
    while(q->data!=value&&q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    if(q->next!=NULL){
        p->next=q->next;
        free(q);
        return head;
    }
}
int main()
{
    struct Node *head;
    struct Node *first;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = first;

    first->data = 13;
    first->next = second;

    second->data = 16;
    second->next = third;

    third->data = 21;
    third->next = fourth;

    fourth->data = 28;
    fourth->next = NULL;

    display(head);
    printf("New Linked List :\n");
    // head=deleteFirst(head);
    // head = deletionAtIndex(head, 2);
    // head=deleteLastNode(head);
    head=deleteAtValue(head,13);
    display(head);
    return 0;
}