#include<bits/stdc++.h>
using namespace std;

int check(int a[], int x, int K, int N)
{
    int students = 1;
    int j=0;
    for (int i = 0; i < N;i++)
    {
       if (a[i]-a[j]>=x)
       {
            students++;
            j=i;
       }
    }
    if (students>=K)
    {
        /*Returning 1...If students are less than or equal to required number
        Because, i can further minimize the distnace */
        return 1;
    }
    else
    {
        return 0;
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
    sort(a, a+N);
    int min, max;
    max = a[N-1]-a[0];
    min = a[1]-a[0];
    int ans = min;
    while (min<=max)
    {
        int mid = (min + max)/2;
        if (check(a, mid, K, N)==0)
        {
            ans = mid;
            min = mid + 1;
        }
        else
        {
            
            max = mid -1;
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