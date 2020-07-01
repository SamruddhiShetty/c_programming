# c_programming
#include<stdio.h>
#include<stdlib.h>

typedef struct Tree{
    int data;
    struct Tree *left, *right;
}tree;

tree* init();
tree* insert(tree *root,int key);
void pre_order(tree *root);
void in_order(tree *root);
void post_order(tree *root);

tree* init(){
    tree *t=(tree*)malloc(sizeof(tree));
    t->data=0;
    t->left=t->right=NULL;

}

tree* insert(tree *root,int key){
    tree *t=init();
    tree *current;
    t->data=key;
    if (root->data==0){
        printf("assigned root\n");
        return t;
    }
    else{
        current=root;
    }

    while (1){
        if (current->data < t->data){
            if (current->right==NULL){
                current->right=t;
                printf("assigned root-right\n");
                break;
            }
            else{
                current=current->right;
            }

        }
        else if(current->data > t->data){
            if (current->left==NULL){
                current->left=t;
                printf("assigned root-left\n");
                break;
            }
            else{
                current=current->left;
            }

        }
        else
        {
            break;
        }
        

    }

    return root;
}

void pre_order(tree *root){
    if (root!=NULL){

        printf("%d\t",root->data);

        pre_order(root->left);

        pre_order(root->right);
    }
    //printf("\n");

}  

void in_order(tree *root){
    if (root!=NULL){
        in_order(root->left);

        printf("%d\t", root->data);

        in_order(root->right);
    }
    //printf("\n");
}


void post_order(tree *root){
    if (root!=NULL){
        post_order(root->left);

        post_order(root->right);

        printf("%d\t", root->data);
  
    }
    //printf("\n");
}

void main(){
    tree *root=init();
    int choice,key;
    while(1){
        printf("press 1 to insert\n");
        printf("press 3 to print in pre-order\n");
        printf("press 4  for in-order\n");
        printf("press 5 for post_order\n");
        printf("press 6 to exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("enter the value\n");
                scanf("%d",&key);
                root=insert(root, key);
                break;
            case 3:
                pre_order(root);
                break;

            case 4:
                in_order(root);
                break;

            case 5:
                post_order(root);
                break;

            case 6:
                exit(1);

        }
    
    }
}
