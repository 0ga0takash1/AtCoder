#include <bits/stdc++.h>
using namespace std;

int main(){
    int r,D,x,ans;
    cin >> r >> D >> x;
    ans = x;
    for (int i = 0;i < 10; i++){
        ans = (r*ans) - D;
        cout << ans << endl;
    }
    return 0;
}
