#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

int main() {
  using namespace std;
  namespace mp = boost::multiprecision;
  using Real = mp::number<mp::cpp_dec_float<1024>>;

  Real a, b, c;
  cin >> a >> b >> c;

  if (mp::sqrt(a) + mp::sqrt(b) < mp::sqrt(c)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" <<endl;
  }
}
