#include <iostream>
#include <vector>
using namespace std;


void findPattern(string s, string p) {
    int n = s.size(), m = p.size();
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++)
            if (s[i + j] != p[j]) break;
        if (j == m) cout << "Pattern found at index " << i << "\n";
    }
}


int main()
{
    string s="rtyuiertyuivgbhnjm";
    string t="rtyui";

    findPattern(s,t);

    return 0;
}
