#include <iostream>
using namespace std;

template <class T>
class Array
{
private:
    T *A;
    int size;
    int length;

public:
    Array()
    {
        A = new T[10];
        size = 10;
        length = 0;
    }
    Array(int sz)
    {
        size = sz;
        A = new T[size];
        length = 0;
    }
    ~Array()
    {
        delete[] A;
    }
    void Display();
    void Insert(int index, int value);
    T Delete(int index);
};
template<class T>
void Array<T>::Display()
{
    for (int i = 0; i < length; i++)
    {
        cout<<A[i]<< " ";
    }
}
template<class T>
void Array<T>::Insert(int index, int value)
{
    if (index >= 0 && index <= length)
    {
        for (int i = length - 1; i >= index; i--)
        {
            A[i+1] = A[i];
        }
        A[index] = value;
        length++;
    }
}
template<class T>
T Array<T>::Delete(int index)
{
    T x = A[index];
    if(index >= 0 && index < length )
    {
        for(int i = index; i < length ; i++){
            A[i] = A[i+1];
        }
        length--;
    }
    return x;
}
int main()
{
    Array<char> arr(6);
    arr.Insert(0,'a');
    arr.Insert(1,'d');
    arr.Insert(2,'g');
    arr.Insert(3,'v');
    arr.Insert(4,'c');
    arr.Insert(5,'n');
    arr.Delete(3);
    arr.Display();   

}