#include <iostream>
using namespace std;
class vehicle{ //parent,base class
public:
    int tyresize;
    int enginesize;
    int light;
    string company;
    vehicle (){
        cout<<"vehicle ka constructor call hua"<<endl;
    }
    //agar child ka object create hua hai toh uske cossesponding uske parent ka bhi banega
};
class car:public vehicle{ //made car as child,derived class of vehicle
public:
    int steeringSize;
    
};
//constructor
class Bike:public vehicle{
public:
    int handlesize;

    // static int nobike; //sare object ke liye same hoga function can also static

    // int tyresize;
    // int enginesize;
    // constructor overloading
    // Bike (int ts,int es):tyresize(ts),enginesize(es){}//all three are constructor
    // Bike (int ts):tyresize(ts),enginesize(120){}
    // Bike ():tyresize(20),enginesize(100){}
};
//overloading two function with same name diffrent parameter
void add(int a,int b){
    cout<<a+b<<endl;
    return;
}
void add(int a){
    cout<<a+10<<endl;
    return;
}
int main(){
    add(1,2);
    add(1);

    Bike honda;
    honda.handlesize=5;
    honda.tyresize=10;
    cout<<honda.tyresize<<endl;
}