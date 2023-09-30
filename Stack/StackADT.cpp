#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int size;
    int Top;
    int *s;
};
void create(struct Stack *st)
{
    // printf("Enter the size of the element");
    // scanf("%d",&st->size);
    st->size = 7;
    st->Top = -1;
    st->s = (int *)malloc(st->size * sizeof(int));
}
void display(struct Stack st)
{
    for(int i = st.Top; i >= 0; i--)
    {
        printf("%d ",st.s[i]);
        
    }
    printf("\n");
}
void push(struct Stack *st,int x)
{
    if(st->Top == st->size-1){
        printf("Stack overflow");
    }else{
        st->Top++;
        st->s[st->Top] = x;
    }
}
int pop(struct Stack *st)
{
    int x;
    if(st->Top == -1){
        return -1;
    }else{
        x = st->s[st->Top];
        st->Top--;
    }
    return x;
}
int peek(struct Stack st,int pos)
{
    int x = -1;
    if(st.Top-pos+1 < 0){
        printf("Invalid Position");
    }else{
        x = st.s[st.Top - pos+1];
        return x;
    }
}
bool isEmpty(struct Stack st)
{
    if(st.Top == -1){
        return true;
    }else{
        return false;
    }
}
bool isFull(struct Stack st)
{
    if(st.Top == st.size - 1){
        return true;
    }else{
        return false;
    }
}
int stackTop(struct Stack p)
{
    if(p.Top == -1){
        return -1;
    }else{
        return p.s[p.Top];
    }
}

int main()
{
    struct Stack p;
    create(&p);

    push(&p,34);
    push(&p,12);
    push(&p,45);
    push(&p,76);
    push(&p,5);
    push(&p,98);
    push(&p,8);

   // pop(&p);
    printf("%d \n",peek(p,4));
    printf("%d \n",stackTop(p));
    printf("%d \n",isFull(p));
    printf("%d \n",isEmpty(p));


    display(p);
}