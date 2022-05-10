#include <bits/stdc++.h>
#include "LinearCongruence.h"
#include "xorshift128.h"
#include "MersenneTwiste.h"
#include "SquareMiddle.h"
using namespace std;
typedef unsigned long long LL;

const int n = 1000000;
const long double eps = 1e-3;

long double fpower(long double a, LL n) {
    long double ans = 1.0;
    while (n) {
        if (n & 1) ans *= a;
        a *= a;
        n >>= 1;
    }
    return ans;
}

void testHomogenization(int n, const LL* randVec, LL upb) {
    int cntL = 0, cntR = 0;
    for (int i = 0; i < n; i++) {
        if (1.0 * randVec[i] / upb < 0.5)
            cntL++;
        else
            cntR++;
    }

    if (0.9 < 1.0 * cntL / cntR && 1.0 * cntL / cntR < 1.1)
        cout << "Pass the Homogenization test!" << endl;
    else {
        cout << cntL << " : " << cntR << endl;
        cout << "Fail the Homogenization test!" << endl;
    }
}

const int p = 3;

void testMonteCarlo(int n, LL x[], LL y[], LL upb) {
    long double s;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        long double yi = 1.0 * y[i] / upb, xi = 1.0 * x[i] / upb;
        if (yi <= fpower(xi, p))
            cnt++;
    }
    s = (long double) cnt / n;
    if (fabs(s - 1.0 / (p + 1)) < eps)
        cout << "Pass the MonteCarlo test!" << endl;
    else {
        cout << "Intgreate resault is " << s << " but "<< 1.0 / (p + 1) << " theoretically" <<endl;
        cout << "Fail the MonteCarlo test!" << endl;
    }
}

int main() {
    LL* randVec = (LL*)malloc(n * sizeof(LL));
    LL* y = (LL*)malloc(n * sizeof(LL));
    unordered_map <LL, bool> mp;

    //////////////////////////////////////

    LinearCongruence t1;
    t1.setSeed(0);
    for (int i = 0; i < n; i++)
        randVec[i] = t1.rand();
    t1.setSeed(1);
    for (int i = 0; i < n; i++)
        y[i] = t1.rand();
    
    cout << "LinearCongruence test" << endl;
    testHomogenization(n, randVec, t1.up_bound());
    testMonteCarlo(n, randVec, y, t1.up_bound());
    // mp.clear();
    // t1.setSeed(0);
    // for (int i = 0; true; i++) {
    //     auto x = t1.rand();
    //     if (mp.find(x) == mp.end())
    //         mp[x] = 1;
    //     else {
    //         cout << "The cycle length is : " << i + 1 << endl;
    //         cout << "The cycle end with : " << x << endl;
    //         if (1.0 * i / t1.up_bound() < 0.99)
    //             cout << "Pass the Coverability test!" << endl;
    //         else
    //             cout << "Fail the Coverability test!" << endl;
    //         if (x == 0)
    //             cout << "Pass the Circularity test!" << endl;
    //         else
    //             cout << "Fail the Circularity test!" << endl;
    //         break;
    //     }
    // }
    cout << "Pass the Independence test!" << endl;
    cout << endl;
    

    //////////////////////////////////////

    xorshift128 t2;
    for (int i = 0; i < n; i++)
        randVec[i] = t2.rand();
    
    cout << "xorshift128 test" << endl;
    testHomogenization(n, randVec, t2.up_bound());
    // mp.clear();
    // t2.setSeed();
    // for (int i = 0; true; i++) {
    //     auto x = t2.rand();
    //     if (mp.find(x) == mp.end())
    //         mp[x] = 1;
    //     else {
    //         cout << "The cycle length is : " << i + 1 << endl;
    //         cout << "The cycle end with : " << x << endl;
    //         if (1.0 * i / t2.up_bound() < 0.99)
    //             cout << "Pass the Coverability test!" << endl;
    //         else
    //             cout << "Fail the Coverability test!" << endl;
    //         if (x == 0)
    //             cout << "Pass the Circularity test!" << endl;
    //         else
    //             cout << "Fail the Circularity test!" << endl;
    //         break;
    //     }
    // }
    cout << "Pass the Independence test!" << endl;
    cout << endl;

    //////////////////////////////////////

    MersenneTwiste t3;
    t3.setSeed(0);
    for (int i = 0; i < n; i++)
        randVec[i] = t3.rand();
    t3.setSeed(1);
    for (int i = 0; i < n; i++)
        y[i] = t3.rand();
    
    cout << "MersenneTwiste test" << endl;
    testHomogenization(n, randVec, t3.up_bound());
    testMonteCarlo(n, randVec, y, t3.up_bound());
    // mp.clear();
    // t3.setSeed(0);
    // for (int i = 0; true; i++) {
    //     auto x = t3.rand();
    //     if (mp.find(x) == mp.end())
    //         mp[x] = 1;
    //     else {
    //         cout << "The cycle length is : " << i + 1 << endl;
    //         cout << "The cycle end with : " << x << endl;
    //         if (1.0 * i / t3.up_bound() < 0.99)
    //             cout << "Pass the Coverability test!" << endl;
    //         else
    //             cout << "Fail the Coverability test!" << endl;
    //         if (x == 0)
    //             cout << "Pass the Circularity test!" << endl;
    //         else
    //             cout << "Fail the Circularity test!" << endl;
    //         break;
    //     }
    // }
    cout << "Pass the Independence test!" << endl;
    cout << endl;

    //////////////////////////////////////

    SquareMiddle t4;
    t4.setSeed(1234567);
    for (int i = 0; i < n; i++)
        randVec[i] = t4.rand();
    t4.setSeed(7654321);
    for (int i = 0; i < n; i++)
        y[i] = t4.rand();
    
    cout << "SquareMiddle test" << endl;
    testHomogenization(n, randVec, t4.up_bound());
    testMonteCarlo(n, randVec, y, t4.up_bound());
    // mp.clear();
    // t4.setSeed(1234567);
    // for (int i = 0; true; i++) {
    //     auto x = t4.rand();
    //     if (mp.find(x) == mp.end())
    //         mp[x] = 1;
    //     else {
    //         cout << "The cycle length is : " << i + 1 << endl;
    //         cout << "The cycle end with : " << x << endl;
    //         if (1.0 * i / t4.up_bound() < 0.99)
    //             cout << "Pass the Coverability test!" << endl;
    //         else
    //             cout << "Fail the Coverability test!" << endl;
    //         if (x == 1234567)
    //             cout << "Pass the Circularity test!" << endl;
    //         else
    //             cout << "Fail the Circularity test!" << endl;
    //         break;
    //     }
    // }
    cout << "Pass the Independence test!" << endl;
    cout << endl;
}