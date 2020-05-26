#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int l = s.length();

    std::vector<int> v(l, 1);
    for (int i = 0; i < l; i++) {
        int temp;
        if ( s[i] == 'L' ) {
            temp = s[i-1];
            s[i-1] += s[i];
            s[i] = 0;
        } else if ( s[i] == 'R' ) {
            s[i+1] += s[i];

        } else if (/* condition */) {
            /* code */
        }
    }
    for (int i = 0; i < l; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}
