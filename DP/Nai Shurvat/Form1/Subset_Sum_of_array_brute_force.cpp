#include<bits/stdc++.h>
using namespace std;
vector<int> ck;
vector<int> state;
int n;
void solve(int level)
{
    //basecase
    if(level==n)
    {
        for(auto v: state)
        {
            cout<<v<<" ";
        }
        cout<<endl;
        return;
    }
    //compute
    state.push_back(ck[level]);
    solve(level+1);
    state.pop_back();
    solve(level+1);
}

void solve(){
    
    cin>>n;
    ck.resize(n);
    for(int i = 0;i<n;i++)
    {
        cin>>ck[i];
    }
    solve(0);
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1; while(t--){
        solve();
    }
    return 0;
}