#include<bits/stdc++.h>
using namespace std;

int f(int n,int k, vector<int>&a, int sum, int i, int b){
    if(k==3 && sum==n) return 1;
    if(sum==n && b!=k) return 0;
    if(sum!=n && b==k) return 0;

    int take=f(n,k,a,sum+a[i],i,b+1);
    int nottake=f(n,k,a,sum,i+1,b);

    return take+nottake;
}

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        a[i]=i+1;
    }

    cout<<f(n,k,a,0,n-1,0)<<endl;
}