/*
 * given strings of lowercase alphabets A of size N and integer array B of size Q,
 * return array of integers C of size Q where C[i] = no of palindrome centred at index B[i]
 * HINT:- only odd length palindrome have a centre. 
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> countPalindromesCenteredAt(string A, vector<int> B) {
    int N = A.size();
    int Q = B.size();
    vector<int> C(Q);
    
    for (int i = 0; i < Q; i++) {
        int center = B[i];
        int count = 1;  // Every character is a palindrome of length 1
        int left = center - 1;
        int right = center + 1;
        
        // Expand around the center
        while (left >= 0 && right < N && A[left] == A[right]) {
            count++;
            left--;
            right++;
        }
        
        C[i] = count;
    }
    
    return C;
}

int main() {
    string A;
    cin >> A;
    
    int Q;
    cin >> Q;
    
    vector<int> B(Q);
    for (int i = 0; i < Q; i++) {
        cin >> B[i];
    }
    
    vector<int> result = countPalindromesCenteredAt(A, B);
    
    for (int i = 0; i < Q; i++) {
        cout << result[i];
        if (i < Q - 1) cout << " ";
    }
    cout << endl;
    
    return 0;
}

