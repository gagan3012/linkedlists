
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *create_ll(struct node* head);
struct node *start(struct node* head);
struct node *inatbeg(struct node *head);
struct node *inatend(struct node *head);
struct node *deletebeg(struct node * head);
struct node *deleteend(struct node *head);
struct node *sort(struct node *head);
int main()
{
    head=create_ll(head);
    printf("created\n");
    head=sort(head);
    head=start(head);
}
struct node *create_ll(struct node* head){
    struct node *new_node,*ptr;
    int num;
    printf("enter data\n");
    scanf("%d",&num);
    while(num!=-1){
        new_node=(struct node*)malloc(sizeof(struct node));
        new_node -> data=num;
        if(head==NULL){
            new_node -> next=NULL;
            head=new_node;
        }
        else{
            ptr=head;
            while(ptr->next!=NULL)
            ptr=ptr->next;
            ptr->next=new_node;
            new_node->next=NULL;
        }
        printf("enter data\n");
        scanf("%d",&num);
    }
    return head;
}
struct node *start(struct node* head){
    struct node *ptr;
    ptr=head;
    while(ptr!=NULL){
        printf("\t%d\t",ptr->data);
        ptr=ptr->next;
    }
    return head;
}
struct node *inatbeg(struct node *head){
    struct node *newnode;
    int number;
    printf("enter number\n");
    scanf("%d",&number);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=number;
    newnode->next=head;
    head=newnode;
    return head;
}
struct node* inatend(struct node *head){
    struct node *inend,*ptr;
    int num;
    printf("enter number");
    scanf("%d",&num);
    inend=(struct node*)malloc(sizeof(struct node));
    inend->data=num;
    inend->next=NULL;
    ptr=head;
    while(ptr->next!=NULL)
    ptr=ptr->next;
    ptr->next=inend;
    return head;
}
struct node* deletebeg(struct node* head){
    struct node *delbeg;
    delbeg=head;
    head=head->next;
    free(delbeg);
    return head;
}
struct node* deleteend(struct node* head){
    struct node *ptr,*del;
    ptr=head;
    while(ptr->next!=NULL){
        del=ptr;
        ptr=ptr->next;
    }
    del->next=NULL;
    free(ptr);
    return head;
}
struct node* sort(struct node* head){
    struct node *ptr1,*ptr2;
    int temp;
    ptr1=head;
    while(ptr1->next!=NULL){
        ptr2=ptr1->next;
        while(ptr2->next!=NULL){
            if(ptr1->data>ptr2->data){
                temp=ptr1->data;
                ptr1->data=ptr2->data;
                ptr2->data=temp;
            }
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
    return head;
}