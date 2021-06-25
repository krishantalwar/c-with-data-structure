#include<stdio.h>
#include<conio.h>

struct Temp{
    int max;
    int min;
    // char city[10]
};
 
int minAvg(struct Temp d[],int totaldays);
int maxAvg(struct Temp d[],int totaldays);

void main(){
    struct Temp d[5];
    int i;

    for(i=0; i<5; i++){

        printf("enter the min tempurature of ");
        scanf("%d",&d[i].min);
        printf("enter the max tempurature of ");
        scanf("%d",&d[i].max);
    }
 

    minAvg(d,5);
    maxAvg(d,5);

}

int minAvg(struct Temp d[],int totaldays){
    int i,summin=0;
        for(i=0; i<5; i++){

        summin+=d[i].min;
    }

    printf("%d",summin/5);

}

int maxAvg(struct Temp d[],int totaldays){
    
    int i,summax=0;
        for(i=0; i<5; i++){

        summax+=d[i].max;
    }

    printf("%d",summax/5);
}