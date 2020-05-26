#include <bits/stdc++.h>
using namespace std;

int array_check(int array[], int key, int size ) {
    for (int i = 0; i < size; i++) {
        if ( key == array[i] ) {
            return 0;
        }
    }

    return 1;
}


int main(){
    int n,m;
    cin >> n >> m;
    int a[100000];
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    int up = 0;
    long long ans = 1;
    while ( up < n ) {
        if ( array_check(a, up+1, m) == 1 ) {
            up++;
            if ( array_check(a, up+1, m) == 1 ) {
                ans *= 2;
                up++;
            }
        } else if ( array_check(a, up+1, m) == 0
                    && array_check(a, up+2, m) == 1 ) {
            up = up+2;
        } else if ( array_check(a, up+1, m) == 0
                    && array_check(a, up+2, m) == 0) {
            cout << 0 << endl;
            return 0;
        }
    }

    ans = ans % 1000000007;
    cout << ans << endl;
    return 0;
}
