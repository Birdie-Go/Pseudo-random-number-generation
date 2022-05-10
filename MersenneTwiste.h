#include <bits/stdc++.h>
using namespace std;

class MersenneTwiste{
private:
    uint32_t w, n, m, r, a, f, u, d, s, b, t, c, l;
    uint32_t index;
    uint32_t* MT;
    uint32_t lower_mask, upper_mask;
public:
    MersenneTwiste() {
        w = 32;
        n = 624;
        m = 397;
        r = 31;
        a = 0x9908B0DF;
        f = 1812433253;
        u = 11;
        d = 0xFFFFFFFF;
        s = 7;
        b = 0x9D2C5680;
        t = 15;
        c = 0xEFC60000;
        l = 18;
        index = n + 1;
        MT = (uint32_t*)malloc(n * sizeof(uint32_t));
        lower_mask = (1ull << r) - 1;
        upper_mask = (1ull << r);
    }

    ~MersenneTwiste() {
        free(MT);
    }

    void setSeed(uint32_t x0) {
        uint32_t i;
        MT[0] = x0;
        for (i = 1; i < n; i++)
            MT[i] = (f * (MT[i - 1] ^ (MT[i - 1] >> 30)) + i);
        index = n;
    }

    inline void Twist() {
        uint32_t x, xA;
        for (uint32_t i = 0; i < n; i++) {
            x = (MT[i] & upper_mask) + (MT[(i + 1) % n] & lower_mask);
            xA = x >> 1;
            if (x & 0x1)
                xA ^= a;
            MT[i] = MT[(i + m) % n] ^ xA;
        }
        index = 0;
    }

    inline uint32_t rand() {
        uint32_t y;
        uint32_t i = index;
        if (index >= n) {
            Twist();
            i = index;
        }
        y = MT[i];
        index = i + 1;
        y ^= (y >> u);
        y ^= (y << s) & b;
        y ^= (y << t) & c;
        y ^= (y >> l);
        return y;
    }

    unsigned long long up_bound() {
        return (1ull << 32);
    }
};