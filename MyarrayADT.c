#include<stdio.h>
#include<conio.h>
#include <stdlib.h>

struct MyarrayADT{
    int *ptr;
    int capicity;
    int lastindex;
};

struct MyarrayADT* createarray(int capicity); 
void insert(struct MyarrayADT *arr,int index,int value);
void update(struct MyarrayADT *arr,int index,int value);
void delete(struct MyarrayADT *arr ,int index);
void append(struct MyarrayADT *arr ,int value);
void dublearray(struct MyarrayADT *arr);
void printsize(struct MyarrayADT *arr);
int search(struct MyarrayADT *arr ,int value);
int totalintem(struct MyarrayADT *arr);
int getitem(struct MyarrayADT *arr,int index);
void complete(struct MyarrayADT *arr);
void printarray(struct MyarrayADT *arr);
void halfarray(struct MyarrayADT *arr);

void main(){
    int length;
    printf("enter the length of array");
    scanf("%d",&length);
    struct MyarrayADT *arr;
    arr=createarray(length);
    printf("%d \n",arr->lastindex);
    complete(arr);
}

struct MyarrayADT* createarray(int capicity){
    struct MyarrayADT *arr;
    arr=(struct MyarrayADT *)malloc(sizeof(struct MyarrayADT));
    arr->lastindex=-1;
    arr->capicity=capicity;
    arr->ptr=(int *)malloc(capicity*sizeof(int));
    return arr;
}


void complete(struct MyarrayADT *arr){
    int n=0,index,value,result,i;
    printf("enter 0 for print \n");
    printf("enter 1 for insert \n");
    printf("enter 2 for delete \n");
    printf("enter 3 for update \n");
    printf("enter 4 for continoue \n");
    printf("enter 5 for append \n");
    printf("enter 6 for search \n");
    printf("enter 7 for total item \n");
    printf("enter 8 for getitem \n");
    printf("enter 9 for exit");
    scanf("%d",&n);
       
    if(n==1){
         printf("enter the index");
         scanf("%d",&index);
        printf("enter the value");
         scanf("%d",&value);

        insert(arr,index,value);

    }else if(n==2){
        printf("enter the index");
         scanf("%d",&index);

        delete(arr,index);
        halfarray(arr);
    }else if(n==3){
        printf("enter the index");
        scanf("%d",&index);
        printf("enter the value");
        scanf("%d",&value);
        update(arr,index,value);
        
    }else if(n==4){
         printsize(arr);
    }else if(n==5){

        printf("enter the value");
         scanf("%d",&value);
        append(arr,value);
    }else if(n==6){

        printf("enter the value");
         scanf("%d",&value);
       result= search(arr,value);
       printf("serach result=%d \n", result);
           complete(arr);
    }else if(n==7){

        result=totalintem(arr);
        printf("total item  result=%d \n", result);
            complete(arr);
    }else if(n==8){
        printf("enter the index");
        scanf("%d",&index);
       result= getitem(arr,index);
            printf("item at %d result=%d \n", index,result);
                complete(arr);
    }else if(n==9){
        exit(0);
    }else if(n==0){
        printarray(arr);
    }
    else{
        printf("enter wrong input \n");
        complete(arr);
    }
}









void insert(struct MyarrayADT *arr,int index,int value){
    int i;
    if(index<0 || index> arr->lastindex+1){
     
        printf("envalid index \n");
    }
    else if(arr->lastindex+1==arr->capicity){
        // printf("unsufficient space \n");
         dublearray(arr);
        for(i=arr->lastindex; i>=index; i--){
            arr->ptr[i+1]=arr->ptr[i];
        }
        arr->ptr[index]=value;
        arr->lastindex++;
    }
    else{
        for(i=arr->lastindex; i>=index; i--){
            arr->ptr[i+1]=arr->ptr[i];
        }
        arr->ptr[index]=value;
        arr->lastindex++;
    }
         
    complete(arr);
}

void append(struct MyarrayADT *arr ,int value){
    
    if(arr->lastindex+1==arr->capicity){
        // printf("unsufficient sapce \n");
        dublearray(arr);
         arr->ptr[arr->lastindex+1]=value;
        arr->lastindex++;
    }else{
        arr->ptr[arr->lastindex+1]=value;
        arr->lastindex++;
    }
    complete(arr);

}

void delete(struct MyarrayADT *arr ,int index){
        int i;
        if(index<0 || index>arr->lastindex+1){
            printf("invalid index \n");
        }else{
            
        for(i=index; i<arr->lastindex+1; i++){

             arr->ptr[i]=arr->ptr[i+1];
            }
             arr->lastindex--;   
        }
        complete(arr);
}

void update(struct MyarrayADT *arr,int index,int value){
     
    if(index<0 || index> arr->lastindex+1){
     
        printf("envalid index \n");
    }else{
        arr->ptr[index]=value;

    }
    complete(arr);

}

int search(struct MyarrayADT *arr ,int value){
    int i;
    for (i = 0; i < arr->lastindex+1; i++)
    {
        if(arr->ptr[i]==value){
            
            return i;
        }else{
             printf("invalid index \n");
            return -1;
        }

    }


}

int totalintem(struct MyarrayADT *arr){
    
    return arr->lastindex+1;
    
}
int getitem(struct MyarrayADT *arr,int index){
    int i;
    if(index<0 || index > arr->lastindex+1){
        printf("invalid index \n");
        return -1;
    }else{

         for (i = 0; i < arr->lastindex; i++){
            if(i==index){
                return arr->ptr[i];
            }

        }

    }
}


void printarray(struct MyarrayADT *arr){
     int i;
     for(i=0; i<arr->capicity; i++){
            printf("%d \t",arr->ptr[i]);
        }
           complete(arr);
}


void dublearray(struct MyarrayADT *arr){
    int *a,i;
    // arr->ptr= (int *)-(arr->ptr,arr->capicity*sizeof(int));
    
    a= (int *)malloc((arr->capicity+arr->capicity)*sizeof(int));
    for(i=0; i<arr->capicity; i++){
        a[i]=arr->ptr[i];
    }
    arr->ptr=a;
    arr->capicity= arr->capicity+arr->capicity;
}
void printsize(struct MyarrayADT *arr){
    
    printf("the capicity %d \n",arr->capicity);
    complete(arr);
}

void halfarray(struct MyarrayADT *arr){
    int *a,i;
    
    if(arr->lastindex<(arr->capicity/2)){
        a= (int *)malloc((arr->capicity/2)*sizeof(int));
        for(i=0; i<arr->capicity; i++){
            a[i]=arr->ptr[i];
        }
        arr->ptr=a;
        arr->capicity= arr->capicity/2;
    }
    

     complete(arr);
}


void relallcatememory(struct MyarrayADT *arr,int newcapicity){
     int i;
     if(newcapicity<arr->lastindex ){
           arr->capicity= newcapicity;
           arr->ptr= (int *)realloc(arr->ptr,newcapicity*sizeof(int));
     }else{
        printf("not possible");
     }
    complete(arr);
}