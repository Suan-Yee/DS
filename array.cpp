#include <stdio.h>
#include <iostream>

struct Arrays
{
    int A[20];
    int length;
    int size;
};
void display(struct Arrays arr)
{
    int x;
    printf("Printing Elements from Array");
    for (x = 0; x < arr.length; x++)
    {
        printf("%d ", arr.A[x]);
    }
}
void append(struct Arrays *arr, int x)
{
    if (arr->length < arr->size)
    {
        arr->A[arr->length++] = x;
    }
}
void insert(struct Arrays *arr, int index, int x)
{
    int i;
    if (index >= 0 && index <= arr->length)
    {
        for (i = arr->length; i > index; i--)
            arr->A[i] = arr->A[i - 1];
        arr->A[index] = x;
        arr->length++;
    }
}
int Delete(struct Arrays *arr, int index)
{
    {
        int x = 0;
        int i;
        if (index >= 0 && index < arr->length)
        {
            x = arr->A[index];
            for (i = index; i < arr->length - 1; i++)
                arr->A[i] = arr->A[i + 1];
            arr->length--;
            return x;
        }
        return 0;
    }
}

int main()
{

    struct Arrays arr = {{1, 4, 6, 3, 8}, 5, 20};

    append(&arr, 9);
    insert(&arr, 2, 7);
    Delete(&arr,2);
    display(arr);
    return 0;
}