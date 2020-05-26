#include <bits/stdc++.h>
using namespace std;

long nCr(int n, int r) {
    long ans = 1;
    for (int i = n; i > n - r; --i) {
        ans = ans*i;
    }
    for (int i = 1 ; i < r + 1; ++i) {
        ans = ans / i;
    }
    return ans;
}

long double_num(char * v[256] , int b){
    int num = 0;
    for(int i = 0; i < b; i++){
        for( int j = i+1; j < b; j++){
            if(v[i] == v[j]) num++;
        }
    }
    return num;
}

int main(){
    int n,dn,a;
    int sum = 0;
    cin >> n;

    vector<char> moji[n];
    for(int i = 0; i < n; i++){
        cin >> moji[i];
    }
    dn = double_num(moji*[n],n);

    for(int i; i < n ; i++){
        a = nCr(n,i);
        if( dn != 0 ){
            if (i == 2) {
                a = a - dn;
            } else if ( i >= 3) {
                a = a - nCr(n-2,i-2)*dn;
                if( a < 0 ) a = 0;
            }
        }
        sum += a;
    }

    sum = sum % (1000000000 + 7);
    cout << sum << endl;
}
