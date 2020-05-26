#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,d;
    cin >> n >> d;
    int nn = (n*(n-1))/2;
    int x[n][d];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            cin >> x[i][j];
        }
    }

    int num = 0;
    double distdist[45] = {};
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; i < n; j++) {
            for (int k = 0; k < d; k++) {
                distdist[num] += pow((x[i][k]-x[j][k]),2.0);
            }
            distdist[num] = sqrt(distdist[num]);
            //distdist[num] *= 10;
            num++;
        }
    }

    int ans = 0;
    for (int i = 0; i < nn; i++) {
        if ( fmod(distdist[i], 10) == 0) {
            ans++;
        }
    }
    cout << ans << endl;
}
