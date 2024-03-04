#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
vector<vector<int>> dp;
int solve(int level, int S)
{
    /*First of all lets understand how it is a form 1 dp.
    If you remember the form is of type, whether to include the level at which we are
    or not include it......
    So, in this as you can see we have set the state as the level as the sum S, which as that
    till the "level"th level the sum is equal to S or not, so there are two possibilities that...
    if the level is included then solve(level-1, S-a[i]) should be true or if the level is 
    excluded then solve(level-1, S) should be true, if either of anyone is true then we can say
    the subarray exits*/


    //basecase
    if(level==-1)
    {
        return 0;
    }
    if(level==0)
    {
        if(S==a[level])
        {
            return 1;
        }
    }
    //return dp
    if(dp[level][S]!=-1)
    {
        return dp[level][S];
    }
    //compute
    return dp[level][S] = solve(level-1, S-a[level]) || solve(level-1, S);

}

void solve(){
    cin>>n;
    int T;
    cin>>T;
    a.resize(n);
    dp.resize(n);
    for(int i =0;i<n;i++)
    {
        dp[i].assign(T, -1);
    }
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<solve(n-1, T)<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1; while(t--){
        solve();
    }
    return 0;
}