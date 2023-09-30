#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
class LinkedList
{
private:
    Node *first;

public:
    LinkedList()
    {
        first = NULL;
    }
    LinkedList(int A[], int n);
    ~LinkedList();
    void Display();
    void Insert(int index, int x);
    int Delete(int index);
    int Length();
};
LinkedList::LinkedList(int A[], int n)
{
    Node *last, *t;

    first = new Node();
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node();
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
LinkedList::~LinkedList()
{
    Node *p = first;
    while (first)
    {
        first = first->next;
        delete p;
        p = first;
    }
}
void LinkedList::Display()
{
    Node * p = first;
    while(p)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}
int LinkedList::Length()
{
    Node *p = first; int x = 0;
    while(p)
    {
        x++;
        p = p->next;
    }
    return x;
}
int LinkedList::Delete(int pos)
{
    int x = -1;
    Node *p,*q;

    if(pos < 1 && pos > Length()){
        return -1;
    }
    if(pos == 1){
            p = first;
            first = first->next;
            delete p;
        }else{
            p = first;
            q = NULL;

            for(int i = 0; i < pos -1 ; i++){
                q = p;
                p->next;
            }
            q->next = p->next;
            x = p->data;
            delete p;
    }
    return x;
}

int main()
{
}