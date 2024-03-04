#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> arr;
vector<int> dp;
vector<bool> check;
/*Reason for taking the bool arr is that their might be possibilty that value of element
in dp array is negative*/
int rec(int level)
{
    //purning && basecase 
    if (level<0)
    {
        return 0;
    }
    //cache and check
    if (check[level])
    {
        return dp[level];
    }
    
    //save and return
    int ans = max(rec(level-1)+arr[level], arr[level]);
    check[level]=1;
    return dp[level] = ans;
}

void solve(){
    cin>>n;
    arr.resize(n);
    dp.resize(n);
    check.assign(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int ans = rec(0);
    for (int i = 1; i < n; i++)
    {
        ans = max(ans, rec(i));
    }
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