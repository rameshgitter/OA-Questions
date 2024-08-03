// Author: pixelpilgrims
#include<bits/stdc++.h>
using namespace std;

// Google OA correct soln
/* Distinct subsequences
You are given a string S of length n. The string S consists of characters O's and 1's only.

Task:-
For each subsequence (excluding empty) for string S, you need to find its decimal representation. 
Print the number of distinct decimal values of the subsequences. Since, the answer can be veryharge, print it modulo (109+7).

Note

• O based indexing is followed.
Consider index O as the most significant bit of binary string.

• A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements. 
For example, "abc" has the following subsequences:
["a","ab","ac"," abc","b","bc","c"]

There are 2^n - 1 non-empty subsequences
*/

const int MOD = 1e9+7;
inline void solve(){
	string s; cin>>s; //  binary string
	int n = s.size();
	// A set to keep track of distinct subsequences values in decimal
    unordered_set<int> unique_values;

    // Iterate over each character in the string
    for (int i = 0; i < n; ++i) {
        int current_value = 0;
        // Consider every subsequence ending at index i
        for (int j = i; j < n; ++j) {
            current_value = (current_value << 1) | (s[j] - '0');
            unique_values.insert(current_value);
        }
    }

    // The size of the set gives the number of distinct subsequences
    cout << unique_values.size() % MOD << "\n";
	
}

int main(){
	int t; cin>>t;
	while(t--) solve();
	return 0;
}

