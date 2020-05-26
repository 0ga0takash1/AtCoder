#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int b[n-1];
    for (int i = 0; i < n-1; ++i) {
        cin >> b[i];
    }

    std::vector<int> v;
    for (int i = 0; i < n-1; ++i) {
        if ( i == 0 ) {
            v.push_back(b[i]);
            if ( b[i] <= b[i+1] ) {
                v.push_back(b[i]);
            } else {
                v.push_back(b[i+1]);
            }            
        } else {
            if ( i != n-2 ) {
                if ( b[i] <= b[i+1] ) {
                    v.push_back(b[i]);
                } else {
                    v.push_back(b[i+1]);
                }
            } else {
                v.push_back(b[i]);
            }

        }
    }
    cout << accumulate(v.begin(), v.end(), 0LL) << endl;
    return 0;
}
