#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k, q;
    cin >> n >> k >> q;
    long long a[q];
    for (int i = 0; i < q; ++i) {
        cin >> a[i];
    }

    std::vector<long long> v(n, k-q);
    for (int i = 0; i < q; ++i) {
        v[a[i]-1]++;
    }

    for (int i = 0; i < n; ++i) {
        if ( v[i] > 0 ) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
