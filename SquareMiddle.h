#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;

LL fpow(LL a, LL n) {
    LL ans = 1;
    while (n) {
        if (n & 1) ans *= a;
        a *= a;
        n >>= 1;
    }
    return ans;
}

class SquareMiddle{
private:
    LL m;
    LL x;
    LL mod;
public:
    SquareMiddle() {
        x = 0;
        m = 10;
        mod = fpow(10, m);
    }
    void setSeed(LL x0) {
        x = x0;
    }
    inline LL rand() {
        x = x * x;
        for (int i = 0; i < m / 2; i++) x /= 10;
        x %= mod;
        return x;
    }
    LL up_bound() {
        return mod;
    }
};