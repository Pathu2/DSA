#include<bits/stdc++.h>
using namespace std;
/*Time Complexity....................*/
struct unionFind{
    // int par[100100];
    // int rank[100100];
    vector<int> par;
    vector<int> rank;
    void init(int n)
    {
        par.resize(n+1);
        rank.assign(n+1, 1);
        for(int i =0;i<n;i++)
        {
            par[i]=i;
            /*Here rank is the like the size of the component
            Initially all the nodes are like the seperate component and har koi
            khud hi parent hai and the size of all the components is equal to one obv*/
        }
    }
    void print_machine(int x)
    {
        int root = find(x);
        cout<<"Rank of x is "<< rank[x]<< "Rank of root is "<<rank[root]<<" while the root is "<<root<<endl;
    }

    int find(int x)
    {
        if(par[x]==x)
        {
            return x;
        }
        else return par[x]=find(par[x]);
        
    }
    /*The find function here is implemented using the path compression....lets see aapne
    question mein kaam aata bhi hai ya nhi*/

    void merge(int x, int y)
    {
        int par_x= find(x);
        int par_y = find(y);
        if(rank[par_x]>rank[par_y])
        {
            par[par_y]=par_x;
            rank[par_x] = rank[par_x] + rank[par_y];
        }
        else
        {
            par[par_x]=par_y;
            rank[par_y]=rank[par_y]+rank[par_x];
        }
    } 
};

void solve(){
    int n, m;
    cin>>n>>m;
    unionFind check;
    // check.print_machine();
    check.init(n);
    while (m--)
    {
        int a, b;
        cin>>a>>b;
        check.merge(a, b);
    }
    for(int i =1;i<=n;i++)
    {
        check.print_machine(i);
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