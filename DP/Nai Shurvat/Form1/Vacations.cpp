#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> a, b, c;
vector<vector<int>> dp;
#define int long long
int rec(int level, int prev)
{
    //pruning

    //basecase
    if(level==n)
    {
        return 0;
    }
    //cache

    //compute/transition
    int ans  = 0;
    if(prev==1)
    {
        ans =  max(ans, b[level] + rec(level + 1, 2));
        ans = max(ans, c[level] + rec(level+1, 3));
    }
    else if(prev==2)
    {
        ans =  max(ans, a[level] + rec(level + 1, 1));
        ans = max(ans, c[level] + rec(level+1, 3));
    }
    else
    {
        ans =  max(ans, a[level] + rec(level + 1, 1));
        ans = max(ans, b[level] + rec(level+1, 2));
    }

    //return
    return ans;
}

void solve(){
    cin>>n;
    a.resize(n);
    b.resize(n);
    c.resize(n);
    dp.resize(n);
    for(int i = 0;i<n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    for (int i = 0; i < n; i++)
    {
        dp[i].resize(3, -1);
    }
    
    int ans = 0;
    ans = max(ans, a[0] + rec(1, 1));
    ans = max(ans, b[0] + rec(1, 2));
    ans = max(ans, c[0] + rec(1, 3));
    cout<<ans<<endl;
    

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1; while(t--){
        solve();
    }
    return 0;
}