#include <bits/stdc++.h>
using namespace std;

int main(){
    int s,kami2,simo2;
    cin >> s;

    kami2 = (s-s%100)/100;
    simo2 = s%100;

    if ( kami2 <= 12 && kami2 > 0) {
        if ( simo2 <= 12 && simo2 > 0 ) {
            cout << "AMBIGUOUS" << endl;
        } else {
            cout << "MMYY" << endl;
        }
    } else {
        if ( simo2 <= 12 && simo2 > 0 ) {
            cout << "YYMM" << endl;
        } else {
            cout << "NA" << endl;
        }
    }
}
