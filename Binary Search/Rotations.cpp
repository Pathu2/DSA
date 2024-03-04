#include<bits/stdc++.h>
using namespace std;
#define int long long
int check(int a[], int x, int l)
{
    if (a[x]>a[l-1])
    {
        return 0;
    }
    /*We will compare each mid with the last element*/
    else
    {
        return 1;
    }
    /*We had used a check function here to return 0 or 1 based on the condition
    and we will use same logic as finding the first 1 in a sorted array of 0s and 1s
    */
}

void solve(){
    int N;
    cin>>N;
    int a[N];
    for (int i = 0; i < N; i++)
    {
        cin>>a[i];
    }
    
    int lo = 0;
    int hi = N-1;
    int ans = N-1;
    while (lo<=hi)
    {
        int mid = (hi+lo)/2;
        if(check(a, mid, N)==0)
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