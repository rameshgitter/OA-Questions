#include <vector>
#include <algorithm>

int minMoves(std::vector<int> arr) {
    long long count_zeros = 0;
    long long count_ones = 0;
    
    long long swaps_zeros_first = 0;
    long long swaps_ones_first = 0;
    
    for (int num : arr) {
        if (num == 0) {
            // For 0s to come first, this 0 must cross all 1s seen so far
            swaps_zeros_first += count_ones;
            count_zeros++;
        } else {
            // For 1s to come first, this 1 must cross all 0s seen so far
            swaps_ones_first += count_zeros;
            count_ones++;
        }
    }
    
    // Return the minimum of the two strategic arrangements
    return std::min(swaps_zeros_first, swaps_ones_first);
}
