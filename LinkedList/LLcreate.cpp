#include<iostream>
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;

void create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(i = 1; i< n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
};
void create2(int B[],int n)
{
    int i;
    struct Node *t,*last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = B[0];
    second->next = NULL;
    last = second;

    for(i = 1; i< n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = B[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
};
void Display(struct Node *p)
{   
    while(p!= NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
void RDisplay(struct Node *p)
{
    if(p!= NULL)
    {
        RDisplay(p->next);
        printf("%d ",p->data);
    }
}
int length(struct Node *p)
{
    int l = 0;
    while(p)
    {
        l++;
        p=p->next;
    }
    return l;
}
int Sum(struct Node *p)
{
    int sum = 0;
    while(p)
    {
        sum = sum + p->data;
        p = p->next;
    }
    return sum;
}
int Max(struct Node *p)
{
    int m = -32768;
    while(p)
    {
        if(p->data > m){
            m = p->data;
        }
        p = p->next;
    }
    return m;

}
Node* Search(struct Node *p,int key)
{
    Node *q;
    while(p)
    {
        if(p->data == key)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }                    
    return NULL;
}
int Delete(int pos)
{
    Node *p,*q;
    int x;

    if(pos == 1)
    {
        x = first->data;
        p = first;
        first = first->next;
        delete p;
    }
    else{
        p = first;
        q = NULL;
        for(int i =0; i < pos-1; i++)
        {
            q = p;
            p = p->next;
        }
        if(p){
            q->next = p->next;
            x = p->data;
            delete p;
        }
    }
    return x;
}
bool check_LL_isSorted()
{
    Node *p;
    int m = -32678;
    p=first;

    while(p){
        if(p->data < m){
            return false;
        }
        m = p->data;
        p = p->next;
    }
    return true;
}
void remove_duplicate_e_inSortedLL()
{
    Node *p = first;
    Node *q = first->next;

    while(q != NULL)
    {
        if(q->data != p->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}
void concat(Node *p,Node *q){
    third = p;
    while(p->next != NULL){
        p=p->next;
    }
    p->next = q;
}
void merge(Node *p,Node *q){
    struct Node *last;

    if(p-> data < q->data){
        third=last=p;
        p = p->next;
        third->next = NULL;
    }else{
        third=last=q;
        q = q->next;
        third->next = NULL;
    }
    while( p && q){
        if(p-> data < q->data){
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }else{
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if(p) last->next = p;
    if(q) last->next = q;
}
int main()
{
    struct Node *temp;
    int A[]={2, 5, 8, 12, 15, 18, 21, 24, 27};
    create(A,9);
    // printf("\n");
    // printf("Sum = %d \n",Sum(first)); 
    // printf("length = %d \n",length(first)); 
    // printf("Max = %d \n",Max(first));
    // printf("Search = %d \n",Search(first,43)); 
    // Display(first); 
    // printf("Delete the Number = %d\n",Delete(4));
    // printf("%d\n",check_LL_isSorted());
    // printf("\n");
    // printf("\n");
    // remove_duplicate_e_inSortedLL();
    // printf("\n");
    Display(first);
    printf("\n");
    int B[]={ 3, 7, 11, 14, 17, 20, 23, 26, 30};
    create2(B,9);
   
    Display(second);
    concat(first,second);
    printf("\n");

    merge(first,second);
    Display(third);

    return 0;


}