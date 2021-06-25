#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void main(){
    int i,n,*ptr;
    printf("ender the no of eelment u want to insert ");
    scanf("%d",&n);
    // printf("%d ", 6);
    ptr=(int*)malloc(2 * sizeof(int));
    printf("%d",ptr);
    for(i=0; i<n; i++){
        scanf("%d",ptr+i);
    }
    printf("sdfds");
     printf("%d",ptr[1]);
    printf("sdfds");
    printf("%u",*ptr);
}

