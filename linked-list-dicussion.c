#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
  int item;
  struct node *next;
};

void print(struct node **st){
    struct node *start;
    start=*st;
    for (int i = 0; start!=NULL; i++){
        printf("the value is =%d \n",start->item);
            start=start->next;
    }

} 

void insertlastnode(int data,struct node **s)
{
    struct node *n;
    n=(struct node*)malloc(sizeof (struct node));
    n->item=data;
    n->next=NULL;
    if(*s==NULL)
        *s=n;

    else
    {
        struct node *t;
        t=*s;
        while(t->next!=NULL)
            t=t->next;
        t->next=n;
    }
}
void insertfirstnode(int data,struct node **s)
{
    struct node *n;
    n=(struct node*)malloc(sizeof (struct node));
    n->item=data;
    n->next=*s;
    *s=n;
}
void insertnode_aftergiven_node(int data,struct node *t1)
{
    struct node *n;
    n=(struct node*)malloc(sizeof (struct node));
    n->item=data;
    n->next=t1->next;
    t1->next=n;
}

struct node* search_node(struct node **s,int data)
{
  struct node *t;
 
  if(*s==NULL)
     return NULL;
    
  else
   {  
     t= *s;
  while(t!=NULL)
     {
      if(t->item==data)
        return t;
        t=t->next;
     }
  }
  return ((struct node*)0);
}
int count_node(struct node **s)
{
    if(*s==NULL)
    return 0;
    else
    {
    struct node *t;
    int cout=1;
    t=*s;
    while(t->next!=NULL)
    {
        cout++;
        t=t->next;
    }
    return cout;
    }

}

void show_list_elements(struct node **start)
{
    struct node *t;
    t=*start;
    while(t->next!=NULL)
    {
        if(start!=NULL)
        {
        printf("%d %d ",t->item,t->next);
        t=t->next;
        }
        else
         printf("underflow");
    }
}

   int menu()
{
     int choice;

   printf("\n 1.insertlastnode");
   printf("\n 2.insertfirstnode");
   printf("\n 3.insertnode_aftergiven_node");
   printf("\n 4.exit");
   printf("\n 5. for print");

   printf("\n enter your choice\n");
   scanf("%d",&choice);
   return choice;
}
int main()
{
     int data,old_data;
    struct node *start=NULL;
    struct node *t1=NULL;
    while(1)
    {

   switch(menu())
   {
    case 1:

    printf("\n\n enter value of data\n");
    scanf("%d",&data);
    insertlastnode(data,&start);

   break;

    case 2:
    printf("enter value of data\n");
    scanf("%d",&data);
    insertfirstnode(data,&start);
    break;

    case 3:

    printf("enter data after which you have to insert\n");
    scanf("%d",&old_data);
    t1 = search_node(&start,old_data);
     if(t1==NULL)
        printf(" \n node is empty :");
     else if(t1==((struct node*)0))
        printf("\n your enter data not in link list: ");
     else 
     {
      printf("enter value of data\n");
      scanf("%d",&data);
     }
    insertnode_aftergiven_node(data,t1);

    break;


   case 4:
    printf("press any key to exit");
    getch();
    exit(0);
    case 5:
        print(&start);
    break;

    default:

    printf("invalid choice.retry");


   }
   getch();
}
    return 0;

}





    
    





    