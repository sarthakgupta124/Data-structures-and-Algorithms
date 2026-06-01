#include <iostream>
using namespace std;
#include <queue>
class Queue{
    int f,b;
    int arr[5];
public:
    Queue(){
        f=0;
        b=0;
    }
    void push(int val){
        if(b==5) {
            cout<<"Oueue is Full"<<endl;
            return;
        }
        arr[b]=val;
        b++;
    }
    void pop(){
        if(b-f==0){
            cout<<"Empty Oueue"<<endl;
            return;
        }
        for(int i=f;i<b;i++){ // this loop solves the problem of the poping the element
            arr[i]=arr[i+1];

        }

        b--;

    }
    int back(){
        if(b-f==0){
            cout<<"Empty Oueue"<<endl;
            return -1;
        }
        return arr[b-1];

    }
    int top(){
        if(b-f==0) return -1;
        return arr[f];
    }
    void display(){
        for(int i=f;i<b;i++) cout<<arr[i]<<" ";
        cout<<endl;
        return;
    }
};
int main(){
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.display();
    q.push(40);
    q.push(50);
    q.display();
    q.push(60);
    q.pop();
    q.display();
    q.push(60);
    q.display();
    return 0;
}
//Problems in array implementation
//1.while pop the spaces are not being deleted they cant be used to push again unlike in queues
//2.solution is circular array or loop impliented above