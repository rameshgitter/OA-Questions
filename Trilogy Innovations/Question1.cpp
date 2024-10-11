// It was a String DP question - ChatGPT did it for me
/*
Problem Description

You are given two strings S and T. 
You need to detemine the number of distinct ways to transform S into T by deleting some (or none) of its characters without rearranging the remaining characters

Note: The answer can be huge so take the modulo with (10^9+7).

Problem Constraints

• 1 <= |S| <= 10^4
• 1 <= [T] << 100
• All strings have only lowercase English letters.

Input Format
• First argument is a string S.
• Second argument is string T.

Output Format
• Return an integer denoting required answer.
*/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int numDistinctWays(string S, string T) {
    int n = S.length();
    int m = T.length();
    
    vector<vector<int64_t>> dp(n+1, vector<int64_t>(m+1, 0));

    // Initialize base cases
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 1;  // T is empty
    }
    
    // Fill dp table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (S[i-1] == T[j-1]) {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % MOD;
            } else {
                dp[i][j] = dp[i-1][j] % MOD;
            }
        }
    }
    
    return dp[n][m];
}

int main() {
    string S, T;
    cin >> S >> T;
    cout << numDistinctWays(S, T) << endl;
    return 0;
}

