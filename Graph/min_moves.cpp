#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<string> board;
vector<vector<vector<int>>> dist;
void dfs(pair<int, int> st)
{
    
}

void solve(){
    cin>>n>>m;
    board.resize(n);
    int k = 4;
    // for (int i = 0; i < n; i++)
    // {
    //     cin>>board[i];
    // }
    dist.resize(n);
    for(int i =0;i<n;i++)
    {
        dist[i].resize(m);
    }
    for(int i  =0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            dist[i][j].assign(k, 0);
        }
    }
    for(int i =0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            for(int p =0;p<k;p++)
            {
                cout<<dist[i][j][p]<<" ";
            }
            cout<<"  ";
        }
        cout<<endl;
    }
    pair<int, int> st, en;
    
    
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1; while(t--){
        solve();
    }
    return 0;
}