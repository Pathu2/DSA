#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
vector<vector<pair<int, int>>> g_adj_list;
/*DFS karne ke lia*/
vector<pair<pair<int, int>, int>> g_edg_list;
/*Bellman-Ford ke lia*/

/*We will need a distance vector for it as we have to relax the edges*/
vector<int> dist;

void bellman(int node)
{
    int max_path = 0;
    dist[node] = 0;
    int times = n - 1;
    while (times--)
    {
        for (auto v : g_edg_list)
        {
            if (v.first.second == n)
            {
                if(max_path<dist[v.first.first] + v.second)
                {
                    max_path = dist[v.first.first] + v.second;
                }
            }
            if (dist[v.first.second] > dist[v.first.first] + v.second)
            {
                dist[v.first.second] = dist[v.first.first] + v.second;
            }
        }
    }
   
    for (auto v : g_edg_list)
    {
        if (dist[v.first.second] > dist[v.first.first] + v.second)
        {
            cout<<max_path<<endl;
            return;
        }
    }
    /*If yaha tak aa raha matlab ek toh cycle nhi hai aur aagar hai toh ek toh zero weight
    ya +ve weight wali hai....
    To find whether their exists a cycle or not and if yes then which one, we will use either
    dfs or dj.*/


}

void solve()
{
    cin >> n >> m;
    g_adj_list.resize(n + 1);
    dist.assign(n + 1, 1e18);
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g_adj_list[a].push_back({b, c});
        g_edg_list.push_back({{a, b}, c});
    }
    bellman(1);
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