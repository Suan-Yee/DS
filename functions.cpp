#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[20];
    int length;
    int size;
};
void swap(int *x,int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void display(struct Array arr)
{
    int x;
    printf("Printing Elements from Array");
    for (x = 0; x < arr.length; x++)
    {
        printf("%d ", arr.A[x]);
    }
}
int Get(struct Array arr, int index)
{
    if (index > 0 && index < arr.length)
    {
        int x = arr.A[index];
        return x;
    }

    return -1;
};
void Set(struct Array *arr, int index, int x)
{
    if (index > 0 && index < arr->length)
    {
        arr->A[index] = x;
    }
}
int Max(struct Array arr)
{
    int max = arr.A[0];
    int i;
    for (i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
            max = arr.A[i];
    }
    return max;
}
int Min(struct Array arr)
{
    int min = arr.A[0];
    int i;
    for (i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < min)
            min = arr.A[i];
    }
    return min;
}
int Sum(struct Array arr)
{
    int s = 0;
    int i;
    for (i = 0; i < arr.length; i++)
    {
        s = s + arr.A[i];
    }
    return s;
}
float Avg(struct Array arr)
{
    return (float)Sum(arr) / arr.length;
}
void Reverse(struct Array *arr)
{
    int *B;
    int x,j;

    B= (int *)malloc(arr->length*sizeof(int));

    for(x = arr->length-1,j=0; x >=0 ; x--,j++)
    B[j] = arr->A[x];
    for(x = 0; x < arr->length ; x++){
        arr->A[x] = B[x];
    }

}
void Reverse2(struct Array *arr)
{
    int i,j;
    for(i=arr->length-1,j=0; j > i ; j++,i--)
    {
        swap(&arr->A[j],&arr->A[i]);
    }
}
int main()
{

    struct Array arr = {{1, 4, 6, 3, 8}, 5, 20};
    //printf("%d\n", Get(arr, 2));
    // Set(&arr,2,9);
    //printf("%d\n", Max(arr));
    //printf("%d\n", Sum(arr));
    Reverse(&arr);
    display(arr);

    return 0;
}