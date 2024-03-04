#include<bits/stdc++.h>
using namespace std;
#define int long long

int sum(int a[], int N)
{
    int sumation = 0;
    for (int i = 0; i < N; i++)
    {
        sumation = sumation + a[i];
    }
    return sumation;
}

int check(int a[], int x, int N, int K)
{
    int painters = 1;
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        if (sum+a[i]<=x)
        {
           sum = sum + a[i];
        }
        else
        {
            sum = 0;
            painters++;
            i--;
        }
    }
    // cout<<painters<<endl;
    if (painters>K)
    {
        return 0;
    }
    else
    {
        return 1;
    }
    
    
}

void solve(){
    int N, K;
    cin>>N>>K;
    int a[N];
    for (int i = 0; i < N; i++)
    {
        cin>>a[i];
    }
    int lo = *max_element(a, a+N);
    int hi = sum(a, N);
    int ans = hi;
    while (lo<=hi)
    {
        int mid = lo + (hi- lo)/2;
        if (check(a, mid, N, K)==0)
        {
            lo = mid+1;
        }
        else
        {
            ans = mid;
            hi= mid-1;
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