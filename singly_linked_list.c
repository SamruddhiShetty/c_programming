# c_programming
 #include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int element;
    struct Node *next;
}node;
node* insertion_at_front(node *head,int data);
node* insertion_at_the_end(node *head,int data);
void print_the_list(node *head);
node* init(int data);
node* delete_by_key(int data, node *head);
node*  delete_at_pos(int pos,node *head);
node* init(int data){
    node *n=(node*)malloc(sizeof(node));
    n->element=data;
    n->next=NULL;
    return n;
}
node* insertion_at_front(node *head,int data){
    node *n=init(data);
    n->next=head->next;
    head->next=n;
    head->element +=1;
    return head;
 
}

node* insertion_at_the_end(node *head,int data){
      node *n=init(data);
      node *current=init(0);
      if(head->next==NULL){
           head->next=n;
        }
        //current=head;
      else{
          current=head->next;
          while(current->next!=NULL){
              current=current->next;
          }
          current->next=n;
      }
      head->element +=1;
      return head;
         
}

node* delete_by_key(int data, node *head){
    node *current=init(0);
    node *prev=init(0);
    current=head;
    while(current!=NULL){
        prev=current;
        current=current->next;
        if(current->element==data){
            prev->next=current->next;
            free(current);
            break;
        }
    }
    if (current==NULL){
        printf("the element is not present in the list\n");
    }
    head->element --;
    return head;
}

void print_the_list(node *head){
    node *current=init(0);
    current=head;   //check out this one 
    for(int i=0;i<head->element;i++){
        current=current->next;
        printf("%d\t",current->element);
    
    }
    printf("total number of elements in list are %d\n",head->element);
}


node*  delete_at_pos(int pos,node *head){
    int count=0;
    node *current=init(0);
    node *prev=init(0);
    current=head;
    while(count!=head->element){
        prev=current;
        current=current->next;
        count ++;
        if(count==pos){
            prev->next=current->next;
            free(current);
            break;
        }
    }
    if(count==head->element){
        printf("this position does not exist\n");
    }
    head->element --;
    return head;

}

void main(){
    node *head=init(0);
    head->element=0;
    head->next=NULL;
    int data;
    while(1){
    printf("press 1 to insert in the front\n");
    printf("press 2 to insert at the back end\n");
    printf("press 3 to print the list\n");
    printf("press 4 to exit\n");
    printf("press 5 to delete by key\n");
    printf("press 6 to delete by position\n");
    int choice;
    scanf("%d",&choice);
    switch(choice){
        case 1:
           printf("eneter the data to be added to the list\n");
           scanf("%d",&data);
           head=insertion_at_front(head,data);
           break;
        case 2:
           printf("enter the element to be added to the list\n");
           scanf("%d",&data);
           head=insertion_at_the_end(head,data);
           break;

        case 3:
            print_the_list(head);
            break;
        case 4:
            exit(1);

        case 5:
             printf("enter the element to be deleted\n");
             scanf("%d",&data);
             head=delete_by_key(data,head);
             break;
        
        case 6:
            printf("enter the position where the element has to be deleted\n");
            int pos;
            scanf("%d",&pos);
            head=delete_at_pos(pos,head);
            break;
        default:
           printf("error");
    }
}
}
