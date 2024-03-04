#include<bits/stdc++.h>
using namespace std;

#define int long long
int check(int a[], int x, int l)
{
    if (x==(l-1))
    {
        return 1;
    }
    if (a[x]>a[x+1])
    {
        return 1;
    }
    /*We will compare each mid with the last element*/
    else
    {
        return 0;
    }
    /*We had used a check function here to return 0 or 1 based on the condition
    and we will use same logic as finding the first 1 in a sorted array of 0s and 1s
    */
}

void print1(int a[], int K, int lo, int hi)
{
    int ans = lo;
    while (lo<=hi)
    {
        int mid  = (lo + hi)/2;
        if (a[mid]<K)
        {
            lo = mid +1; 
        }
        else
        {
            ans = mid;
            hi = mid -1;
        }  
    }
    if (a[ans]==K)
    {
        cout<<ans+1<<" ";
        return;
    }
    else
    {
        return;
    } 
}

void print2(int a[], int K, int lo, int hi)
{
    int ans = lo;
    while (lo<=hi)
    {
        int mid  = (lo +hi)/2;
        if (a[mid]>K)
        {
            lo = mid +1; 
        }
        else
        {
            ans = mid;
            hi = mid -1;
        }  
    }
    if (a[ans]==K)
    {
        cout<<ans+1;
        return;
    }
    else
    {
        return;
    } 
}

void solve(){
    int N, Q, K;
    cin>>N>>Q;
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
    while (Q--)
    {
        cin>>K;
        print1(a, K, 0, ans);
        print2(a, K, ans+1, N-1);
        cout<<endl;
    }
    
    
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t; cin>>t; while(t--){
        solve();
    }
    return 0;
}