#include<stdio.h>
#include<iostream>


struct Array{
    int A[10];
    int size;
    int length;
};
void swap(int *x,int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int LinearSearch(struct Array *arr,int key){
    int x;
    for(x=0; x < arr->length; x++){
        if(key == arr->A[x]){
            swap(&arr->A[x],&arr->A[x-1]);
            return x;
        }
        
    }
    return -1;
}
int main(){

    struct Array arr={{1,4,6,3,7},10,5};
    printf("%d\n",LinearSearch(&arr,4));

}