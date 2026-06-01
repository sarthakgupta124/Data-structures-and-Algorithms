#include <iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)cin>>arr[i][j];
    }
    int minr=0,maxr=n-1,maxc=m-1,minc=0;
    while(minr<=maxr || minc<=maxc){
        for(int i=minc;i<=maxc;i++) cout<<arr[minr][i];
        minr++;
        for(int i=minr;i<=maxr;i++) cout<<arr[i][maxc];
        maxc--;
        for(int i=maxc;i>=minc;i--) cout<<arr[maxr][i];
        maxr--;
        for(int i=maxr;i>=minr;i--) cout<<arr[i][minc];
        minc++;
    }

}