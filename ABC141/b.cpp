#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int flag = 0;
    int a = 0;
    int b = 0;
    for (int i = 0; i < s.length(); ++i) {
        if ( i%2 == 0 ) {
            if ( s[i] == 'R' || s[i] == 'U' || s[i] == 'D' ) {
                a++;
            } else {
                break;
            }
        } else {
            if ( s[i] == 'L' || s[i] == 'U' || s[i] == 'D' ) {
                b++;
            } else {
                break;
            }
        }

    }

    if ( a+b == s.length()) {
        flag = 1;
    }
    cout << (flag ? "Yes" : "No" ) << endl;
    return 0;
}
