![post.png](https://github.com/llllllllr/im-ved/blob/master/post.png?raw=true)

```c
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int* pre;int* In;
int flag=0;
typedef int ElementType;
typedef struct Snode* Stack;



struct Snode{
    int stackTop;
    int maxSize;
    ElementType * data;
};

Stack createStack(int maxsize){
    Stack stk=(Stack)malloc(sizeof(Stack));
    stk->data= (ElementType*)malloc(sizeof(ElementType)*maxsize);
    stk->stackTop=-1;
    stk->maxSize=maxsize;
    return stk;
}

bool isFull(Stack stk)
{
    return stk->stackTop==stk->maxSize-1;
}

bool isEmpty(Stack stk){
    return stk->stackTop==-1;
}

bool push(Stack stk,ElementType e)
{
    if(isFull(stk))
        return false;
    else
     stk->data[++stk->stackTop]=e;
    return true;
}

ElementType pop(Stack stk)
{
    return stk->data[stk->stackTop--];
}

void post(int root,int start,int end) {
    if(start>end) return;
    int i=start;
    while(i<end && pre[root]!=In[i]) i++;
    post(root+1,start,i-1);
    post(root+1+i-start,i+1,end);
    if(!flag)
    {
        printf("%d",pre[root]);
        flag=1;
    }
    else
    printf(" %d",pre[root]);
}
int main(){
    int N,k=0,j=0;
    char s[10];
    ElementType val;
    scanf("%d",&N);
    Stack stk = createStack(N);
    pre = (int*)malloc(sizeof(int)*N);
    In = (int*)malloc(sizeof(int)*N);
    for(int i=0;i<2*N;i++)
    {
        
		scanf("%s",s);
        if(s[1]=='u')
        {
            scanf("%d",&val);
            push(stk,val);
            pre[k++]=val;
        }
        else{
            In[j++]=pop(stk);
        }
    }
    post(0,0,N-1);
    return 0;
}
```

