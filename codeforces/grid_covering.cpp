// #include <bits/stdc++.h>
// using namespace std;
// bool f(vector<vector<int>>&grid,int i,int j,int n,int m,int count,int a,int b,char last){
//     if(count==n*m-1){
//         //last position
//         if(grid[i][j]!=-1) return false;
//         grid[i][j]=1;
//         return true;
//         grid[i][j]=-1;
//     }
//     if(last=='a'){
//         int nc;
//         nc=(j+b)%(m);
//         if(grid[i][nc]==-1){
//             grid[i][j]=1;
//             bool ans=f(grid,i,nc,n,m,count+1,a,b,'b');
//             grid[i][j]=-1;
//             return ans;
//         }
//         else return false;
//     }
//     else{
//         int nr;
//         nr=(i+a)%(n);
//         if(grid[nr][j]==-1){
//             grid[i][j]=1;
//             bool ans=f(grid,nr,j,n,m,count+1,a,b,'a');
//             grid[i][j]=-1;
//             return ans;
//         }
//         else return false;
//     }
    
// }
// int main(){
//     int s;
//     cin>>s;
//     int n,m,a,b;
//     while(s--){
//         cin>>n>>m>>a>>b;
//         vector<vector<int>>grid(n,vector<int>(m,-1)); //-1 denotes the vacant place
//         bool ans=f(grid,0,0,n,m,0,a,b,'a');
//         if(ans) cout<<"yes"<<endl;
//         else{
//             grid.assign(n,vector<int>(m,-1));
//             ans=f(grid,0,0,n,m,0,a,b,'b');
//             if(ans) cout<<"yes"<<endl;
//             else cout<<"no"<<endl;
//         }
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

// Iterative function to avoid Stack Overflow
bool check_path(int n, int m, int a, int b, char current_move) {
    // 0 denotes vacant, 1 denotes visited
    vector<vector<int>> visited(n, vector<int>(m, 0));
    
    int r = 0, c = 0;
    int count = 0;
    
    while (count < n * m) {
        if (visited[r][c] == 1) {
            return false;
        }
        
        visited[r][c] = 1;
        count++;
        
        if (count == n * m) {
            return true;
        }
        if (current_move == 'a') {
            c = (c + b) % m;
            current_move = 'b';
        } else {
            r = (r + a) % n;
            current_move = 'a';
        }
    }
    
    return false;
}
int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int s;
    if (!(cin >> s)) return 0;
    
    while (s--) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        
        // Try starting with a horizontal move ('a') OR a vertical move ('b')
        if (check_path(n, m, a, b, 'a') || check_path(n, m, a, b, 'b')) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
    return 0;
}