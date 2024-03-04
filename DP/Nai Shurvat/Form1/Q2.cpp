#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;

int rec(int level, int k, int sum)
{
    // purnate
    if (level > n)
    {
        if (k == 0)
        {
            if (sum == n)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    // basecase
    if (k == 0)
    {
        if (sum == n)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    // cache

    // compute/transition
    /*Don't take it*/

    int ans = rec(level + 1, k, sum);


    /*Take it*/
    if (k > 0)
    {
        ans = ans + rec(level + 1, k - 1, sum + level);
    }
    /*Repeat it*/
    if (level-1 != 0 && k > 0)
    {
        
        ans = ans + rec(level+1, k - 1, sum + level-1);
        
    }
    return ans;
    // return
}

void solve()
{
    int k;
    cin >> n >> k;
    cout << rec(1, k, 0) << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}