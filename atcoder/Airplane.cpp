#include <bits/stdc++.h>
using namespace std;

int main(){
    int p,q,r,max;
    cin >> p >> q >> r;
    if ( p >= q && p >= r) {
        max = p;
    } else if ( q >= p && q >= r ) {
        max = q;
    } else {
        max = r;
    }
    cout << p + q + r - max << endl;
}
