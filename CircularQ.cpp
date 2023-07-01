#include<iostream>
using namespace std;
class CircularQueue
{
    int q[5];
    int front;
    int rear;
    int size;

    public:
    CircularQueue()
    {
        front=-1;
        rear=-1;
        size=5;

    }

    void Enqueue(int v)
    {
        if((rear+1)%size==front)
        cout<<"queue overflow...!"<<endl;
        else if(rear==-1)
        {
            rear++;
            front++;
            q[front]=v;
        }
        else
        {
            rear=(rear+1)%size;
            q[rear]=v;

        }


    }

    void Dequeue()
    {
        if(front==-1)
        cout<<"queue underflow"<<endl;
        else if(front==rear)
        {
            cout<<q[front]<<"deleted"<<endl;
            rear=-1;
            front=-1;
        }
        else
        {
            cout<<q[front]<<"deleted"<<endl;
            front=(front+1)%size;

        }
    }

    void printQueue()
    {
        if(rear==-1)
        cout<<"queue is empty"<<endl;
        int i=front;
        while(1)
        {

            cout<<q[i]<<" ";
            if(i==rear)
            break;
            i=(i+1)%size;
        }
        cout<<endl;
    }


};
int main()
{
    CircularQueue q1;
    int choice;
    while(1)
    {
    cout<<"1. enqueue"<<endl;
    cout<<"2. dequeue"<<endl;
    cout<<"3. print"<<endl;
    cout<<"4. exit"<<endl;
    cout<<"enter your choice"<<endl;
    cin>>choice;

    switch(choice)
    {
        case 1:
        int v;
        cout<<"enter no."<<endl;
        cin>>v;
        q1.Enqueue(v);
        break;

        case 2:
        q1.Dequeue();
        break;

        case 3:
        q1.printQueue();
        break;


        case 4:
        exit(0);
        break;
    }
    }

    return 0;

}