# c_programming

#include<stdio.h>
#include<stdlib.h>
typedef struct Queue{
    int *arr;
    int capacity;
    int front, back;
    int size;
    
}que;
que* init(int size);
void deque(que*q);
void enque(que*q, int data);
void display(que *q);
que* init(int size){
    que *q=(que*)malloc(sizeof(que));
    q->capacity=size;
    q->arr=(int*)malloc(sizeof(int)*size);
    q->capacity=size;
    q->front=0;
    q->back=-1;
    q->size=0;
    return q;

}

void enque(que*q, int data){
    if (q->back==q->capacity-1 && q->front==0 || q->front==q->back+1 && q->back!=-1){
        printf("overflow\n");
        return ;
    }
    else{
        q->back = (q->back+1)%(q->capacity);
        q->arr[q->back]=data;
        q->size ++;
        printf("%d", q->back);
    }
}

void deque(que*q){
    if (q->front==q->back-1){
        printf("underflow\n");
        return;
    }
    q->front=(q->front+1)%(q->capacity);
    q->size --; 

}

void display(que *q){
    int i=q->front;
    int count=0;
    while (count<q->size){
        printf("%d\t",q->arr[i]);
        count ++;
        i=(i+1)%q->capacity;
    }
}

void main(){
    int capacity;
    printf("enter the capacity of the que\n");
    scanf("%d", &capacity);
    que *q=init(capacity);
    while (1){
        printf("press 1 to insert\n");
        printf("press 2 to delete\n");
        printf("press 3 to display\n");
        printf("press 4 to exit\n");
        int choice;
        printf("enter your choic\n");
        scanf("%d", &choice);
        int key;
        switch(choice){
            case 1:
                printf("enter the data to be inserted\n");
                scanf("%d", &key);
                enque(q, key);
                break;

            case 2:
                deque(q);
                break;

            case 3:
                display(q);
                break;

            case 4:
                exit(1);

                
        }
    }
}

