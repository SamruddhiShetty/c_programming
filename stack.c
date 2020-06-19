# c_p
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct stack{
    int *data;
    int top;
    int size;
}st;
st* init(int size);
void check(int no, st *stack1, st *s2);
void push(int element, st *stack1);
int pop(st *stack1);
void printmax(st *stack2);
st* init(int size){
   st *s=(st*)malloc(sizeof(st));
   s->top=-1;
   s->size=size;
   s->data=(int*)malloc(sizeof(int)*size);
   return s;
}
int element;
int max=0;
void check(int no, st *stack1, st *s2){
    switch(no){
        case 1:
          scanf("%d", &element);
          push(element, stack1);
           if (element>max){
                max=element;
                push(max, s2);
            }
          break;
        case 2:
            if(stack1->data[stack1->top]==s2->data[s2->top]){
                pop(s2);
                if(s2->top==-1){
                    max=0;
                }
                else
                {
                    max=s2->data[s2->top];
                }
                
            }
          pop(stack1);
          break;
        case 3:
          printmax(s2);
          break;
    }
}
void push(int element, st *stack1){
    if (stack1->top==stack1->size-1){
       stack1->data=(int*)malloc(sizeof(int)*stack1->size*2);

    }
    stack1->top++;
    stack1->data[stack1->top]=element;
 
}
int pop(st *stack1){
    if (stack1->top==-1){
        return -1;
    }
    stack1->top--;
    //printf("after pop%d\n", stack1->data[stack1->top]);
    return 0;
}
void printmax(st *stack2){
    printf("%d\n",stack2->data[stack2->top]);
}
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N,i;
    int no;
    scanf("%d", &N);
    st *s=init(N);
    st *s2=init(30);
    for(i=0;i<N;i++){
    scanf("%d", &no);
    check(no,s,s2);
    }
    return 0;
}
rogramming
