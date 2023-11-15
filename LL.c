#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
}*first=NULL,*last,*second=NULL,*third=NULL;

void create1(int arr[],int n){
    int i;
    struct Node *t;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=arr[0];
    first->next=NULL;
    last=first;
    
    for(int i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=arr[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void create2(int arr[],int n){
    int i;
    struct Node *t;
    second=(struct Node*)malloc(sizeof(struct Node));
    second->data=arr[0];
    second->next=NULL;
    last=second;
    
    for(int i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=arr[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
int count(struct Node *p){
    int l=0;
    while(p){
        l++;
        p=p->next;
    }
    return l;
}

void Display(struct Node *p)
{
    while(p!=NULL){
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("\n");
}
int sum(struct Node *p){
int total=0;
while(p){
    total=total+p->data;
    p=p->next;
}
return total;
}
int max(struct Node *p){
    int max=p->data;
    while(p){
        if(max<p->data){
            max=p->data;
        }
        p=p->next;
    }
    return max;
    }
    void search(struct Node *p,int element){
        while(p){
            if(element==p->data){
                printf("The element is present\n");
                break;
            }
            p=p->next;
        }
        printf("The value is not present\n");

    }
    void insert(struct Node *p,int index,int x){
        struct Node *t;
        if(index<0 || index>count(p)){
            return;
        }
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=x;
        if(index==0){
            t->next=first;
            first=t;
        }
        else{
            for(int i=0;i<index-1;i++){
                p=p->next;
            }
                t->next=p->next;
                p->next=t;
            
        }
    }
    void InsertEnd(struct Node *p,int x){
        struct Node *t;
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=x;
        t->next=NULL;
        if(first==NULL){
            first=last=t;
        }
        else{
            last->next=t;
            last=t;
        }
    }
   void insertsorted(struct Node *p, int x) {
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if (p->data > x) {
        t->next = p;
        first = t;
    } else {
        while (p->next != NULL && p->next->data < x) {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

    int delete(struct Node *p,int index){
        struct Node *q;
        int x=-1,i;
        if(index<1 || index>count(p)){
            return -1;
        } 
          if(index==1){
                q=first;
                x=first->data;
                first=first->next;
                free(q);
                return x;
            }
            else{
                for(int i=0;i<index-1;i++){
                    q=p;
                    p=p->next;
                }
                q->next=p->next;
                x=p->data;
                free(p);
                return x;

            }
        }
        int checksort(struct Node *p){
            int x=-65536;
            while(p!=NULL){
                if(p->data<x){
                    return -1;
                }
                x=p->data;
                p=p->next;
            }
            return 1;
        }
        void reverse(struct Node*p){
            struct Node*q=NULL,*r=NULL;
            while(p!=NULL){
                r=q;
                q=p;
                p=p->next;
                q->next=r;
            }
            first=q;
        }
        void merge(struct Node*p,struct Node*q){
            if(p->data<q->data){
                third=last=first;
                p=p->next;
                last->next=NULL;
            }
             else{
                third=last=first;
                q=q->next;
                last->next=NULL;
            }
            while(p && q){
                if(p->data<q->data){
                    last->next=p;
                    last=p;
                    p=-p->next;
                    last->next=NULL;
                }
                else{
                    last->next=q;
                    last=q;
                    q=-q->next;
                    last->next=NULL;
                }

            }
        }
int main(void){
    int arr[]={5,7,8,9,10};
    int arr2[]={11,12,13,14,15};
    create1(arr,5);
    create2(arr2,5);
    Display(first);
    Display(second);
    printf("\n");
    printf("The number of elements are %d\n",count(first));
    printf("The sum of all the numbers in the linked list is %d\n",sum(first));
    printf("The max value is %d",max(first));
    printf("The value to be searched was 7 , is it there?\n");
    search(first,2);
    insert(first,0,4);
    Display(first);
    InsertEnd(first,11);
    Display(first);
    insertsorted(first,6);
    Display(first);
    printf("%d",checksort(first));
    reverse(first);
    Display(first);
}

