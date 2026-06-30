#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N);
    int totalSum = 0;

    for(int i = 0; i < N; i++) {
        cin >> A[i];
        totalSum += A[i];
    }

    // DP array
    vector<long long> dp(totalSum + 1, 0);
    dp[0] = 1;

    for(int i = 0; i < N; i++) {
        int x = A[i];
        for(int s = totalSum; s >= x; s--) {
            dp[s] = (dp[s] + dp[s - x]) % MOD;
        }
    }

    // Sieve for primes
    vector<bool> isPrime(totalSum + 1, true);
    if(totalSum >= 0) isPrime[0] = false;
    if(totalSum >= 1) isPrime[1] = false;

    for(int i = 2; i * i <= totalSum; i++) {
        if(isPrime[i]) {
            for(int j = i * i; j <= totalSum; j += i) {
                isPrime[j] = false;
            }
        }
    }

    long long ans = 0;

    for(int s = 2; s <= totalSum; s++) {
        if(isPrime[s]) {
            ans = (ans + dp[s]) % MOD;
        }
    }

    cout << ans << "\n";

    return 0;
}
