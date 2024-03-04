#include<bits/stdc++.h>
using namespace std;
int n, m;
string s1, s2;
int dp[2001][2001];
int rec(int lvl1, int lvl2)
{
    //purnate

    //basecase
    if (lvl1==n||lvl2==m)
    {
        return 0;
    }
    //cache and return
    if (dp[lvl1][lvl2]!=-1)
    {
        return dp[lvl1][lvl2];
    }
    
    //save and return
    int ans = 0;
    if (s1[lvl1]==s2[lvl2])
    {
        ans = max(ans, rec(lvl1+1, lvl2+1)+1);
    }
    else
    {
        ans = max(rec(lvl1+1, lvl2), rec(lvl1, lvl2+1));
    }
    return dp[lvl1][lvl2] = ans;
    
}

void solve(){
    cin>>s1>>s2;
    n=s1.length();
    m=s2.length();
    memset(dp, -1, sizeof(dp));
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