#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{ 
    int item;
    struct node *next;
};
void insertatfirst(struct node **last,int value);
void insertatlast(struct node **last,int value);
void menue(struct node **s);
void print(struct node **last);
void deleteatfirst(struct node **last);
void deleteatlast(struct node **last);
void deleteatposition(struct node **last,int index);

int main(){
    struct node *last=NULL;
    // printf("the *last \n",*last);
    printf("the *last %d\n ",last);
    printf("the *last %d\n",&(*last));
    printf("the *last %d\n",&last);
    menue(&last);
}
void menue(struct node **last){
    int n,index, value;
    // printf("the *menue \n",*last);
    printf("the *menue %d\n",last);
    printf("the *menue %d\n",&(*last));
    printf("enter 0 for print \n");
    printf("enter 1 for insert at first \n");
    printf("enter 2 for insert at last \n");
    printf("enter 3 for insert at postion \n");
    printf("enter 4 for insert after with postion \n");
    printf("enter 5 for delete first \n");
    printf("enter 6 for delete last \n");
    printf("enter 7 for delete after with postion\n");
    printf("enter 8 for sort linkedlist\n");
    printf("enter your choise \n");
    scanf("%d",&n);
    if(n==1){
        printf("enter the value");
        scanf("%d",&value);
        insertatfirst(last,value);
    }

}

void print(struct node **last){
    struct node *t;
    int i;
    t=(*last)->next;
    for(i=0; t!=(*last); i++){
        printf("%d",t->item);
        t=t->next;
    }
    menue(last);
}


void insertatfirst(struct node **last,int value){
    struct node *new;
    new=(struct node *)malloc(sizeof(struct node *));
    new->item=value;
    if(*last==NULL){
        new->next=new;
        *last=new;
    }else{
        new->next=(*last)->next;
        (*last)->next=new;
    }
    menue(last);
}

void insertatlast(struct node **last,int value){
    struct node *new;
    new=(struct node *)malloc(sizeof(struct node *));
    new->item=value;
   if((*last)==NULL){
       new->next=new;
       *last=new;
   }else{
       new->next=(*last)->next;
       (*last)->next=new;
       *last=new;
   }
    menue(last);
}

void deleteatfirst(struct node **last){
    struct node *t;
    t=(*last)->next;
    if((*last)==NULL){
        printf("nothing to delete");
    }else if((*last)==(*last)->next){
        *last=NULL;
    }else{
        (*last)->next=t->next;
    }
    free(t);
    menue(last);
}


void deleteatlast(struct node **last){
    struct node *t,*s;
    int i;
    t=*last;
    s=*last;
    if(t==NULL){
        printf("nothing to delete");
    }else if((*last)==(*last)->next){
        *last=NULL;
    }else{
        for(i=0; t->next!=(*last); i++){
            t=t->next;
        }
        t->next=(*last)->next;
        *last=t;
    }
    free(s);
    menue(last);
}




void deleteatposition(struct node **last,int index){
    struct node *t,*r;
    int i=0;
    if((*last)!=NULL){
        t=(*last)->next;
        if(index==0){
            deleteatfirst(last);
        }else{
            for(i=0; i<index-1; i++){
                t=t->next;
            }
            if(i=index-1){
                if(t->next==(*last)){
                    deleteatlast(last);
                }else{
                    r=t->next;
                    t->next=t->next->next;
                    free(r);
                }
            }
        }
    }else{
        printf("nothing to delete \n");
    }
    menue(last);
}