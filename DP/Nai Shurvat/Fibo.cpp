#include<bits/stdc++.h>
using namespace std;
vector<int> dp;
int fibo(int n)
{
    if(n==0)
    {
        return 0;
    }
    else if(n==1)
    {
        return 1;
    }
    else if(dp[n]!=-1)
    {
        return dp[n];
    }
    return dp[n] = fibo(n-1) + fibo(n-2);
}
/*This the normal way of recursion to find the fibonacci series...where it takes O(2^n) time
complexity. We can say dp here and reduce the time complexity to O(n).*/
/*To use dp first of all we must the concept of states in it, because my most of the part
will be done if i get the correct state.*/
/*So the state is basically the level we can say or the variable that is changing on
each call...which is definitely th value of n*/
/*Make the array of dp where we will store the value, according to level, like may be 1d,
2d or 3d.*/
void solve(){
    int n;
    cin>>n;
    dp.assign(n+1, -1);
    cout<<fibo(n)<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1; while(t--){
        solve();
    }
    return 0;
}