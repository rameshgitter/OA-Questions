#include <bits/stdc++.h>
using namespace std;

// Problem Link: https://www.geeksforgeeks.org/problems/count-the-substring--170645/0
// Explanation video: https://www.youtube.com/watch?v=LO1qGTE-Xbo&list=WL&index=1
// Short code video: https://www.youtube.com/watch?v=UfsF7PRpyq8&list=WL&index=2
// Helper explanation provided in GFG editorial

// Function to count substrings with more or equal number of '1's compared to '0's
int countSubstring(string &s) {
    int n = s.length();

    // `dp` array to track prefix counts
    vector<int> dp(2 * n + 1, 0);

    int cnt = n; // Offset index to manage negative counts
    int minus = 0; // Tracks substrings with invalid counts

    // Precompute `dp` and `minus`
    for (int i = 0; i < n; i++) {
        if (s[i] == '0')
            cnt--;
        else
            cnt++;

        if (cnt <= n)
            minus++;

        dp[cnt]++;
    }

    int ans = 0; // Stores the total count of valid substrings
    int idx = n; // Start index for adjusting counts

    // Calculate the result using `dp` and `minus`
    for (int i = 0; i < n; i++) {
        ans += (n - i) - minus;

        if (s[i] == '1') {
            idx++;
            dp[idx]--;
            minus += dp[idx];
        } else {
            minus--;
            minus -= dp[idx];
            idx--;
            dp[idx]--;
        }
    }

    return ans;
}

int main() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        string s;
        cin >> s; // Input string

        cout << "______________________" << "\n";
        cout << countSubstring(s) << "\n";
    }

    return 0;
}
