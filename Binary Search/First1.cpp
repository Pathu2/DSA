#include<bits/stdc++.h>
using namespace std;

void solve(){
    int arr[]={0, 0, 0, 0, 1, 1, 1, 1, 1};
    int lo = 0;
    int hi = 8;
    int ans = -1;
    while (lo<=hi)
    {
        int mid = lo + (hi-lo)/2;
        if(arr[mid]==0)
        {
            lo = mid +1 ;
        }
        else
        {
            ans = mid;
            hi = mid-1;
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