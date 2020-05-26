#include <bits/stdc++.h>
using namespace std;

#define Sort(x) sort(x.begin(), x.end())
#define Sort_rev(x) sort(x.begin(), x.end(), greater<int>())
#define ll long long

int main() {
    int a, b;
    cin >> a >> b;
    if ( a >= 10 || b >= 10 ) {
        cout << -1 << endl;
    } else {
        cout << a*b << endl;
    }
    return 0;
}
