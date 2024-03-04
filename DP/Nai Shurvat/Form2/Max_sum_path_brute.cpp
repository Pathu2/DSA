#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> arr, dp;
vector<vector<bool>> hai;

int dx[]={0, 1};
int dy[]={1, 0};
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
    //purnate
    if(x<0 || x>=n || y<0 || y>=m)
    {
        return 0;
    }
    //basecase
    if(x==n-1 && y==m-1)
    {
        return arr[x][y];
    }
    //cache
    if(hai[x][y])
    {
        return dp[x][y];
    }
    //compute/transition
    int ans  = arr[x][y];
    for(int i = 0;i<2;i++)
    {
        if(check(x+dx[i], y+dy[i]))
        {
            ans =  max(ans, arr[x][y] + rec(x+ dx[i], y+dy[i]));
        }
    }
    //return
    hai[x][y]=true;
    return dp[x][y] = ans;
}

void solve(){
    cin>>n>>m;
    arr.resize(n);
    dp.resize(n);
    hai.resize(n);
    for (int i = 0; i < n; i++)
    {
        arr[i].resize(m);
        dp[i].resize(m);
        hai[i].assign(m, false);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<rec(0, 0)<<endl;

    
    
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1; while(t--){
        solve();
    }
    return 0;
}