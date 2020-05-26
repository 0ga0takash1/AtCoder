#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;
    long long ans = 0;
    long long now = a;
    if ( b != 1 ) {
        ans = 1;
        while (now < b) {
            now += (a-1);
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
