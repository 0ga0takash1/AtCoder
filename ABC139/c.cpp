#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long h[n];
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    long long ans = 0;
    std::vector<long long> v;
    for (int i = 0; i < n; i++) {
        if ( h[i] >= h[i+1]) {
            ans++;
            if ( i == n-1 ) {
                v.push_back(ans);
            }
        } else {
            v.push_back(ans);
            ans = 0;
        }
    }
    cout << *max_element(v.begin(), v.end()) << endl;
    return 0;
}
