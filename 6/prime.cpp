#include <iostream>
using namespace std;
int main()
{
    int x;
    cout << "enter number;";
    cin >> x;
    int count = 0;
    for (int i = 2; i < x / 2 + 1; i++)
    {
        if (x % i == 0)
        {
            count += 1;
            break;
        }
    }
    if(count==0) cout<<"prime";
    else cout<<"composite";
}