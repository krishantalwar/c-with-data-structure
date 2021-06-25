#include<stdio.h>
#include<conio.h>
#include <stdlib.h>

struct Myarray{
    int a[10];
    int validindex;
    int count;
};
 
int insert(int index,int value);
int update(int index,int value);
int delete(int index);
void complete();
    struct Myarray mydata;
void main(){
    mydata.validindex=0;
    mydata.count=0;
    // int validindex=;
    complete();
    

}

void complete(){
    int n=0,index,value;

    printf("enter 1 for insert");
    printf("enter 2 for delete");
    printf("enter 3 for update");
    printf("enter 4 for continoue");
    printf("enter 5 for exit");
    scanf("%d",&n);

    if(n==1){
         printf("enter the index");
         scanf("%d",&index);
        printf("enter the value");
         scanf("%d",&value);

        insert(index,value);

    }else if(n==2){
        printf("enter the index");
         scanf("%d",&index);

        delete(index);
    }else if(n==3){
        printf("enter the index");
        scanf("%d",&index);
        printf("enter the value");
        scanf("%d",&value);
        update(index,value);
        
    }else if(n==4){
         complete();
    }else if(n==5){
        exit(0);
    }else{
        printf("enter wrong input");
    }
}

int insert(int index,int value){
    int i;

    if(mydata.count <10){

        if(index<=mydata.validindex){

            if(index==mydata.validindex){

               mydata.a[index]=value;
                mydata.validindex++;
                mydata.count++;
            
            }else{
                for(i=mydata.validindex; i>=index; i--){
                    if(i!=index){

                        mydata.a[i]=mydata.a[i-1];
                    }else{
                        mydata.a[i]=value;
                        mydata.validindex++;
                        // printf("mydata validindex %d",mydata.validindex);
                        mydata.count++;
                       
                    }
                }
                
            }


        }else{
            printf("invalid index");
        }

    }else{
        printf("unsfficient space");
    }
        for(i=0; i<10; i++){
            printf("%d \t",mydata.a[i]);
        }
        complete();


}


int update(int index,int value){
    int i;
    if(index<=mydata.validindex){
        mydata.a[index]=value;
    }else{
        printf("not valid index");
    }
    for(i=0; i<10; i++){
            printf("%d \t",mydata.a[i]);
        }
    complete();
}

int delete(int index){
    int i;
    if(index<=mydata.validindex){
        for(i=index; i<mydata.validindex; i++){
                mydata.a[i]=mydata.a[i+1];
        }
        mydata.count--;
        mydata.validindex--;
    }
    if(mydata.validindex==-1){
        mydata.validindex=0;
    }
    for(i=0; i<10; i++){
            printf("%d \t",mydata.a[i]);
        }
    complete();
}
