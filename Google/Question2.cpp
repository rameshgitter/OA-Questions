// Author: pixelpilgrims
#include<bits/stdc++.h>
using namespace std;

// Google OA correct soln
/* More Ones
You are given a string S that consists only of Os and is.

Task: Determine the number of substrings that have more is than Os.

Note: A substring of a string is a sequence obtained by removing zero or more characters from either/both the frontand back of the string. 
The substrings of string "101" are ("101", "10", "1", "0", "01", "1"), "11" cannot be called the substring of "101" because it cannot be obtained by removing characters from the front or back of "101".

Example: 

Assumption

• S="0111"

Approach: 

The substrings of "0111" that have more is than Os are ["011","0111", "1", "11", "111", "1", "11", "1"]

Therefore, the answer is 8 substrings.
*/

/*
inline void solve(){
	string s; cin>>s; //  binary string
	int n = s.size();
	int count = 0; 
	for(int i=0; i<n; i++){
		int one = 0, zero = 0;
		for(int j=i; j<n; j++){
			if(s[j] == '1') one++;
			else zero++;
			if(one > zero) count++;
		}
	}
	cout << count << endl;
}
*/

class FenwickTree {
private:
    vector<int> tree;
    int n;

public:
    FenwickTree(int size) {
        n = size;
        tree.resize(n + 1, 0);
    }

    void update(int index, int value) {
        while (index <= n) {
            tree[index] += value;
            index += index & (-index);
        }
    }

    int query(int index) {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & (-index);
        }
        return sum;
    }
};

inline void solve(){
    string s; 
    cin >> s; // binary string
    int n = s.size();
    int offset = n + 1; // To handle negative prefix sums
    FenwickTree bit(2 * n + 2); // Fenwick tree size
    
    int count = 0, prefixSum = 0;
    bit.update(offset, 1); // Initial prefix sum of 0
    
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') 
            prefixSum++;
        else 
            prefixSum--;
        
        // Count the number of prefix sums less than the current prefix sum
        count += bit.query(prefixSum + offset - 1);
        
        // Update the BIT with the current prefix sum
        bit.update(prefixSum + offset, 1);
    }
    
    cout << count << endl;
}

int main(){
	int t; cin>>t;
	while(t--) solve();
	return 0;
}

