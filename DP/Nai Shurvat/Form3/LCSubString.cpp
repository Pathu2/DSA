#include<bits/stdc++.h>
using namespace std;
int n, m;
string s1, s2;
int rec(int i, int j, int Ntaken)
{
    //pruning
    
    //basecase
    if(i==n || j==m)
    {
        return 0;
    }
    //cache
    
    //compute/transition
    int ans = 0;
    if(Ntaken==0)
    {
        if(s1[i]==s2[j])
        {
            ans = rec(i+1, j+1, 1);
        }
        
    }
    //return
}


void solve(){
    cin>>s1>>s2;
    n = s1.length();

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1; while(t--){
        solve();
    }
    return 0;
}