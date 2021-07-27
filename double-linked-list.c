#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    struct node *prev;    
    int item;
    struct node *next;
};

void menue(struct node **start);
void print(struct node **start);
void insetAtFirst(struct node **start,int value);
void insetAtLast(struct node **start,int value);
void insetAtPostion(struct node **start,int value,int index);
// void insetAfterPostion(struct node **start,int value,int index);
void deleteFirst(struct node **start);
void deleteLast(struct node **start);
// void deleteNodePostion(struct node **start,int index);
void sortlinkedlist(struct node **start);

void main(){
    struct node *start=NULL;
    printf("the value in start %d\n",start);
    printf("the address in start %d\n",&start);
    menue(&start);
    getch();  
}


void menue(struct node **start){

    printf("the value in side menue in start %d\n  ",start);
    printf("the  in side menue in start %d\n",*start);
    printf("the  in side menue in start %d\n ",&(*start));        
    printf("the address in side menue in start %d\n",&start);

    int n,index,value,result,i;
    printf("enter 0 for print \n");
    printf("enter 1 for insert at first \n");
    printf("enter 2 for insert at last \n");
    printf("enter 3 for insert at postion \n");
    printf("enter 4 for insert after with postion \n");
    printf("enter 5 for delete first \n");
    printf("enter 6 for delete last \n");
    printf("enter 7 for delete after with postion\n");
    printf("enter 8 for sort linkedlist\n");
    
    
    printf("enter any  other thing  for exit");
    scanf("%d",&n);
    if(n==0){
          print(start);
    }else if(n==1){      
        printf("enter the value");
        scanf("%d",&value);
        insetAtFirst(start,value);
    }else if(n==2){      
        printf("enter the value");
        scanf("%d",&value);
        insetAtLast(start,value);
    }else if(n==3){      
        printf("enter the value");
        scanf("%d",&value);
        printf("enter the index");
        scanf("%d",&index);
        insetAtPostion(start,value,index);
    }else if(n==4){      
        printf("enter the value");
        scanf("%d",&value);
        printf("enter the index");
        scanf("%d",&index);
        // insetAfterPostion(start,value,index);
    }else if(n==5){      

        deleteFirst(start);
    }else if(n==6){      

        deleteLast(start);
    }else if(n==7){      
        printf("enter the index");
        scanf("%d",&index);
        // deleteNodePostion(start,index);
    }else if(n==8){      
        sortlinkedlist(start);
    }else{
        exit(0);
    }
}

void print(struct node **st){

    struct node *start;
    start=*st;
    printf("the value print  %d\n ",st);
    printf("the value print  %d\n ",*st);
    printf("the value print  %d\n ",&st);
    for (int i = 0; start!=NULL; i++){
        printf("the value is =%d \n",start->item);
            start=start->next;
    }
       menue(st);
} 

void insetAtFirst(struct node **st,int value){
    struct node *new;
    new=(struct node *)malloc(sizeof(struct node));
    new->prev=NULL;
    new->item=value;
    new->next=*st;
    if(*st==NULL){
        *st=new;
    }else{
        (*st)->prev=new;
        *st=new;
    }
    menue(st);

}

void insetAtLast(struct node **st,int value){
    struct node *new,*t;
    new=(struct node *)malloc(sizeof(struct node));
    new->prev=NULL;
    new->item=value;
    new->next=NULL;
    if(*st==NULL){
        *st=new;
    }else{
        t=*st;
       for (int i = 0; t->next!=NULL; i++)
       {
           t=t->next;
       }
        t->next=new;
        new->prev=t;
    }
    menue(st);
}


void deleteFirst(struct node **st){
    struct node *t;
    t=*st;
    if(t==NULL){
        printf("nothing to delete");
    }else{
        *st=t->next;
        t->next->prev=NULL;
        // (*st)->prev=NULL;
    }
    free(t);
    menue(st);
}

void deleteLast(struct node **st){
    struct node *t,*lastsecond;
    t=*st;
    if(t->next==NULL){
        free(t);
        *st=NULL;
    }else{
        for (int i = 0; t->next!=NULL; i++){
            t=t->next;
        }
        t->prev->next=NULL;
        free(t);
    }
    menue(st);

}


void insetAtPostion(struct node **start,int value,int index){
    struct node *new,*t;
    int i;
    new=(struct node *)malloc(sizeof(struct node));
    new->item=value;
    new->next=NULL;
    new->prev=NULL;
    t=*start;
    for (i = 0; i<index-1; i++){
        if(t!=NULL){
            t=t->next; 
        }
    }
    // printf("%d insertatpostion\n",i);
    if(i==index-1){
    // printf("%d insertatpostion\n",t->item); 
        new->next=t->next;
        new->prev=t;
        t->next=new;
    }else if(index==0){
        new->next=t;
        new->prev=NULL;
        t->prev=new;
        *start=new;
    }else{
        printf("undifined position");
    }
    menue(start);
}

// void insetAfterPostion(struct node **start,int value,int index){

// }
// 5 4
void sortlinkedlist(struct node **start){
    struct node *t;
    int i=0,temp;
    t=*start;
    for (i = 0; t!=NULL; i++)
    {
        if(t->next!=NULL){
            if(t->item>t->next->item){
                temp=t->item;
                t->item=t->next->item;
                t->next->item=temp;
                t=*start;
            }
        }
        t=t->next;
    }
        menue(start);
}
// 1 4 2 3 5

// netweb
// 
