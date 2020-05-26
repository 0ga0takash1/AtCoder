#include <bits/stdc++.h>
using namespace std;

#define Sort(x) sort(x.begin(), x.end())
#define Sort_rev(x) sort(x.begin(), x.end(), greater<int>())
typedef long long ll;
typedef int64_t i6;
//π M_PI
//deg = rad*180/M_PI

double nCr(double n , double r) {
    std::vector<std::vector<long double> > v(n + 1,std::vector<long double>(n + 1, 0));
    for (int i = 0; i < v.size(); i++) {
        v[i][0] = 1;
        v[i][i] = 1;
    }
    for (int j = 1; j < v.size(); j++) {
        for (int k = 1; k < j; k++) {
            v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
        }
    }
    return v[n][r];
}

int main() {
    int n;
    cin >> n;
    double x[n];
    double y[n];
    //int num = 1;
    double ans;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        //num *= (i+1);
    }

    if ( n == 2 ) {
        double xx = x[1] - x[0];
        double yy = y[1] - y[0];
        ans = sqrt(xx*xx+yy*yy);
    } else if ( n == 3 ) {
        double dis[3];
        double x12 = x[1] - x[0];
        double y12 = y[1] - y[0];
        dis[0] = sqrt(x12*x12+y12*y12);
        double x23 = x[2] - x[1];
        double y23 = y[2] - y[3];
        dis[1] = sqrt(x23*x23+y23*y23);
        double x31 = x[2] - x[0];
        double y31 = y[2] - y[0];
        dis[2] = sqrt(x31*x31+y31*y31);

        double dis_all = (dis[0]+dis[1]+dis[2])*6;
        ans = dis_all - ((dis[0]+dis[1]+dis[2])*2);
        ans /= 6;
    } else {
        std::vector<double> dis;
        double num = (n*(n-3))/2+n;
/*
        if (n == 4) {
            num = 6;
        } else if ( n == 5) {
            num = 10;
        } else if ( n == 6) {
            num = 15;
        } else if ( n == 7) {
            num = 20;
        } else if ( n = 8 ) {
            num = 29;
        }
*/
        for (int i = 0; i < n-1; ++i) {
            for (int j = i+1; j < n; ++j) {
                double X = x[j] - x[i];
                double Y = y[j] - y[i];
                dis.push_back(sqrt(X*X+Y*Y));
                ans = accumulate(dis.begin(), dis.end(), 0) * nCr(num, n-1);
                ans -= accumulate(dis.begin(), dis.end(), 0)*2;
                ans /= num;
            }
        }
    }

    cout << fixed << setprecision(10);
    cout << ans << endl;
    return 0;
}
