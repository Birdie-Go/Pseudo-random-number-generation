#include <bits/stdc++.h>
using namespace std;

class xorshift128{
private:
    unsigned long x, y, z;
public:
    xorshift128() {
        x = 123456789;
        y = 362436069;
        z = 521288629;
    }
    void setSeed() {
        x = 123456789;
        y = 362436069;
        z = 521288629;
    }
    inline unsigned long rand() {
        unsigned long t;
        x ^= x << 16;
        x ^= x >> 5;
        x ^= x << 1;
        t = x;
        x = y;
        y = z;
        z = t ^ x ^ y;
        return z;
    }
    unsigned long long up_bound() {
        return (1ull << 32);
    }
};