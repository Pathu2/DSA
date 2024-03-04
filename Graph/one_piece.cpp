#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
vector<vector<int>> g;
vector<vector<int>> dist;
int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};
/*Right, left, down , up*/
/*0 1 2 3*/
bool check(int x, int y)
{
    if(x>=1&& x<=n && y>=1 && y<=m)
    {
        return true;
    }
    return false;
}

// pair<int, int> direction(int wind_dir)
// {
//     if(wind_dir==1)
//     {
//         return {0, 1};
//     }
//     else if(wind_dir==2)
//     {
//         return {0, -1};
//     }
//     else if(wind_dir==3)
//     {
//         return {1, 0};
//     }
//     else
//     {
//         return {-1, 0};
//     }
// }

void bfs(int x, int y)
{
    dist[x][y]=0;
    deque<pair<pair<int, int>,int>> q;
    q.push_back({{x, y}, g[x][y]});
    while (!q.empty())
    {
        int cur_x = q.front().first.first;
        int cur_y = q.front().first.second;
        // pair<int, int> wind_dir = direction(q.front().second);
        int wind_dir= q.front().second;
        q.pop_front();
        for(int i =0;i<4;i++)
        {
            if(check(cur_x+dx[i], cur_y+dy[i]))
            {
                if(wind_dir==i+1)
                {
                    if(dist[cur_x+dx[i]][cur_y+dy[i]]>dist[cur_x][cur_y])
                    {
                        dist[cur_x+dx[i]][cur_y+dy[i]] = dist[cur_x][cur_y];
                        q.push_front({{cur_x+dx[i], cur_y+dy[i]}, g[cur_x+dx[i]][cur_y+dy[i]]});
                    }
                }
                else
                {
                    if(dist[cur_x+dx[i]][cur_y+dy[i]]>dist[cur_x][cur_y]+1)
                    {
                        dist[cur_x+dx[i]][cur_y+dy[i]] = dist[cur_x][cur_y]+1;
                        q.push_back({{cur_x+dx[i], cur_y+dy[i]}, g[cur_x+dx[i]][cur_y+dy[i]]});
                    }
                }
            }
        }
    }
    

}
void solve(){
    cin>>n>>m;
    g.resize(n+1);
    dist.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        g[i].resize(m+1);
        dist[i].assign(m+1, 1e9);
    }
    for(int i =1;i<=n;i++)
    {
        for(int j =1;j<=m;j++)
        {
            cin>>g[i][j];
        }
    }
    bfs(1, 1);
    cout<<dist[n][m]<<endl;

    
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1; while(t--){
        solve();
    }
    return 0;
}