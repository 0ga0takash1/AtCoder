#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,q;
    cin >> n >> q;
    int ans = n;
    char str[256];
    for (int i = 0; i < n; i++) {
        cin >> str;
    }

    char pos[256];
    char LorR[256];
    for (int i = 0; i < q; i++) {
        cin >> pos[i] >> LorR[i];
    }

    for (int i = 0; i < q; i++){
        if ((pos[0] == str[0] && LorR[0] == 'L') ||
            (pos[n-1] == str[n-1] && LorR[n-1] == 'R')) {
            ans--;
        }
    }
    cout << ans << endl;
}
