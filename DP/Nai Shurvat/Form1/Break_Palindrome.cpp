/*In this question we have been given a string, and we have to break the string
in the substring such that each subtring is a palindrome, we have to give minimum number
of such breaks*/

/*This question is done and dusted*/

#include<bits/stdc++.h>
using namespace std;

int n;
string s;
vector<vector<int>> pal;

int pali(int l, int r) {
    if (r - l <= 1) {
        return (s[l] == s[r]);
    }

    if (pal[l][r] != -1) {
        return pal[l][r];
    }

    int ans = 0;
    if (s[l] == s[r]) {
        ans = pali(l + 1, r - 1);
    }
    
    pal[l+1][r] = pali(l + 1, r);
    pal[l][r-1] = pali(l, r - 1);
    return pal[l][r] = ans;
}

int rec(int level)
{
    /*First, lets understand the logic.....if i have a string abacab
    Firstly i can check whether the string is alrady a palindrome or not..if so then we
    will return 0.............

    Then if the string is not already a palidrome, we have two possibilities...which are
    either break the string at the current level that is take only take that particular 
    character or we break at a plaindrome...
    for this we will take a for loop and will find the palindorme ans will make transitions
    accordinly..............
    */

    //pruning
    
    if(pal[level][n-1]==1)
    {
        return 0;
    }

    //basecase
    if(level==n-1)
    {
        return 0;
    }
    //cache

    //transition/compute
    int ans = 1 + rec(level+1);
    for(int i = level+1;i<n;i++)
    {
        if(pal[level][i]==1)
        {
            if(i<n-1)
            {
                ans = min(ans, 1 + rec(i+1));
            }
        }
    }
    return ans;
    //return
}


void solve() {
    cin >> n >> s;
    pal.assign(n, vector<int>(n, -1));
    pali(0, n - 1);
    // for(int i= 0;i<n;i++)
    // {
    //     for(int j = 0;j<n;j++)
    //     {
    //         cout<<pal[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<rec(0)<<endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1; 
    while (t--) {
        solve();
    }
    return 0;
}
