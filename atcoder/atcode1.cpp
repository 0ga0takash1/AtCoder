#include <iostream>
using namespace std;

int main() {
    int a,b,c;
    int d = 0;
    cin >> a >> b >> c;
    for (int i = 0;i < c;i++){
        b = b - a;
        if (b < 0) break;
        d++;
    }
    cout << d << endl;
}
