#include <bits/stdc++.h>
using namespace std;
#define n 100
class Queue{
    int*a;
    int front;
    int rear;
    public:
    Queue(){
        a= new int[n];
       front=-1;     
        rear=-1;
    }
    void push(int x){
        if(rear==n-1){
            cout<<"overflow";
        }
        rear++;
        a[rear]=x;
        if(front==-1)
        front++;
    }
    void pop(){
        if(front==-1 || front>rear)
        {cout<<"underflow";
        return;}
        front++;
    }
    int peek(){
        if(front==-1 || front>rear)
        {cout<<"underflow";
        return -1;}
        return a[front];
    }
    bool empty(){
        if(front==-1 || front>rear){
            return true;
        }
        else
        return false;
    }
    void display(){
        for(int i=front;i<=rear;i++)
        cout<<a[i]<<" ";
    }
};
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	Queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.display();
	q.pop(); cout<<"\n";
	q.display();
	cout<<"\n"<<q.peek();
	return 0;
}
