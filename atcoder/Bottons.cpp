#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    int n = 0;
    cin >> a >> b;

    for (int i = 0; i < 2; i++){
        if ( a >= b ) {
            n += a;
            a = a - 1;
        } else {
            n += b;
            b = b - 1;
        }
    }
    cout << n << endl;
}
