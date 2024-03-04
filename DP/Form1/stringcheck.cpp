#include<bits/stdc++.h>
using namespace std;
int n, t;
int dp[1001][1001];
int rec(int level, int x)
/*Here x is the subsequence got in the original string*/
{
    
    if (level==n)
    {
        if (x==t)
        {
            return 1;
            /*This is because suppose we are at level n-1 at x=t-1 and for the transition happening at the last lvl we want to find whether
            have the sub sequene completed or not if its completed then we will return 1 but if its not then 0
            now why zero? Just remember our problem statement, we have been asked about the no. of string which have this string t in it, aagar string
            hai hi nhi toh add nhi kar sakte na*/
        }
        else
        {
            return 0;
        }
        
    }
    if (dp[level][x]!=-1)
    {
        return dp[level][x];
    }
    
    int ans = 0;
    if(x==t)
    {
        ans = 1+26*rec(level+1, x);
    }
    else
    {
        ans = rec(level+1, x+1) + 25*rec(level+1, x);
    }
    return dp[level][x] = ans;
}

void solve(){
    cin>>n>>t;
    memset(dp, -1, sizeof(dp));
    cout<<rec(0,0)<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1; while(t--){
        solve();
    }
    return 0;
}