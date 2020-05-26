#include <bits/stdc++.h>
using namespace std;

int main() {
    long int s;cin >> s;
    if ( s <= 1000000000 ) {
        cout << 0 << " " << 0 << " " << s << " " << 0 << " " << 0 << " " << 1 << endl;
    } else {
        long int x;
        for (long int i = 2; i < s; i++) {
            x = s;
            if ( x%i == 0 && x/i <= 1000000000 ) {
                x = i;
                break;
            }
        }
        cout << 0 << " " << 0 << " " << s/x << " " << 0 << " " << 0 << " " << x << endl;
    }
}
