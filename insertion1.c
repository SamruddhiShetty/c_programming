# c_programming
#include <stdio.h>
int max_of_four(int a[5]){
    int i,v,j;
    for(i=1;i<4;i++){
       v=a[i];
       j=i-1;
       while(j>=0 && a[j]>v){
           a[j+1]=a[j];
           j -= 1;
       }
       a[j+1]=v;
    }
    for(i=0;i<4;i++){
         printf("%d\t",a[i]);
    }
    return (a[3]);
}

int main() {
    int a[5],i;
    for(i=0;i<4;i++){
      scanf("%d", &a[i]);
    }
    int ans = max_of_four(a);
    printf("%d", ans);
    
    return 0;
}
