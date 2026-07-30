#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int workingWeeks(vector<int> projC) {
    long long sum = 0;
    long long max_val = 0;
    
    // Find the total sum of modules and the maximum project size
    for (int modules : projC) {
        sum += modules;
        if (modules > max_val) {
            max_val = modules;
        }
    }
    
    long long remaining_sum = sum - max_val;
    
    // Check if the largest project is strictly dominant
    if (max_val > remaining_sum + 1) {
        return 2 * remaining_sum + 1;
    } else {
        return sum;
    }
}
