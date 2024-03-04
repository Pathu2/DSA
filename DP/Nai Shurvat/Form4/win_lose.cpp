#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> a;

int rec(int L, int R)
{
    //purning

    //basecase
    if(L==R)
    {
        return a[L];
    }
    //cache

    //compute/transition
    int ans  = max(a[L]-rec(L+1, R), a[R]-rec(L, R-1));
    return ans;

    //return 
}

void solve(){
    cin>>n;
    a.resize(n);
    for(int i = 0;i<n;i++)
    {
        cin>>a[i];
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
