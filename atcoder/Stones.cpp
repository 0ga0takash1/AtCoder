#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(){
    int N;
    int ans = 0;
    cin >> N;
    string S(N, '0');

    for (int i = 0; i < N; i++){
        cin >> S[i];
    }

    for (int i = 0; i < N; i++){
        if ( S[i] == '#' && S[i+1] == '.'){
            ans++;
        }
    }
    cout << ans << endl;
}
