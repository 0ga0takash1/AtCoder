#include <bits/stdc++.h>
using namespace std;

int main(){
    double n;
    int a = 0;
    cin >> n;

    char str[256];
    for (int i = 0; i < n; i++) {
        cin >> str;
    }

    for (int i = 0; i < n; i++){
        if ( str[i] == 'R' ) {
            a++;
        }
    }

    if( a > (n / 2)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
