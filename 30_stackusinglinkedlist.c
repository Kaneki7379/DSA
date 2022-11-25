#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
int isEmpty(struct Node *top){
if(top==NULL){
    return 1;
}
else{
    return 0;
}
}
int isFull(struct Node *top){
struct Node *n=(struct Node *)malloc(sizeof(struct Node));
if(n==NULL)
return 1;
else
return 0;
}
void linkedlistTraversal(struct Node *ptr)
{
    while(ptr!=NULL){
    printf("Element : %d\n",ptr->data);
    ptr=ptr->next;
    }
}
struct Node * push(struct Node *top,int x){
    if(isFull(top)){
        printf("Stack Overflow !\n");
    }
    else{
    struct Node *n=(struct Node*)malloc(sizeof(struct Node));
    n->data=x;
    n->next=top;
    top=n;
    return top;
}
}
int pop(struct Node **top){
    if(isEmpty(*top)==1){
        printf("Stack Underflow !");
    }
    else{
struct Node *n=*top;
*top=(*top)->next;
int element=n->data;
free(n);
return element;
}
}
int main(){
    struct Node *top=NULL;
    top=push(top,78);
    top=push(top,7);
    top=push(top,8);
    top=push(top,98);
    top=push(top,74);
    top=push(top,12);
    linkedlistTraversal(top);

    int element=pop(&top);

    printf("Popped Element is : %d\nNew Stack :\n",element);
    linkedlistTraversal(top);
    return 0;
}