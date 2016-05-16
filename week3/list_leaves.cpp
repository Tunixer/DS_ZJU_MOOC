#include <iostream>
using namespace std;
#define MaxTree 10
#define type int
#define Null -1

struct TreeNode {
    type Left;
    type Right;
}T[MaxTree];

struct QueueNode
{
    type value;
    QueueNode *next=nullptr;
};

struct Queue{
    QueueNode *front=nullptr;
    QueueNode *rear=nullptr;
    int num=0;
};

void PushQueue(int number,Queue& T)
{
    QueueNode *temp=new(QueueNode);
    temp->value=number;
    if (T.num==0) {
        T.front=T.rear=temp;
        
    }else{
        T.rear->next=temp;
        T.rear=temp;
    }
    T.num++;
}

int PopQueue(Queue& T)
{
    if (T.num==0)
    {
        return Null;
    }
    QueueNode *p=T.front;
    type temp=p->value;
    T.front=p->next;
    T.num--;
    delete p;
    return temp;
}

bool IsQueueEmpty(Queue& T)
{
    return (!T.num);
}



int BuildTree(TreeNode []);
void LevelView(int);

int main(int argc, const char * argv[])
{
    //接收输入信息并构建该二叉树
    int Root=BuildTree(T);

    //层次遍历该二叉树，依次输出每一个叶结点的序号
    LevelView(Root);
    
    return 0;
}

int BuildTree(TreeNode T1[])
{
    int N=0,flag[MaxTree],root=0;
    char cleft,cright;
    cin>>N;
    for (int i=0; i<N; ++i) //将flag数组每个值都设置为0，flag数组用来判断二叉树的根结点
    {
        flag[i]=0;
    }
    
    for (int i=0; i<N; ++i)
    {
        cin>>cleft>>cright;
        if (cleft!='-')
        {
            T1[i].Left=cleft-'0';
            flag[T1[i].Left]=1;
        }else{
            T1[i].Left=Null;
        }
        
        if (cright!='-')
        {
            T1[i].Right=cright-'0';
            flag[T1[i].Right]=1;
        }else{
            T1[i].Right=Null;
        }
    }
    
    for (int i=0; i<N; ++i) {
        if (!flag[i])
        {
            root=i;
            break;
        }
    }
    return root;
}

void LevelView(int n)
{
    Queue Q;
    PushQueue(n, Q);
    int flag=0;
    int num_0=0;
    while (!IsQueueEmpty(Q))
    {
        num_0=PopQueue(Q);
        if (T[num_0].Left!=Null) {
            PushQueue(T[num_0].Left, Q);
        }
        if (T[num_0].Right!=Null) {
            PushQueue(T[num_0].Right, Q);
        }
        if ((T[num_0].Left==Null)&&(T[num_0].Right==Null))
        {
            if (flag==0)
            {
                cout<<num_0;
                flag=1;
            }else{
            cout<<' '<<num_0;
            }
        }
    }
    
}

