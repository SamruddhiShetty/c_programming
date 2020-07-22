# c_programming
//using array and bottom up approach 

#include<stdio.h>
#include<stdlib.h>
int* heapify(int *a, int size);
void main(){
    int a[20];
    int i;
    int size;
    printf("enter the max size of the array]\n");
    scanf ("%d", &size);
    printf("enter the elements\n");
    for(i=1; i<=size; i++){
        scanf("%d", &a[i]);
    }
    int *b=heapify(a, size);
    for(i=1; i<=size; i++){
    printf("%d\t", *(b+i));
    }   

}

int* heapify(int *a, int size){
    int x= size/2;
    int b,i,k,j;

    for(i=x; i>0; i--){
        k=i;
        b=*(a+k);
        int heap=0;
        while (heap!=1 && 2*k<=size){
            j=2*k;
            if(j<size){
                if(*(a+j)<*(a+j+1)){
                    j ++;
                }
            }
            if(b<*(a+j)){
                *(a+k)=*(a+j);
                k=j;
            }
            else{
                heap=1;
            }
        }
        *(a+k)=b;
    }

    return (a);
}
