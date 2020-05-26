#include <bits/stdc++.h>
using namespace std;

int main(){
    int s;
    int ans = 0;
    cin >> s;

    int one = s % 10;
    int ten = (s/10)%10;
    int hun = (s/100)%10;
    int th = (s/1000)%10;

    if ( one == ten || ten == hun ||  hun== th) {
        ans = 1;
    }
    if ( ans == 1) {
        cout << "Bad" << endl;
    } else {
        cout << "Good" << endl;
    }
}
