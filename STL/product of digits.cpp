#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
void solve(){
    int N;
    cin>>N;
    int t;
    long long product = 1;
    while(N--)
    {
        cin>>t;
        product = (product*t)%mod;
    }
    cout<<product<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t; cin>>t; while(t--){
        solve();
    }
    return 0;
}