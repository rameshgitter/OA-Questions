#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> energy(n);
    vector<int> activation_cost(n);
    
    // Read energy values
    for (int i = 0; i < n; i++) {
        cin >> energy[i];
    }
    
    // Read activation costs
    for (int i = 0; i < n; i++) {
        cin >> activation_cost[i];
    }
    
    // Calculate net benefit for each crystal (energy - activation cost)
    vector<pair<int, int>> crystals; // {net_benefit, index}
    for (int i = 0; i < n; i++) {
        int net_benefit = energy[i] - activation_cost[i];
        crystals.push_back({net_benefit, i});
    }
    
    // Sort by net benefit in descending order
    sort(crystals.begin(), crystals.end(), greater<pair<int, int>>());
    
    // Select top K crystals and calculate total energy
    long long total_energy = 0;
    vector<int> selected_indices;
    
    for (int i = 0; i < k; i++) {
        int idx = crystals[i].second;
        selected_indices.push_back(idx);
        total_energy += energy[idx];
    }
    
    // If there's a sequential chain reaction bonus, we might need to consider
    // the order of activation. For now, assuming simple sum.
    
    // The problem mentions sequential chain reaction, but without clear rules,
    // I'll implement a basic version that considers adjacent bonuses
    
    // Sort selected indices to check for sequential bonuses
    sort(selected_indices.begin(), selected_indices.end());
    
    // Add bonus for consecutive crystals (chain reaction effect)
    long long chain_bonus = 0;
    for (int i = 1; i < selected_indices.size(); i++) {
        if (selected_indices[i] == selected_indices[i-1] + 1) {
            // Adjacent crystals get a small bonus (10% of smaller energy)
            int bonus = min(energy[selected_indices[i]], energy[selected_indices[i-1]]) / 10;
            chain_bonus += bonus;
        }
    }
    
    cout << total_energy + chain_bonus << endl;
    
    return 0;
}

// Alternative approach using dynamic programming for more complex chain reactions
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> energy(n);
    vector<int> activation_cost(n);
    
    for (int i = 0; i < n; i++) {
        cin >> energy[i];
    }
    
    for (int i = 0; i < n; i++) {
        cin >> activation_cost[i];
    }
    
    // DP approach: dp[i][j] = maximum energy using j crystals from first i crystals
    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, LLONG_MIN));
    dp[0][0] = 0;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            // Don't take crystal i-1
            dp[i][j] = dp[i-1][j];
            
            // Take crystal i-1
            if (j > 0 && dp[i-1][j-1] != LLONG_MIN) {
                long long energy_gain = energy[i-1] - activation_cost[i-1];
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + energy_gain);
            }
        }
    }
    
    cout << dp[n][k] << endl;
    return 0;
}
*/
