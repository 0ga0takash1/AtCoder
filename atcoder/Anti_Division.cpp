#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
/*
    long int ans = 0;
    for (long long i = a; i <= b; i++) {
        if ( i%c != 0 && i%d != 0 ) {
            ans++;
        }
    }
*/
    long int ans = b-a;
    long int cnum = a;
    long int num = 0;
    while ( cnum <= b ) {
        cnum += c;
        num++;
    }
    long int dnum = a;
    long int num2 = 0;
    while ( dnum <= b ) {
        dnum += c;
        num2++;
    }
    ans = ans - num-num2;
    cout << ans << endl;
}
