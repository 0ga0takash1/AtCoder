#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    int ans = 0;
    if (s[0] == s[1] && s[1] == s[2] && s[2] == s[3]) {
        /* code */
    } else {
        if ( s[0] == s[1] && s[2] == s[3]) {
            ans = 1;
        } else if ( s[0] == s[2] && s[1] == s[3]) {
            ans = 1;
        } else if ( s[0] == s[3] && s[1] == s[2]) {
            ans = 1;
        }
    }

    if ( ans == 1 ) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
