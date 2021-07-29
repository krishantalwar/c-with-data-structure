#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{ 
    struct node *prev;
    int item;
    struct node *next;
};
void insertatfirst(struct node **start,int value);
void insertatlast(struct node **start,int value);
void menue(struct node **s);
void print(struct node **start);
void deleteatfirst(struct node **start);
void deleteatlast(struct node **start);
void deleteatposition(struct node **start,int index);

int main(){
    struct node *start=NULL;
    menue(&start);
}