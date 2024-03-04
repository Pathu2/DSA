#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    int x, y;
    cin>>x>>y;
    int run =0;
    while (k--)
    {
        int xi, yi;
        cin>>xi>>yi;
        if ((abs(xi-x)+abs(yi-y))%2==0)
        {
            run++;
        }
    }
    if(run)
    {
        cout<<"No"<<endl;
    }
    else
    {
        cout<<"Yes"<<endl;
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