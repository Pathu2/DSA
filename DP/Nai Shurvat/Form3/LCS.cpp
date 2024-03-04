#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<char> a, b;

int rec(int i, int j)
{
    //purning

    //basecase
    if(i==n || j==m)
    {
        return 0;
    }
    //cache

    //compute/transition
    int ans = 0;
    if(a[i]==b[j])
    {
        ans = max(ans, 1 +rec(i+1, j+1));
    }
    else
    {
        ans =  max(ans, rec(i+1, j));
        ans = max(ans, rec(i, j+1));
    }
    return ans;
    //return
}

void solve(){
    cin>>n>>m;
    a.resize(n);
    b.resize(m);
    for(int i = 0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i = 0;i<m;i++)
    {
        cin>>b[i];
    }
    cout<<rec(0, 0)<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1; while(t--){
        solve();
    }
    return 0;
}