#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
using mpi = mp::cpp_int;
using namespace std;
using ll = long long;

ll solve(mpi X, mpi Y, mpi A, mpi B) {
    mpi cnt = 0;
    // Y > X + b * B
    // b = (Y - X) / B

    while (X * A < Y || X + B < Y) {
        cerr << "X = " << X << endl;
        cerr << "Y = " << Y << endl;
        cerr << "X * A = " << X * A << endl;
        cerr << "X + B = " << X + B << endl;
        if (X * A < X + B) {
            cerr << "* " << A << endl;
            cnt++;
            X *= A;
        } else {
            mpi l = 1;
            mpi r = (Y - X) / B;
            mpi m;
            while (r - l > 1) {
                cerr << "  l = " << l << endl;
                cerr << "  r = " << r << endl;
                m = (l + r) / 2;
                if ((X + m * B) * A > (X + m * B) + B) {
                    l = m;
                } else {
                    r = m;
                }
            }
            cerr << "+ " << l << " * " << B << endl;
            cnt += l;
            X += l * B;
        }
    }
    return (ll)cnt;
}

ll solve_slow(ll X, ll Y, ll A, ll B) {
    ll cnt = 0;
    while (X * A < Y || X + B < Y) {
        if (X * A < X + B) {
            X *= A;
        } else {
            X += B;
        }
        ++cnt;
    }
    return cnt;
}


int main() {
    ll X, Y, A, B; cin >> X >> Y >> A >> B;
    cout << solve(X, Y, A, B) << endl;
    return 0;
}
