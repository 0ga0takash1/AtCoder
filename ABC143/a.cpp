#include <bits/stdc++.h>
using namespace std;

#define Sort(x) sort(x.begin(), x.end())
#define Sort_rev(x) sort(x.begin(), x.end(), greater<int>())
#define ll long long

int main() {
    int a, b;
    cin >> a >> b;
    if ( a-(b*2) > 0 ) {
        cout << a-(b*2) << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}
