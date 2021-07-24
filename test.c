#include<stdio.h>
#include<conio.h>
void main()
{
    int a[5]={1,4,2,5,3},i,temp=0;
    for(i=0; i<5; i++){
        if(a[i]>a[i+1]){
            temp=a[i];
            a[i]=a[i+1];
            a[i+1]=temp;
            i=-1;
        }
    }
    for(i=0; i<5; i++){
        printf("%d\n",a[i]);
    }
    getch();
}   
