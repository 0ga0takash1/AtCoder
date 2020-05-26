#include <bits/stdc++.h>
using namespace std;

#define Sort(x) sort(x.begin(), x.end())
#define Sort_rev(x) sort(x.begin(), x.end(), greater<int>())
#define ll long long

int main() {
    int n;
    cin >> n;
    int flag = 0;
    for (int i = 1; i <= 9; ++i) {
        if ( n%i == 0 ) {
            if ( 1 <= n/i && n/i <= 9 ) {
                flag = 1;
            }
        }
    }

    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}
