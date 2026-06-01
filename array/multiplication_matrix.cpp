#include <iostream>
using namespace std;
int main()
{
    int n , m , k;
    cin>>n>>m>>k;
    int arr[n][m];
    int brr[m][k];
    int crr[n][k];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)cin>>arr[i][j];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < k; j++) cin>>brr[i][j];
    }
    int i = 0;
    while (i < n)
    {
        int j = 0;
        while (j < k)
        {

            int k = 0, sum = 0;
            while (k < m)
            {
                sum += (arr[i][k] * brr[k][j]);
                k++;
            }
            crr[i][j] = sum;
            j++;
        }
        i++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
            cout << crr[i][j] << " ";
        cout << endl;
    }
}