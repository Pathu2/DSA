#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> g;
vector<pair<int, int>> edgelist;
vector<int> visited;
/*Now in this question we have to find the number of pairs of the edges
which are not reachable..
For edges to be not reachable we can say that are not in same connected component...
They must be in the different componenets...so we first need to find the nodes in different
components and then can find the edges in different components....for this we will use
the dfs traversal*/

/*We will mark all the nodes of same component with same number*/


void dfs(int node, int num_of_comp)
{
    
    visited[node]=num_of_comp;
    for (auto i = g[node].begin(); i != g[node].end(); i++)
    {
        if (visited[*i]!=0)
        {
            dfs(*i, num_of_comp);
        }
    }
    return;
    /*This completes our dfs*/
}

void solve(){
    cin>>n>>m;
    g.resize(n+1);
    visited.assign(n+1, 0);
     
    while (m--)
    {
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
        /*To store the neighbour of that node.....that is pushing it back
        in the vector at that index*/
        edgelist.push_back({a, b});
        /*We are making a edge list*/
    }
    int num_of_comp = 0;
    for (int i = 1; i <=n ; i++)
    {
        if (visited[i]==0)
        {
            num_of_comp++;
            dfs(i, num_of_comp);
        }
    }

    vector<int> num_of_edge(num_of_comp+1, 0);
    for (auto it=edgelist.begin(); it!=edgelist.end();it++)
    {
        num_of_edge[visited[it->first]]++;
    }
    


    
    
    
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1; while(t--){
        solve();
    }
    return 0;
}