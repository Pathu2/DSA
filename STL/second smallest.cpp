#include<bits/stdc++.h>
using namespace std;

void solve(){
    int N;
    cin>>N;
    int a[N];
    if (N==1)
    {
        cout<<"-1"<<endl;
        return;
    }
    for (int i = 0; i < N; i++)
    {
        cin>>a[i];
    }
    sort(a, a+N);
    int count = 0 ;
    for (int i = 1;i< N; i++)
    {
        if (a[0]<a[i])
        {
            cout<<a[i]<<endl;
            count++;
            break;
        }
    }
    if (count == 0)
    {
        cout<<"-1"<<endl;
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