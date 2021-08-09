#include<stdio.h>
#include<conio.h>
#include <stdlib.h>

struct stack{
    int *ptr;
    int capicity;
    int lastindex;
};
void menue(struct stack *arr);
struct stack* createarray(int capicity); 
void push(struct stack *arr,int value);
void pop(struct stack *arr);
void peak(struct stack *arr);
void print(struct stack *arr);
void main(){
    int length;
    printf("enter the length of array");
    scanf("%d",&length);
    struct stack *arr;
    arr=createarray(length);
    menue(arr);
}
struct stack* createarray(int capicity){
    struct stack* arr;
    arr=(struct stack*) malloc(sizeof(struct stack*));
    arr->ptr=(int *)malloc(capicity*sizeof(int));
    arr->capicity=capicity;
    arr->lastindex=-1;
    return arr;
}

void menue(struct stack *arr){
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
        push(arr);
    }else if(n==2){
        pop(arr);
    }else if(n==3){      
        peak(arr);
    }else if(n==4){
        print(arr);
    }
}

void push(struct stack *arr,int value){
    arr->ptr[arr->lastindex+1]=value;
    arr->lastindex++;
    menue(arr);
}

void pop(struct stack *arr){
    if(arr->lastindex!=-1){
        printf("the pop element is %d",arr->ptr[arr->lastindex]);
        arr->lastindex--;    
    }else{
        printf("nothing to pop");
    }
    menue(arr); 
}

void peak(struct stack *arr){
    if(arr->lastindex!=-1){
        printf("the peak element is %d",arr->ptr[arr->lastindex]); 
    }else{
        printf("nothing to peak");
    }
    menue(arr); 
}

void print(struct stack *arr){

}