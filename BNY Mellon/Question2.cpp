#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> layers(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &layers[i]);
    }
    int max_val = *max_element(layers.begin(), layers.end());
    int O = 0, E = 0;
    for (int layer : layers) {
        int delta = max_val - layer;
        O += delta % 2;
        E += delta / 2;
    }
    int candidate1 = 2 * E;
    int candidate2 = 2 * O - 1;
    int ans = max(candidate1, candidate2);
    // In case all layers are already equal, ans is 0
    if (max_val == 0 || ans < 0) ans = 0;
    printf("%d\n", ans);
    return 0;
}
