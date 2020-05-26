#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, d;
    cin >> n >> d;
    int a = (d*2)+1;
    for (int i = 1; i <= n; i++) {
        if ( a*i >= n ) {
            cout << i << endl;
            break;
        }
    }
}
