#include<stdio.h>
#include<conio.h>
#include <stdlib.h>

struct queue{
    struct queue *next;
    int value;
};
void menue(struct queue **arr);
void push(struct queue **arr,int value);
void pop(struct queue **arr);
void peak(struct queue **arr);


void main(){
    struct queue *rear=NULL;
    menue(&rear);
}

void menue(struct queue **arr){
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

