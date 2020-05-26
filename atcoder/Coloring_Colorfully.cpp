#include <bits/stdc++.h>
using namespace std;

int main(){
    string zero_one;
    cin >> zero_one;
    long long size = zero_one.size();

    int ans = 0;
    long long mohan[size];
    long long Zero_one[size];

    for (int i = 0; i < size; i++){
        if ( zero_one[i] == '0' ) {
            Zero_one[i] = 0;
        } else {
            Zero_one[i] = 1;
        }
    }

    if ( Zero_one[0] == 0 ) {
        for (int i = 0; i < size; i++){
            if ( i % 2 == 0 ) {
                mohan[i] = 0;
            } else {
                mohan[i] = 1;
            }
        }
    } else {
        for (int i = 0; i < size; i++){
            if ( i % 2 == 0 ) {
                mohan[i] = 1;
            } else {
                mohan[i] = 0;
            }
        }
    }

    for (int i = 0; i < size; i++){
        if ( Zero_one[i] != mohan[i] ) {
            ans++;
        }
    }
    cout << ans << endl;
}
