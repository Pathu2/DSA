#include<bits/stdc++.h>
#define int long long
using namespace std;

int search(int B, int b[], int M)
{
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
    return ans;
    
}


int check(int  x, int a[], int b[], int N, int M, int  K)
{
    int no_of_elements_less_than_x  = 0;
    if (N<=M)
    {
        
        for (int i = 0; i < N; i++)
        {
            no_of_elements_less_than_x = no_of_elements_less_than_x + search(x-a[i], b, M);
        }
        
    }
    else
    {
        for (int i = 0; i < M; i++)
        {
            no_of_elements_less_than_x = no_of_elements_less_than_x + search(x-b[i], a, N);
        }
    }


    if (no_of_elements_less_than_x>=K)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}


void solve(){
    int N, M; 
    int  K;
    cin>>N>>M>>K;
    int a[N], b[M];
    for (int i = 0; i < N; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < M; i++)
    {
        cin>>b[i];
    }
    sort(a, a+N);
    sort(b, b+M);
    int  lo = a[0]+b[0];
    int  hi = a[N-1]+b[M-1];
    int  ans = lo;
    while (lo<=hi)
    {
        int  mid = lo + (hi-lo)/2;
        if (check(mid, a, b, N, M , K)==0)
        {
            lo = mid+1;
        }
        else
        {
            ans = mid;
            hi = mid -1 ;
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