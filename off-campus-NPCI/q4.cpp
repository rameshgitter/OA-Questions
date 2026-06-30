#include <string>
#include <vector>

using namespace std;

int firstOccurrence(string text, string searchPattern) {
    int n = text.length();
    int m = searchPattern.length();

    if (m > n) return -1;

    for (int i = 0; i <= n - m; i++) {
        bool match = true;
        for (int j = 0; j < m; j++) {
            if (searchPattern[j] != '*' && searchPattern[j] != text[i + j]) {
                match = false;
                break;
            }
        }
        if (match) return i;
    }

    return -1;
}
