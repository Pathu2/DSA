#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> g;

vector<int> visited;

void dfs(int node)
{
    /*How to apply dfs?
    If the node is visited...return
    If it is not visited...make it visited and loop through its neighbours and
    see if they are visited or not..if not visited then turant dfs lagado...
    else if visited then continue.*/

    /*How to know that the node is visited or not
    we will maintain an array..if the vlaue at that index is equal to zero then not visited
    else visited*/

    /*Who are the neighbousrs
    Neighbours are the elements in the vector at that index in the adjacency list*/

    if (visited[node]!=0)
    {
        return;
    }
    visited[node]=1;
    for (auto i = g[node].begin(); i != g[node].end(); i++)
    {

        if (visited[*i]!=0)
        {
            dfs(*i);
        }
    }
    return;
    /*This completes our dfs*/
    

}

void solve(){
    cin>>n>>m;
    /*Here n is number of nodes and m is no of edges*/
    /*I am considering that the graph is 1 indexed graph and i will represent my graph
    by adjaceny list*/
    /*Now i will input the edges*/
    /*For edges i will be given the nodes between which i have a edge*/
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
    }
    dfs(0);
    
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1; while(t--){
        solve();
    }
    return 0;
}