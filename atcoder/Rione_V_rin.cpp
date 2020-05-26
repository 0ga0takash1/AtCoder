#include <iostream>
using namespace std;

int main(){
    int a,b,c,sum1,sum2,sum3;

    cin >> a >> b >> c;

    sum1 = a + b;
    sum2 = b + c;
    sum3 = c + a;

    if ( sum1 < sum2 && sum1 < sum3 ) {
        cout << sum1 << endl;
    } else if( sum2 < sum1 && sum2 < sum3 ) {
        cout << sum2 << endl;
    } else if( sum3 < sum1 && sum3 < sum2){
        cout << sum3 << endl;
    } else if( a == b && b == c ){
        cout << sum1 << endl;
    }
}
