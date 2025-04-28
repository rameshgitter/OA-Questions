#include <iostream>
#include <string>

/*
 * Given two strings—a text string S of length n and a pattern string P of length m—determine the number of times P occurs in S, including overlapping occurrences 
*/

int countOccurrencesTwoPointer(const std::string& s1, const std::string& s2) {
    int n = s1.length(), m = s2.length();
    if (m == 0 || n < m) return 0;            // edge cases
    int count = 0;
    int i = 0, j = 0;
    while (i < n) {
        if (s1[i] == s2[j]) {
            ++i; ++j;
            if (j == m) {                     // found a match
                ++count;
                j = 0;                        // reset pattern pointer
                i = i - m + 1;               // rewind to allow overlap
            }
        } else {
            i = i - j + 1;                    // move to next start
            j = 0;                            // reset pattern pointer
        }
    }
    return count;
}

int main() {
    std::string text = "abababa";
    std::string pattern = "aba";
    std::cout << "Occurrences: "
              << countOccurrencesTwoPointer(text, pattern)
              << std::endl;                  // Outputs 2
    return 0;
}
