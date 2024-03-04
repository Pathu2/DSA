#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
int dp[101][100100];

int rec(int level, int sum_left, vector<int> &arr)
{
    //purnate
    
    //basecase
    if(level==arr.size())
    {
        if(sum_left==0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    //cache check
    if(dp[level][sum_left]!=-1)
    {
        return dp[level][sum_left];
    }
    //compute/transition
    /*Dont take wala transition*/
    int ans = rec(level+1, sum_left,arr);
    if(sum_left>=arr[level])
    {
        ans = ans || rec(level+1, sum_left-arr[level], arr);
    }
    return dp[level][sum_left] = ans;
    //return
}

void printset(int level, int sum_left, int q, vector<vector<int>> &ans, int n, vector<int> &arr)
{
    //basecase
    if(level==n)
    {
        return;
    }
    //compute
    if(rec(level+1, sum_left, arr))
    {
        printset(level+1, sum_left, q, ans, n, arr);
    }
    else if(rec(level+1, sum_left-arr[level], arr))
    {
        ans[q].push_back(level);
        printset(level+1, sum_left-arr[level], q, ans, n, arr);
    }
}

vector<vector<int>> subset_queries(vector<int> &arr, vector<int> &queries) {
    vector<vector<int>> ans;
    int q= queries.size();
    int n= arr.size();
    ans.resize(q);
    memset(dp, -1, sizeof(dp));
    for(int i = 0;i<q;i++)
    {
        if(rec(0, queries[i], arr))
        {
            printset(0, queries[i], i, ans, n, arr);
        }
        else
        {
            ans[i].push_back(-1);
        }
    }
    return ans;
}

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)cin >> arr[i];
    vector<int> queries(Q);
    for (int i = 0; i < Q; i++)cin >> queries[i];
    auto ans = subset_queries(arr, queries);

    // checker.
    if (ans.size() != Q) {
        cout << 101 << endl;
        return;
    }
    for (int i = 0; i < Q; i++) {
        auto x = ans[i];
        if (x.size() == 0) {
            cout << 101 << endl;
            continue;
        }
        if (x.size() == 1 && x[0] == -1) {
            cout << -1 << endl;
            continue;
        }
        ll sum = 0, p = -10;
        for (auto y : x) {
            if (y < 0 || y >= N || p >= y ) { // valid 0-indexed.
                sum = -1111;
                break;
            }
            p = y;
            sum += arr[y];
        }
        if (sum == queries[i]) {
            cout << 1 << endl;
        }
        else cout << 101 << endl;
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}