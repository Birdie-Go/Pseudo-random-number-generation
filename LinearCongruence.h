#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;

class LinearCongruence{
private:
    LL a, c, m;
    LL x;
public:
    LinearCongruence() {
        a = 1554525;
        c = 1013904223;
        m = (1ull << 32);
        x = 0;
    }
    void setSeed(LL x0) {
        x = x0;
    }
    inline LL rand() {
        x = (1ll * a * x + c) % m;
        return x;
    }
    LL up_bound() {
        return (1ull << 32);
    }
};