#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,a,b,c,d;
    int su,hu;
    cin >> n >> a >> b >> c >> d;
    su = a-1;
    hu = b-1;
    string s;
    cin >> s;

    for (int i = hu; i < d-1; i++) {
        if ( s[i+1] == '#' && s[i+2] == '#') {
            cout << "No" << endl;
            return 0;
        }
    }

    if ( c > d ) {
        for (int i = max(su, hu); i < d; i++) {
            if ( s[i-1] == '.' && s[i] == '.' && s[i+1] == '.' ) {
            } else {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}
