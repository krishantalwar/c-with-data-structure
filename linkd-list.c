#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int item;
    struct node *next;
};

void menue(struct node **start);
void print(struct node **start);
void insetAtFirst(struct node **start,int value);
void insetAtLast(struct node **start,int value);
void insetAtPostion(struct node **start,int value,int index);
void insetAfterPostion(struct node **start,int value,int index);
void deleteFirst(struct node **start);
void deleteLast(struct node **start);
void deleteNodePostion(struct node **start,int index);
void sortlinkedlist(struct node **start);
void reversedlinkedlist(struct node **start);
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
    printf("enter 9 for revsrse linkedlist\n");
    
    
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
        insetAfterPostion(start,value,index);
    }else if(n==5){      

        deleteFirst(start);
    }else if(n==6){      

        deleteLast(start);
    }else if(n==7){      
        printf("enter the index");
        scanf("%d",&index);
        deleteNodePostion(start,index);
    }else if(n==8){      
        sortlinkedlist(start);
    }else if(n==9){      
        reversedlinkedlist(start);
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

    printf("the value in side menue in st %d\n ",st);
    printf("the  in side menue in st %d\n",*st);
    // printf("the  in side menue in st %d\n ",&(*st));        
    // printf("the address in side menue in st %d\n",&st);
    struct node *new;
    new=(struct node *)malloc(sizeof(struct node));
    new->item=value;
    new->next=*st;
    *st=new;
    menue(st);
}

void insetAtLast(struct node **st,int value){

    printf("the value in side insetAtLast in st %d\n ",st);
    printf("the  in side insetAtLast in st %d\n",*st);
    // printf("the  in side insetAtLast in st %d\n ",&(*st));        
    // printf("the address in side insetAtLast in st %d\n",&st);
    struct node *new,*t;
    new=(struct node *)malloc(sizeof(struct node));
    // printf("the address in side menue in new %d\n",new);
    // printf("the address in side menue in new %d\n",&new);
    new->item=value;
    new->next=NULL;
    if(*st==NULL){
        *st=new;
    }else{
        t=*st;
        for (int i = 0; t->next!=NULL; i++){
            // printf("the value is =%d \n",t->item);
                t=t->next;
        }
        t->next=new;
    }
    menue(st);
}

void insetAfterPostion(struct node **st,int value,int index){
    struct node *new=NULL,*t=NULL;
    int i,count=0;
    new=(struct node *)malloc(sizeof(struct node));
    new->item=value;
    t=*st;
    printf("I inside insetAfterPostion %d \n",t->item);
                // 0<1
    for ( i = 0; i<index; i++){
        if(t!=NULL){
            t=t->next;
            count++;
        }
    }
    if(count>=index){ 
        new->next=t->next;
        t->next=new;
    }else{
        printf("out of bound");
    }

        
    
    menue(st);
}

void insetAtPostion(struct node **st,int value,int index){
    struct node *new=NULL,*t=NULL;
    int i,count=0;
    new=(struct node *)malloc(sizeof(struct node));
    new->item=value;
    t=*st;
    for ( i = 0; i<index-1; i++){
        if(t!=NULL){
            t=t->next;
            count++;
        }
    }    
    if(count>=index-1){ 
        new->next=t->next;
        t->next=new;
    }else{
        printf("out of bound");
    }   
    menue(st);
}


void deleteFirst(struct node **st){
    struct node *start;
    start=*st;
    if(*st){
        *st=start->next;
    }else{
        printf("nothing to delete");
    }
    printf("the  in side insetAtLast in st %d\n ",(*st)->item);       
    free(start);
    menue(st);
}

void deleteLast(struct node **st){

    struct node *start;
    start=*st;

    if (start->next == NULL) {
         *st=NULL;
         free(start);
    }else{
        for (int i = 0; start->next->next!=NULL; i++){
            start=start->next;
        }
        free(start->next);
        start->next=NULL;
    }
    menue(st);
}



void deleteNodePostion(struct node **st,int index){
    struct node *t=NULL,*next;
    int i,count=0;
    t=*st;
    printf("I inside insetAfterPostion %d \n",t->item);
    if (index==0) {
        deleteFirst(st);
    }else{
                // 0<1
        for ( i = 0; i<index-1; i++){
            if(t!=NULL){
                t=t->next;
                count++;
            }
        }

        if(count>=index-1){ 
            next=t->next->next; 
            free(t->next);
            t->next=next;
        }else{
            printf("out of bound");
        }
    }
    menue(st);
}


void sortlinkedlist(struct node **st){
    struct node *t;
    int a,i;
    t=*st;
    for(i=0; t!=NULL; i++){
        if(t->next!=NULL){
            if(t->item>t->next->item){
                a=t->item;
                t->item=t->next->item;
                t->next->item=a;
                t=*st;
            }
        }
        t=t->next;
    }
    menue(st);
}


void reversedlinkedlist(struct node **start){
    struct node *t=NULL,*t1=NULL;
    int i=0;
    if(((*start)->next!=NULL) && ((*start)!=NULL)){
        t=(*start)->next;
        (*start)->next=NULL;
        for(i=0; t!=NULL; i++){
            if(t->next!=NULL){
                t1=t->next;
            }
            t->next=*start;
            *start=t;
            if(t1!=NULL){
                t=t1;
            }else{
                break;
            }
            t1=NULL;
        }        
    }else{
        printf("nothing to reverse");
    }
    menue(start);
}



// 19    0   12   18    9   18   14    9    1   11
// 1,4,2,3,5
// 5,3,2,4,1
