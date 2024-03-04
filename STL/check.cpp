#include<bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    int a[N];
    if (N == 1) {
        cout << "-1" << endl;
        return;
    }
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int smallest = INT_MAX;         // Initialize smallest to maximum possible value
    int secondSmallest = INT_MAX;   // Initialize secondSmallest to maximum possible value

    for (int i = 0; i < N; i++) {
        if (a[i] < smallest) {
            secondSmallest = smallest;
            smallest = a[i];
        } else if (a[i] < secondSmallest && a[i] != smallest) {
            secondSmallest = a[i];
        }
    }

    if (secondSmallest == INT_MAX) {
        cout << "-1" << endl;
    } else {
        cout << secondSmallest << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
