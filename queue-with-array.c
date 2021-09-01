#include<stdio.h>
#include<conio.h>
#include <stdlib.h>

struct queue{
    int *ptr;
    int capicity;
    int front,rear;
};
struct queue* createquee(int capicity); 
void mainmenue(struct queue *arr);
void insert(struct queue *arr,int value);
void delete(struct queue *arr);
void peak(struct queue *arr);
void print(struct queue *arr);
void main()
{
    int n;
    struct queue *quee;
    printf("inter the quee or array size");
    scanf("%d",&n);
    quee=createquee(n);
    mainmenue(quee);
 
}
struct queue* createquee(int capicity){
    struct queue *arr;
    arr=(struct queue *)malloc(sizeof(struct queue));
    arr->front=-1;
    arr->rear=-1;
    arr->capicity=capicity;
    arr->ptr=(int *)malloc(capicity*sizeof(int));
    return arr;
}

void mainmenue(struct queue *arr){
    int n,index,value,result,i;

    printf("enter 1 for insert a value \n");
    printf("enter 2 for delete a value \n");
    printf("enter 3 for peak a value \n");
    printf("enter 4 for print queue \n");
    printf("enter other for exit");
    scanf("%d",&n);
    if(n==1){
        printf("enter the value u eant to insert");
        scanf("%d",&value);
        insert(arr,value);
    }else if(n==2){
        delete(arr);
    }else if(n==3){
        peak(arr);
    }else if(n==4){
        print(arr);
    }else{
        mainmenue(arr);   
    }
}


void insert(struct queue *arr,int value){
    if(arr->rear!=arr->capicity-1 || arr->front!=0){
        if(arr->front==-1){
            arr->front=0;
            arr->rear=0;
            arr->ptr[arr->rear]=value;
        }else{
            if(arr->front!=0 && arr->rear==arr->capicity-1){
                arr->rear=0;
                arr->ptr[arr->rear]=value;
            }else{
                if((arr->rear+1)==arr->front){
                    printf("over flow \n");
                }else{
                    arr->rear+=1;
                    arr->ptr[arr->rear]=value;
                }
            }
        }
    }else{
        printf("over flow main \n");
    }
 mainmenue(arr);   
}

void print(struct queue *arr){
     int i;
    for(i=0; i<arr->capicity; i++){
        printf("%d \t",arr->ptr[i]);
    }
    printf("\n ---------------------------\n ");
    printf("%d \n",arr->front);
    for(i=arr->front; i<arr->capicity; i++){
        printf("%d \t",arr->ptr[i]);
    }
           mainmenue(arr);
}


void delete(struct queue *arr){
    if(arr->rear==-1){
        printf("nothing to delete \n");
    }else if(arr->front==arr->rear){
        arr->front=-1;
        arr->rear=-1;
    }else if(arr->front==arr->capicity-1){
        arr->front=0;
    }else{
        arr->front+=1;
    }
    mainmenue(arr);
    
}


void peak(struct queue *arr){
    printf("%d \n",arr->ptr[arr->front]);
    mainmenue(arr);    
}
