#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void display(struct Node *head)
{
    struct Node *ptr = head;
     do{
    printf("Element: %d\n", ptr->data);
    ptr = ptr->next;
     }
    while (ptr!=head);
}
struct Node * insertAtFirst(struct Node * head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
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

    first->data = 11;
    first->next = second;

    second->data = 13;
    second->next = third;

    third->data = 15;
    third->next = fourth;

    fourth->data = 17;
    fourth->next = head;
    printf("Elements Before Insertion\n");
    display(head);
    printf("Elements after Insertion\n");
    head = insertAtFirst(head, 77);
    display(head);
    return 0;
}