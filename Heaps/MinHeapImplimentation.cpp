#include <iostream>
#include <vector>
using namespace std;
class minheap{
    int arr[50];
    int idx;
public:
    minheap(){
        idx=1;
    }
    int top(){
        return arr[1];
    }
    void push(int ele){
        arr[idx]=ele;
        int temp_idx=idx;
        idx++;
        while(temp_idx>0){
            int parent=temp_idx/2;
            if(arr[parent]>arr[temp_idx]){
                swap(arr[parent],arr[temp_idx]);
            }
            else break;
            temp_idx=parent;
        }
    }
    int size(){
        return idx-1;
    }
    void pr(){
        for(int i=1;i<idx;i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
    void pop(){
        if(idx==1){
            cout<<"heap is empty!"<<endl;
            return;
        }
        else{
            arr[1]=arr[--idx];
            int i=1;
            while(true){
                int c1=2*i;
                int c2=2*i+1;

                if(c1<idx-1 && c2<idx-1 && arr[c1]<arr[i] && arr[c2]<arr[i]){
                    if(arr[c1]<arr[c2]){
                        swap(arr[i],arr[c1]);
                        i=c1;
                    }
                    else{
                        swap(arr[i],arr[c2]);
                        i=c2;
                    }
                }
                else if(c1<idx && arr[c1]<arr[i]){
                    swap(arr[i],arr[c1]);
                    i=c1;
                }
                else if(c2<idx && arr[c2]<arr[i]){
                    swap(arr[i],arr[c2]);
                    i=c2;
                }
                else break;
            }
        }
    }
    
};
int main(){
    minheap hp;
    cout<<hp.size()<<endl;
    hp.push(10);
    cout<<hp.size()<<endl;
    cout<<hp.top()<<endl;
    hp.push(13);
    hp.push(12);
    hp.push(14);
    hp.push(19);
    hp.push(20);
    hp.pr();
    hp.push(9);
    hp.pr();
    hp.pop();
    hp.pr();

}