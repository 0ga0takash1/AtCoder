#include <bits/stdc++.h>
#include "Eigen/Dense"
using Eigen::MatrixXd;
using namespace std;

int main() {
/*
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    int flag = 1;
    double a_h = a/h;
    double b_w = b/w;
    if ( a_h > b_w*2 || a_h*2 < b_w ) {
        flag = 0;
    }

    if ( flag ) {
        int ans[w][h];
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if ( j < a ) {
                    cout << 1;
                } else {
                    cout << 0;
                }
            }
            cout << endl;
        }
    } else {
        cout << "No" << endl;
    }
*/
    MatrixXd m(2,2);
    m(0,0) = 3;
    m(1,0) = 2.5;
    m(0,1) = -1;
    m(1,1) = m(1,0) + m(0,1);
    std::cout << m << std::endl;
    return 0;
}
