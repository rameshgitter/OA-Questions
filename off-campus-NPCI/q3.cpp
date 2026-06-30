vector<int> findValidSizes(vector<int>& a) {
    int n = a.size();
    vector<int> freq(n + 1, 0);

    for (int x : a) {
        if (x <= n) freq[x]++;
    }

    vector<int> prefix(n + 1, 0);
    prefix[0] = freq[0];

    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + freq[i];
    }

    vector<int> ans;

    // k = 0 always possible
    ans.push_back(0);

    bool ok = true;

    for (int i = 0; i < n; i++) {
        if (prefix[i] < i + 1) {
            ok = false;
        }

        if (ok) {
            ans.push_back(i + 1);
        }
    }

    return ans;
}
