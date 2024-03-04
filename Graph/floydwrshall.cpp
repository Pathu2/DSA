#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, q;
vector<vector<int>> dist;
vector<vector<bool>> haikya;
/*How we have taken input for the  graph*/
/*For solving the problem with floyd warshall we have to use adjaceny matrix, instead of list
while taking the input we will first of all make a dist matrix and set all the values
except diagonal ones, equal to 1e9 or infinte and cell i, j says that it is the edge between
ith and jth  node and its value is equal to value of the cell.*/
/*Rememeber that you have to take both the for loops till n; as both represents the nodes*/
void solve()
{
    cin >> n >> m >> q;
    dist.resize(n + 1);
    haikya.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        dist[i].resize(n + 1);
        haikya[i].resize(n + 1);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
            {
                dist[i][j] = 1e18;
                haikya[i][j] = false;
            }
            else
            {
                dist[i][j] = 0;
                haikya[i][j] = true;
            }
        }
    }
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
        haikya[a][b] = true;
        haikya[b][a] = true;
    }
    /*Appling the algorithm itself*/
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    haikya[i][j] = true;
                }
            }
        }
    }
    while (q--)
    {
        int p, q;
        cin >> p >> q;
        if (!haikya[p][q])
        {
            cout << -1 << endl;
        }
        else
        {
            cout << dist[p][q] << endl;
            
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    t=1;
    while (t--)
    {
        solve();
    }
    return 0;
}