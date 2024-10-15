#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int toys(vector<int>& w) {
    sort(w.begin(), w.end());
    int containers = 0;
    int n = w.size();
    int i = 0;

    while (i < n) {
        int minWeight = w[i];
        int maxWeight = minWeight + 4;
        while (i < n && w[i] <= maxWeight) {
            i++;
        }
        containers++;
    }

    return containers;
}

int main() {
    int n;
    cin >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    cout << toys(w) << endl;

    return 0;
}
