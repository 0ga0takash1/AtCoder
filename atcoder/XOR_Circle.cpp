#include <bits/stdc++.h>
using namespace std;

int find ( int v[], int size, int num) {
    for (int i = 0; i < size; i++) {
        if ( v[i] == num) {
            return 1;
        }
    }
    return 0;
}


int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    int num;

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n; j++) {
            num = a[i] ^ a[j];
        }

        if (find(a, n, num)) {
            ans++;
        }
    }
    
    cout << (ans == (n-1) ? "Yes": "No") << endl;
}
