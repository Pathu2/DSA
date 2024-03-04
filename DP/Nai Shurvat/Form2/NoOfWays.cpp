#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> arr, dp;
bool check(int x, int y)
{
    if(x<0 || x>=n || y<0 || y>=m)
    {
        return 0;
    }
    return 1;
}

int rec(int x, int y)
{
    //pruning
    if(x<0 || x>=n || y<0 || y>=m)
    {
        return 0;
    }
    //basecase
    if(x==0 && y==0)
    {
        return 1;
    }
    //cache
    if(dp[x][y]!=-1)
    {
        return dp[x][y];
    }

    //compute/transition
    int ans  = 0;
    ans =rec(x-1, y) + rec(x, y-1);

    //return
    return dp[x][y] = ans;
}

void solve(){
    cin>>n>>m;
    arr.resize(n);
    dp.resize(n);
    for (int i = 0; i < n; i++)
    {
        arr[i].resize(m);
        dp[i].assign(m, -1);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<rec(n-1, m-1);

    
    
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1; while(t--){
        solve();
    }
    return 0;
}