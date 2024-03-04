#include<bits/stdc++.h>
using namespace std;

vector<string> board;
vector<vector<int>> dp;
int n, m;
int min_cells(int x, int y)
{
    //purnate
    if(x>=n || y>=m || board[x][y]=='#')
    {
        return 1e9;
    }
    //base
    if(x==n-1 && y==m-1)
    {
        return 0;
    }
    //cache
    if(dp[x][y]!=(-1))
    {
        return dp[x][y];
    }
    //save
    dp[x][y] = 1 + min(min_cells(x+1, y), min_cells(x, y+1));
    //return
    return dp[x][y];
}

void solve(){
    cin>>n>>m;
    board.resize(n);
    dp.resize(n);
    for(int i = 0; i<n;i++)
    {
        cin>>board[i];
        dp[i].assign(m, -1);
    }
    cout<<min_cells(0, 0)<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1; while(t--){
        solve();
    }
    return 0;
}