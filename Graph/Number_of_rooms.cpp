#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<string> mp;
/*I will make a visited array as well*/
vector<vector<int>> dis;

int dx[] = {-1,0,1,0};
int dy[] = {0, 1, 0, -1};

bool check(int x, int y)
{
    if (x>=0 && x<n && y>=0 && y<m && mp[x][y]=='.')
    {
        return 1;
    }
    return 0;
    
}

void dfs(int row, int col, int num_of_comps)
{
    dis[row][col] = num_of_comps;
    for (int k = 0; k < 4; k++)
    {
        if (check(row+dx[k], col+dy[k]) && dis[row+dx[k]][col+dy[k]]==0)
        {
            dfs(row+dx[k], col+dy[k], num_of_comps);
        }
        
    }
    return;
    
}

void solve(){
    cin>>n>>m;
    mp.resize(n);
    dis.resize(n, vector<int>(m));
    for (auto v:dis)
    {
        v.assign(m, 0);
    }
    
    for (int i = 0; i < n; i++)
    {
        cin>>mp[i];
    }
    int num_of_comp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mp[i][j]=='.' && dis[i][j]==0)
            {
                num_of_comp++;
                dfs(i, j, num_of_comp);
            }
            else
            {
                continue;
            }   
        }  
    }
    cout<<num_of_comp<<endl;
    

    
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1; while(t--){
        solve();
    }
    return 0;
}