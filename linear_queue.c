# c_programming
#include<stdio.h>
#include<stdlib.h>
typedef struct queue{
    int *arr;
    int front, back;
    int capacity;
}que;

que* init(int n);
void enqueue(que *q,int key);
int dequeue(que *q);
void front_key(que *q);


que* init(int n){
    que *q=(que*)malloc(sizeof(que));
    q->capacity=n;
    q->front=q->back=0;
    q->arr=(int*)malloc(sizeof(int)*n);
    return q;
}

void enqueue(que *q,int key){
    if (q->back==q->capacity){
        printf("overflow condition\n");
        return;
    }
    q->arr[q->back]=key;
    q->back ++;
}

int dequeue(que *q){
    int x;
    if(q->front > q->back){
        printf("underflow condition\n");
        return -1;
    }
    x=q->arr[q->front];
    q->front ++;
    return x;
}

void front_key(que *q){
    printf("%d\n",q->arr[q->front]);
}

void rear_key(que *q){
    printf("%d\n",q->arr[q->back-1]);
}

void main(){
    int n;
    printf("enter the size of the queue\n");
    scanf("%d",&n);
    que *q=init(n);  
    //q is assigned the value of address returned jus like int *i=20; where i holds the address of 20
    while(1){
        printf("press 1 to enqueue\n");
        printf("press 2 to dequeue\n");
        printf("press 3 to get the front item\n");
        printf("press 4 to get the rear item\n");
        printf("press 5 to exit\n");
        int choice;
        printf("enter the choice\n");
        scanf("%d",&choice);
        int key;
        switch(choice){
            case 1:
               printf("eneter the item to be addded\n");
               scanf("%d",&key);
               enqueue(q, key);
               break;

            case 2:
               key=dequeue(q);
               printf("the item deleted from the queue is %d\n",key);
               break;

            case 3:
              front_key(q);
              break;

            case 4:
              rear_key(q);
              break;
            
            case 5:
               exit(1);
            default:
               printf("error\n");
        }
    }

}
