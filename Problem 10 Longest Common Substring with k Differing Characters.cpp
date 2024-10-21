#include <iostream>
#include <string>
#include <vector>
using namespace std;

int substringDiff(int k, const string& s1, const string& s2) {
    int maxLength = 0;
    int len1 = s1.length();
    int len2 = s2.length();

    for (int start1 = 0; start1 < len1; start1++) {
        for (int start2 = 0; start2 < len2; start2++) {
            int length = 0;
            int diffCount = 0;

            while (start1 + length < len1 && start2 + length < len2) {
                if (s1[start1 + length] != s2[start2 + length]) {
                    diffCount++;
                }
                if (diffCount > k) {
                    break;
                }
                length++;
            }

            maxLength = max(maxLength, length);
        }
    }

    return maxLength;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        string s1, s2;
        cin >> k >> s1 >> s2;
        cout << substringDiff(k, s1, s2) << endl;
    }

    return 0;
}
