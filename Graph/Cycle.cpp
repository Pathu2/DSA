#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> g;
vector<int> col;
vector<int> parent;
int no_of_cycles = 0;
int no_of_cross_edge= 0;
void dfs(int node)
{
    col[node]=2;
    for (auto i = g[node].begin(); i != g[node].end(); i++)
    {
        parent[*i]=node;
        if (col[*i]==1)
        {
            dfs(*i);
        }
        else if(col[*i]==2)
        {
            no_of_cycles++;
            int temp = node;
            while (temp!=(*i))
            {
                cout<<temp<<" ";
                temp = parent[temp];
            }
            cout<<temp<<endl;
            /*Reverse karna padega isko....pehele saare node ko ek vector me lo aur
            phir reverse karke print karo....aur saari cycles print karane ke lia
            vector of vector bana loo*/
        }
        else if (col[*i]==3)
        {
            no_of_cross_edge++;
        } 
    }
    col[node]=3; 
}

void solve(){
    cin>>n>>m;
    g.resize(n+1);
    col.assign(n+1, 1);
    parent.resize(n+1);
    while (m--)
    {
        int a, b;
        cin>>a>>b;
        if (a==b)
        {
            continue;
            /*Handling self loops*/
        }
        
        g[a].push_back(b);
    }
    dfs(1);
    cout<<no_of_cycles<<" "<<no_of_cross_edge<<endl;
    
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1; while(t--){
        solve();
    }
    return 0;
}