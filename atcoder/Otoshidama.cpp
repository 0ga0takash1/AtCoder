#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,y;
    int satsu_1000 = 0;
    int satsu_5000 = 0;
    int satsu_10000 = 0;
    const int f = -1;
    cin >> n >> y;
    if ( 10000*n > y && y > 10000*n - 5000 ) {
        cout << f << f << f;
    } else {
/*
        while (1) {
            if ( y < 10000 ) {
                break;
            }
            y = y - 10000;
            satsu_10000++;
        }

        while (1) {
            if ( y < 5000 ) {
                break;
            }
            y = y - 5000;
            satsu_5000++;
        }

        while (1) {
            if ( y <= 0 ) {
                break;
            }
            y = y - 1000;
            satsu_1000++;
        }
*/

        cout << satsu_10000;
        cout << satsu_5000;
        cout << satsu_1000 << endl;
    }
}
