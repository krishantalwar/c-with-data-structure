#include<stdio.h>
#include<conio.h>
#include <stdlib.h>

struct stack{
    struct stack *next;
    int value;
};
void menue(struct stack **arr);
void push(struct stack **arr,int value);
void pop(struct stack **arr);
void peak(struct stack **arr);

void main(){
    struct stack *arr=NULL;
    menue(&arr);
}

void menue(struct stack **arr){
    int n,value;
    printf("enter 1 for push emlement in stack \n");
    printf("enter 2 for pop emlement in stack \n");
    printf("enter 3 for peek emlement in stack \n");
    printf("enter 4 for print emlements in stack \n");
    printf("enter your choice ");
    scanf("%d",&n);
    if(n==1){
        printf("enter the value \n");
        scanf("%d",&value);
        push(arr,value);
    }else if(n==2){
        pop(arr);
    }else if(n==3){      
        peak(arr);
    }else if(n==4){
        // print(arr);
    }
}

void push(struct stack **arr,int value){
    struct stack *t,*new;
    t=*arr;
    new=(struct stack *) malloc(sizeof(struct stack*));
    new->value=value;
    new->next=NULL;
    if(t==NULL){
        *arr=new;
    }else{
         new->next=t;
        //  t->next=new;
        *arr=new;
    }
    menue(arr);
}


void pop(struct stack **arr){
    struct stack *t;
    t=*arr;
    if(t!=NULL){
        t=(*arr)->next;
        // free(arr);
        *arr=t;
    }else{
        printf("nothing to delete");
    }
    menue(arr);
}


void peak(struct stack **arr){
    struct stack *t;
    t=*arr;
    int i=0;
    for(i=0; t!=NULL; i++){
        printf("the element is %d",t->value);
        t=t->next;
    }
    menue(arr);
}