# c_programming

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next,*prev;
}node;

node* init(int key);
node* insert_front(node *head, int key);
node* insert_back(node *head, int key);
node* print_list(node *head);
node* delete_front(node* head);
node* delete_rear(node *head);

node* init(int key){
    node *n=(node*)malloc(sizeof(node));
    n->data=key;
    n->prev=n->next=n;
    return n;
}

node* insert_front(node *head, int key){
    node *n=init(key);
    if (head->prev==head){
        head->prev=n;
    }
    n->next=head->next;
    n->prev=head;
    head->next->prev=n;
    head->next=n;
    head->data++;
    return head;
}

node* insert_back(node *head, int key){
    node *n=init(key);
    if (head->next==head){
        head->next=n;
    }
    n->prev=head->prev;
    n->next=head;
    head->prev->next=n;
    head->prev=n;
    head->data ++;
    return head;
}

node* print_list(node *head){
    node *current;
    current=head->next;
    printf("in-order\n");
    for(int i=0;i<head->data;i++){
        printf("%d\t",current->data);
        current=current->next;
    }
    printf("\n");
    printf("reverse-order\n");
    current=head->prev;
    while(current!=head){
        printf("%d\t",current->data);
        current=current->prev;
    }
    printf("\n");
    return head;
}

node* delete_front(node *head){
    node* current;
    current=head->next;
    printf("%d\n",current->next->data);
    head->next=current->next;
    current->next->prev=head;
    head->data--;
    return head;
}

node* delete_rear(node *head){
    node* current;
    current=head->prev;
    printf("%d\n",current->prev->data);
    head->prev=current->prev;
    current->prev->next=head;
    head->data--;
    return head;

}

void main(){
    node *head=init(0);
    while (1){
        printf("press 1 to insert front\n");
        printf("press 2 to insert at the rear end\n");
        printf("press 3 to print\n");
        printf("press 4 to delete at the front end\n");
        printf("press 5 to delete at the rear\n");
        printf("press 6 to exit\n");
        int choice, key;
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("enter the number\n");
                scanf("%d",&key);
                head=insert_front(head, key);
                break;

            case 2:
                printf("enter the number\n");
                scanf("%d",&key);
                head=insert_back(head, key);
                break;

            case 3:
                head=print_list(head);
                break;

            case 4:
                head=delete_front(head);
                break;
            
            case 5:
                head=delete_rear(head);
                break;

            case 6:
               exit(1);

            default:
                printf("error\n");

        
    }

}
}
