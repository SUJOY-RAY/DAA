#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long marcsCakeWalk(vector<int>& calorie){
    sort(calorie.rbegin(),calorie.rend());
    long long miles=0;

    for (int i = 0 ; i < calorie.size(); i++)
    {
        miles+=(1LL<<i)*calorie[i];
    }
    return miles;
}

int main() {
    int n;
    cin >> n;
    vector<int> calorie(n);
    for (int i = 0; i < n; i++) {
        cin >> calorie[i];
    }

    cout << marcsCakeWalk(calorie) << endl;

    return 0;
}





