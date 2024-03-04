#include<bits/stdc++.h>
using namespace std;

void solve(){
    int M;
    cin>>M;
    int b[M];
    for (int i = 0; i < M; i++)
    {
        cin>>b[i];
    }
    int B;
    cin>>B;
    int lo = 0;
    int hi = M-1;
    int ans  = M;
    while (lo<=hi)
    {
        int mid  = (lo+hi)/2;
        if (b[mid]<=B)
        {
            lo = mid +1;
        }
        else
        {
            ans = mid;
            hi = mid -1;
        }   
    }
    cout<<ans<<endl;
    
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t; cin>>t; while(t--){
        solve();
    }
    return 0;
}