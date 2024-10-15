#include <iostream>
#include <vector>
using namespace std;

int getWays(int n, vector<int>& c) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int coin : c) {
        for (int amount = coin; amount <= n; amount++) {
            dp[amount] += dp[amount - coin];
        }
    }

    return dp[n];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> c(m);
    for (int i = 0; i < m; i++) {
        cin >> c[i];
    }

    cout << getWays(n, c) << endl;

    return 0;
}
