#include <bits/stdc++.h>
using namespace std;

int main(){
    double w, h, x, y;
    cin >> w >> h >> x >> y;

    double area;
    int num = 0;

    area = (w*h)/2;
    cout << setprecision(6) << area;
    if ( x == (w/2) && y == (h/2) ) {
        num = 1;
        cout << " " << num << endl;
    } else {
        cout << " " << num << endl;
    }
    return 0;
    
}
