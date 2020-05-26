#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int ans = 0;
    int a[256] = {};

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int i = 0; i < n; i++){
        int R = a[i];
        for (int j = 0; j < n;j++){
            int G = a[j];
            for (int k = 0; k < n; k++){
                int B = a[k];

                if ( R > abs(G-B) && R < abs(G+B)){
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
}
