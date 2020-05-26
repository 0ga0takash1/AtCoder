#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,l,r,L[100000],R[100000];
    int ans = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> L[i] >> R[i];
    }
    l = L[0];
    r = R[0];

    for (int i = 1; i < m; i++){
        if ( L[i] > l){
            l = L[i];
        }

        if ( R[i] < r ) {
            r = R[i];
        }
    }

    for (int i = 1; i <= n; i++){
        if ( i >= l && i <= r ) {
            ans++;
        }
    }
    cout << ans << endl;
}
