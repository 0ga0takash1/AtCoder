#include <bits/stdc++.h>
using namespace std;

int main(){
    int num[5] = {};
    int k;
    int ans = 0;
    for (int i = 0; i < 5; i++) {
        cin >> num[i];
    }

    cin >> k;

    for (int i = 0; i < 4; i++) {
        for (int j = i+1; j < 5; j++){
            if ( num[j] - num[i] > k) {
                ans = 1;
            }
        }
    }

/*
    if ( ans == 1 ) {
        cout << ":(" << endl;
    } else {
        cout << "Yay!" << endl;
    }
*/
    cout << (ans == 1 ? ":(" : "Yay!") << endl;
}
