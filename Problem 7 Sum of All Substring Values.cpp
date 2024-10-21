#include <iostream>
#include <string>
#include <vector>
#include <numeric> // For std::accumulate
using namespace std;

vector<string> findAllSubstrings(const string& number) {
    vector<string> substrings;
    int length = number.length();

    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j <= length; j++) {
            substrings.push_back(number.substr(i, j - i));
        }
    }

    return substrings;
}

int sumOfSubstrings(const string& number) {
    vector<string> substrings = findAllSubstrings(number);
    int totalSum = 0;

    for (const auto& s : substrings) {
        totalSum += stoi(s); // Convert substring to integer and add to totalSum
    }

    return totalSum;
}

int main() {
    string number;
    cin >> number;

    int totalSum = sumOfSubstrings(number);
    cout << totalSum << endl;

    return 0;
}
