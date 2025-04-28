/*
 * You have an integer array distances of size n, 
 *  each element represents an employee’s signed distance from the office at position 0 (negative = left, positive = right). 
 * You are also given two integers, start and end, defining the inclusive distance range. 
 * Print (or return) all elements distances[i] such that
 * start ≤ distances[i] ≤ end
*/

#include <iostream>
#include <vector>

// Filters and prints distances in the inclusive range [start, end]
void printInRange(const std::vector<int>& distances, int start, int end) {
    for (int d : distances) {                     // range-based for loop :contentReference[oaicite:0]{index=0}
        if (d >= start && d <= end) {
            std::cout << d << ' ';
        }
    }
    std::cout << '\n';
}

int main() {
    // Example data
    std::vector<int> distances = { -10, -5, -2, 0, 3, 8, 12 };
    int start = -2, end = 8;

    std::cout << "Employees within [" 
              << start << ", " << end << "]: ";
    printInRange(distances, start, end);
    return 0;
}

  
