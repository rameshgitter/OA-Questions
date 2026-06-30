#include <vector>
#include <stack>
#include <string>
#include <limits>

using namespace std;

string isValid(vector<int> a) {
    stack<int> s;
    int root_limit = numeric_limits<int>::min();

    for (int val : a) {
        // If we find a node who should be in the right subtree 
        // but is smaller than the root, it's invalid.
        if (val < root_limit) {
            return "NO";
        }

        // If val is greater than the stack top, it means val 
        // is in the right subtree of the stack top.
        while (!s.empty() && val > s.top()) {
            root_limit = s.top();
            s.pop();
        }

        s.push(val);
    }

    return "YES";
}
