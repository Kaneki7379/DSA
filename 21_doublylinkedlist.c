#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node * doubly(struct Node *head){

}
int main(){
    struct Node *N1=(struct Node *)malloc(sizeof(struct Node));
    struct Node *N2=(struct Node *)malloc(sizeof(struct Node));
    struct Node *N3=(struct Node *)malloc(sizeof(struct Node));
    struct Node *N4=(struct Node *)malloc(sizeof(struct Node));

    N1->next=N2;
    N1->prev=NULL;
    N1->data=23;
    N2->next=N3;
    N2->prev=N1;
    N2->data=56;
    N3->next=N4;
    N3->prev=N2;
    N3->data=34;
    N4->next=NULL;
    N4->prev=N3;
    N4->data=44;
    return 0;
}