#include <bits/stdc++.h>
using namespace std;
void letterCombinations()
{
    vector<string> com(10);
    int count = 0;
    for (int i = 2; i <= 9; i++)
    {
        int x = 3;
        while (x--)
        {
            char s = count + 'a';
            string n = com[i] + s;
            com[i] = n;
            count++;
        }
        if (i == 6 || i == 8)
            x = 4;
        else
            x = 3;
    }


    for (int i = 2; i <= 9; i++)
    {
        cout<<com[i]<<endl;
    }
    // string an;
    // f(com, digits, 0, an);
    // return ans;
}
int main()
{
    letterCombinations();
}