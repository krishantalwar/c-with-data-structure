#include<stdio.h>
#include<conio.h>

void main(){
    int i=1,*p,**t;
    // clrscr();
    p=&i;
    printf("i value  = %d \n", &i);
    printf("p value after intalize= %d \n",p);
    printf("p value after with *= %d \n",*p);
    printf("p value  = %d \n", &p);
     printf("p value  *= %d \n", &(*p));
    t=&p;
    printf("t value after without *= %d \n",t);
    printf("t value after = %d \n", &t); 
    printf("t value after with *= %d \n",*t);
   
    printf("t value after  = %d \n",&(*t));
    printf("t value after  = %d \n",&(**t));

    getch();
}