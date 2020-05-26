#include <iostream>
using namespace std;

int main(){
    int a,b;
    char op;

    cin >> a >> op >> b;

    if ( op == '+' ) {
        a = a + b;
    } else if ( op == '-') {
        a = a - b;
    }

    cout << a << endl;
}
