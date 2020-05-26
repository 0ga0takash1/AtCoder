#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int length = s.length();
    int num = 0;

    for (int i = 0; i < length; i++) {
        if ( s[i] == 'o') {
            num++;
        }
    }

    if ( (15-length) >= (8-num) ) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
