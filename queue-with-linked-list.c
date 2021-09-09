#include<stdio.h>
#include<conio.h>
#include <stdlib.h>


struct queuenodes{
    struct queuenodes *next;
    int item;
};


struct queue{
    struct queuenodes *front;
    struct queuenodes *rear;
};

void menue(struct queue **arr);
void push(struct queue **arr,int value);
void pop(struct queue **arr);
void peak(struct queue **arr);


void main(){
    struct queue* q=NULL;
    q = (struct queue*)malloc(sizeof(struct queue));
    q->front=NULL;
    q->rear=NULL;
    // printf(" the  quee is %d \n",q);
    // printf(" the  quee  address is %d \n",&q);
    // exit(0);
    menue(&q);
}




void menue(struct queue **arr){
    int n,value;
    // printf(" the  quee is %d \n",arr);
    // printf(" the  quee  address is %d \n",&arr);
    // printf(" the  quee  address is %d \n",*arr);
    

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


void push(struct queue **arr,int value){
    struct queuenodes *new,*temp=NULL;
    temp = (struct queuenodes*)malloc(sizeof(struct queuenodes));
    new=(struct queuenodes *)malloc(sizeof(struct queuenodes));
    new->next=NULL;
    new->item=value;

    if((*arr)->rear==NULL){
        // printf("the value is %d \n",queue);
        (*arr)->rear=new;
        (*arr)->front=new;
        // printf("the value is %d \n",queue);
        // (*arr)=new;
        // printf("the value is %d \n",(*arr));
    }else{
        // printf("the value is %d \n",new->next);
        printf("the value is %d \n",new->next);
        (*arr)->rear->next=new;
        (*arr)->rear=new;
    }
    menue(arr);
}


void pop(struct queue **arr){
    struct queue *temp=NULL;
    temp=*arr;

    if(temp->front==NULL){
        printf("noting to pop");
    }else{

        printf("the valie is %d \n",(*arr)->front->item);
        (*arr)->front=(*arr)->front->next;
        
    }
   menue(arr);
}





void peak(struct queue **arr){
    struct queue *temp;
    temp=*arr;

    if(temp->front==NULL){
        printf("noting to peak \n");
    }else{
        printf("the valie is %d \n",temp->front->item);
    }
   menue(arr);
}



