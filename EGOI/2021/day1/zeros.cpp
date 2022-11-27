
#include <iostream>
#include <vector>
 
using namespace std;
 
long long multiplicity(long long a, long long b, int d) {
    if (a > b) return 0;
    if (a%d != 0) {
        a += (d-a%d);
        return multiplicity(a, b, d);
    }
    // long long diff = (b-a)/d + 1;
    return 1 + multiplicity(a/d, b/d, d);
}
 
int main() {
    long long a, b; cin >> a >> b;
    long long m2 = multiplicity(a, b, 2);
    long long m5 = multiplicity(a, b, 5);
    cout << min(m2, m5);
    return 0;
}
