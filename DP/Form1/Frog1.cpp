#include<bits/stdc++.h>
using namespace std;
int n, k;
vector<int> stones;
vector<int> dp;
int rec(int level)
{
    //pruning
    // if (level==n-1)
    // {
    //     return abs(stones[level]-stones[level+1]);
    // }
    /*We will not need this now as i am using the for and will do purning their only */
    //basecase
    if (level==n)
    {
        return 0;
    }
    
    //cache and return
    if(dp[level]!=-1)
    {
        return dp[level];
    }
    //compute
    int ans = 10000;
    for (int i = 1; i <=k; i++)
    {
        if (level+i>=n+1)
        {
            break;
        }
        ans = min(ans, abs(stones[level]-stones[level+i])+rec(level+i));
    }
    return dp[level]= ans;

}

void solve(){
    cin>>n>>k;
    stones.resize(n+1);
    dp.assign(n+1, -1);
    for (int i = 1; i < n+1; i++)
    {
        cin>>stones[i];
    }
    cout<<rec(1)<<endl;
    
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t; cin>>t; while(t--){
        solve();
    }
    return 0;
}