#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    int l[100];
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }

    int ans = 0;
    int now = 0;
    for (int i = 0; i < (n+1); i++) {
        now += l[i];
        ans++;
        if ( now > x ) {
            break;
        }
    }

    cout << ans << endl;
}
