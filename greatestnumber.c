#include<stdio.h>
#include<conio.h>

int maxValue(int a[]);
int avg(int a[]);
void main(){
int a[6],i,temp=0,avgr;
    printf("dddddddddddddd ");
    a[2]=5;
    a[4]=6;
    a[3]=7;
        printf("%d",sizeof(a)/sizeof(int));
                printf("%d \t",sizeof(a[0]));
        printf("%d",sizeof(a)/sizeof(a[0]));
        
    // printf("%d ", 6);
    for(i=0; i<6; i++){
        scanf("%d",&a[i]);
    }

    
    temp=maxValue(a);
    avgr=(float)avg(a);
    // for(i=0; i<sizeof(a)/sizeof(int); i++){
    //     if(a[i]>temp){
    //         temp=a[i];
    //         size=i;
    //     }
    // }
    printf("%d \t",temp);
    printf("%d \t",avgr);
    // printf("%d",size);
}

int maxValue(int a[]){
    int temps,i;
    temps=a[0];
    for(i=0; i<6; i++){
        if(a[i]>temps){
            temps=a[i];   
        }
    }

    return temps;
}

int avg(int a[]){
    int sum=0,i;
    for(i=0; i<6; i++){
        sum+=a[i];
   
    }
    sum=sum/6;
   
 

    return sum;
}
