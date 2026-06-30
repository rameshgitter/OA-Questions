#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;

int main() {
    int N, K;
    if (!(cin >> N >> K)) return 0;

    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    vector<vector<ll>> dp(K + 1, vector<ll>(N + 1, LLONG_MAX));

    for (int i = 1; i <= N; i++) {
        int max_val = A[1], min_val = A[1];
        for (int j = 1; j <= i; j++) {
            max_val = max(max_val, A[j]);
            min_val = min(min_val, A[j]);
        }
        dp[1][i] = (ll)(max_val - min_val) * i;
    }

    for (int k = 2; k <= K; k++) {
        for (int i = k; i <= N; i++) {
            int max_val = A[i], min_val = A[i];
            for (int p = i; p >= k; p--) {
                max_val = max(max_val, A[p]);
                min_val = min(min_val, A[p]);
                
                if (dp[k - 1][p - 1] != LLONG_MAX) {
                    ll cost = (ll)(max_val - min_val) * (i - p + 1);
                    dp[k][i] = min(dp[k][i], dp[k - 1][p - 1] + cost);
                }
            }
        }
    }

    cout << dp[K][N] << endl;

    return 0;
}
