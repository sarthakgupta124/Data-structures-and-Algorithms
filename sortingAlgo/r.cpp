#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int> &k, int a, int b)
{
    int pivot = (a + b) / 2, co = 0; // we take random pivot point to improve time complexity

    for (int i = a; i < b; i++)
    {
        if (i == pivot)
            continue;
        if (k[i] > k[pivot])
            co++;
    }
    swap(k[pivot], k[a + co]);
    int i = a, j = b;
    while (i < (a + co) && (j > a + co))
    {
        if (k[i] > k[a + co])
        {
            i++;
        }
        else if (k[j] <= k[a + co])
        {
            j--;
        }
        else
        {
            swap(k[i], k[j]);
            i++;
            j--;
        }
    }
    return (a + co);
}
int ouicksort(vector<int> &v, int k, int i, int j)
{
    if (i >= j)
        return v[i];
    int c = partition(v, i, j);
    if (k < c)
        return ouicksort(v, k, i, c);
    else if (k > c)
        return ouicksort(v, k, c+1, j);
    else
        return v[c];
}
int main()
{
    int n = 9;
    vector<int> v(n);
    v = {3,2,3,1,2,4,5,5,6};
    int y;
    cin>>y;

    cout<<ouicksort(v, y-1,0, n);
    // for (int i = 0; i < n; i++)
    //     cout << v[i] << " ";
}