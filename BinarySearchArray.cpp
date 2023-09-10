#include<iostream>
#include<stdio.h>

struct Array{
    int A[10];
    int size;
    int length;
};
int BinarySearch(struct Array arr,int key){
    int l= 0; 
    int h= arr.length-1;
    int mid;

    while(l <= h)
    {
        mid=(l+h)/2;
        if(key == arr.A[mid])
            return mid;
        else if(key > arr.A[mid])
            l=mid+1;
        else
            h=mid-1;
    }
    return -1;
}
int main(){
    struct Array arr={{5,8,9,12,16,19,23,28,32,43},10,10};
    printf("%d\n",BinarySearch(arr,43));
}