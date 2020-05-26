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

    if ( s[su] == '.') {
        s[su] = '#';
    }
    if ( s[hu] == '.') {
        s[hu] = '#';
    }

    while (1) {
        if ( s[hu+1] == '.' || s[hu+2] == '.') {
            if ( s[hu] == '#' ) {
                s[hu] = '.';
            }

            if ( s[hu+2] == '.' ) {
                hu += 2;
            }  else {
                hu++;
            }
            s[hu] = '#';
        } else {
            break;
        }

        if ( s[su+1] == '.' || s[su+2] == '.') {
            if ( s[su] == '#' ) {
                s[su] = '.';
            }

            if ( s[su+2] == '.' ) {
                su += 2;
            }  else {
                su++;
            }
            s[su] = '#';
        } else {
            break;
        }

        if ( su >= (c-1) && hu >= (d-1) ) {
            break;
        }
    }

    if ( su == (c-1) && hu == (d-1) ) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
