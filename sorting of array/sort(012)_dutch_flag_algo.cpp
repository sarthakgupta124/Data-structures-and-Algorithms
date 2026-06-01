#include <iostream>
// sort(012)_dutch_flag_algo
using namespace std;
void swap(int a, int b,int arr[])
{
    int c = arr[a];
    arr[a] = arr[b];
    arr[b] = c;
}

int main()

{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int i = 0, j = n - 1, k = 1;
    while (i <= k && i < j && k <= j)
    {
        if (arr[k] == 1)
            k++;

        if (i <= k && i < j && k <= j)
            ;
        else
            break;
        if (arr[k] == 0)
        {
            swap(k,i,arr);

            i++;
        }
        else if (arr[k] == 2)
        {
            swap(k,j,arr);
            j--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
}