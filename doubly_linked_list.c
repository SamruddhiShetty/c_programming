# c_programming
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *right;
    struct Node *left;
}node;
node* init(int element);
node* insert_at_front(int element,node *head);
node* insert_at_tail(int element, node* head);
node* print_list(node* head);
node* delete_key(int element,node *head);
node* delete_at_position(int pos,node *head);
node* init(int element){
    node *n=(node*)malloc(sizeof(node));
    n->data=element;
    n->left=NULL;
    n->right=NULL;
}
node* insert_at_front(int element,node *head){
    node *n=init(element);
    if(head->right==NULL){
        n->left=head;
        head->right=n;
        head->data ++;
        return head;
    }
    else{
        n->right=head->right;
        n->left=head;
        head->right->left=n;
        head->right=n;
        head->data++;
        return head;
    }
}

node* insert_at_tail(int element, node* head){
      node *n=init(element);
      node *current=init(0);
      if(head->right==NULL){
          head->right=n;
          n->left=head;
          head->data++;
          return head;
      }
      current=head->right;
      while(current->right!=NULL){
          current=current->right;
      }
      current->right=n;
      n->left=current;
      head->data ++;
      return head;

}

node* delete_key(int element,node *head){
    node *current=init(0);
    current=head->right;
    while(current!=NULL && current->data!=element){
        current=current->right;
    }
    if(current==NULL){
        printf("the element is not there in the list\n");
        return head;
    }
    if(current->right==NULL){
        current->left->right=current->right;
        head->data --;
        return head;
    }
    current->left->right=current->right;
    current->right->left=current->left;
    free(current);
    head->data --;
    return head;
}

node* delete_at_position(int pos,node *head){
    node *current=init(0);
    int count=1;
    current=head->right;
    while(current!=NULL && count!=pos){
        current=current->right;
        count ++;
    }
    if(current==NULL){
        printf("invalid position\n");
        return head;
    }
    if(current->right==NULL){
        current->left->right=current->right;
        head->data --;
        return head;
    }
     current->left->right=current->right;
    current->right->left=current->left;
    free(current);
    head->data --;
    return head;

}

node* print_list(node *head){
    node *current=init(0);
    current=head->right;
    printf("printing it in  order\n");
    while(current!=NULL){
        printf("%d\t",current->data);
        current=current->right;
    }
    printf("\nprinting it in reverse order \n");
    current=head->right;
    while(current->right!=NULL){
        current=current->right;
    }
    while(current!=head){
        printf("%d\t",current->data);
        current=current->left;
    }
    return head;
}

void main(){
    node *head=init(0);
    int element;
    while(1){
        printf("\npress 1 to insert node at the front\n");
        printf("press 2 to insert node at the end\n");
        printf("press 3 to print the list\n");
        printf("press 4 to delete the given item \n");
        printf("press 5 to delete a key at given position\n");
        printf("press 6 to exit\n");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1:
               printf("enter the element to be inserted\n");
               scanf("%d",&element);
               head=insert_at_front(element,head);
               break;

            case 2:
                printf("enter the element to be inserted\n");
                scanf("%d",&element);
                head=insert_at_tail(element,head);
                break;

            case 3:
                head=print_list(head);
                break;
            case 4:
                printf("enter the key to be deleted\n");
                scanf("%d",&element);
                head=delete_key(element,head);
                break;

            case 5:
               printf("enter the position\n");
               int position;
               scanf("%d",&position);
               head=delete_at_position(position,head);
               break;

            case 6:
                exit(1);

            default:
               printf("error\n");
        }
    }
}
