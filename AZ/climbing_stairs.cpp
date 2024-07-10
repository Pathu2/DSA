#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
void solve(){
    int m;
    int n;
    cin>>n>>m;
    int climbs = n/m;
    cout<<(climbs + (n-(climbs*m)))<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
//ADD THE IOS CODE AND ENDL CODE ALWAYS IN THE SOLUTION
