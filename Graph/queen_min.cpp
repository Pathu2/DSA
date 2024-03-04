#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> dist;
vector<string> board;
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
bool check(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < n && board[x][y] != '#')
    {
        return true;
    }
    return false;
}
void bfs(pair<int, int> st)
{
    dist[st.first][st.second] = 0;
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({st, {0, 0}});
    int cur_node_x = q.front().first.first;
    int cur_node_y = q.front().first.second;
    q.pop();
    for (int i = 0; i < 8; i++)
    {
        if (check(cur_node_x + dx[i], cur_node_y + dy[i]) && (dist[cur_node_x + dx[i]][cur_node_y + dy[i]] > dist[cur_node_x][cur_node_y] + 1))
        {
            dist[cur_node_x + dx[i]][cur_node_y + dy[i]] = dist[cur_node_x][cur_node_y] + 1;
            q.push({{cur_node_x + dx[i], cur_node_y + dy[i]}, {dx[i], dy[i]}});
        }
    }
    while (!q.empty())
    {
        int cur_node_x = q.front().first.first;
        int cur_node_y = q.front().first.second;
        pair<int, int> cur_dir = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            if (check(cur_node_x + dx[i], cur_node_y + dy[i]))
            {
                if (cur_dir.first == dx[i] && cur_dir.second == dy[i])
                {
                    if (dist[cur_node_x + dx[i]][cur_node_y + dy[i]] > dist[cur_node_x][cur_node_y])
                    {
                        dist[cur_node_x + dx[i]][cur_node_y + dy[i]] = dist[cur_node_x][cur_node_y];
                        q.push({{cur_node_x + dx[i], cur_node_y + dy[i]}, {dx[i], dy[i]}});
                    }
                }
                else
                {
                    if (dist[cur_node_x + dx[i]][cur_node_y + dy[i]] > dist[cur_node_x][cur_node_y]+1)
                    {
                        dist[cur_node_x + dx[i]][cur_node_y + dy[i]] = dist[cur_node_x][cur_node_y]+1;
                        q.push({{cur_node_x + dx[i], cur_node_y + dy[i]}, {dx[i], dy[i]}});
                    }
                }
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    board.resize(n);
    dist.resize(n);
    for (int i = 0; i < n; i++)
    {
        dist[i].assign(m, 1e9);
    }
    pair<int, int> st, en;
    for (int i = 0; i < n; i++)
    {
        cin >> board[i];
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'Q')
            {
                st = {i, j};
            }
            else if (board[i][j] == 'E')
            {
                en = {i, j};
            }
        }
    }
    bfs(st);
    for(int i =0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            if (board[i][j]=='#')
            {
                cout<<"  ";
            }
            else
            {
                cout<<dist[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}