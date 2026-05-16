// problem: https://neetcode.io/problems/multiply-strings/question
// approach v2: Fourier Transform; interpret multiplication,
//              i.e. convolution in time domain, as element-wise
//              multiplication in freq domain, reducing work from O(M*N)
//              to O((M + N) log(M + N))
//
//              example:
//                prod[i+j] += num1[i]*num2[j]
//                   12
//                 x 34
//                 ----
//                    8  prod[0+0] += 8
//                   40  prod[0+1] += 40
//                   60  prod[1+0] += 60 = 100
//                  300  prod[1+1] += 300
//                  raw convolution   --> [8,100,300]
//                  normalize carries --> [8,0,4] (i.e., 408)
//
// complexity: O((M + N) log(M + N)) time, O(M + N) space, M := length num1, N := length num2
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>

class Solution {
 private:
  const double pi = 3.14159265358979323846;

 public:
  void dft (std::vector<std::complex<double>>& w, bool invert) {
    // Discrete Fourier Transform
    // (slow, O(N^2); included for comparison w/ FFT below)
    const int N = w.size();
    std::vector<std::complex<double>> res(N);

    double sign = invert ? 1.0 : -1.0;
    for (int k = 0; k < N; ++k) {
      std::complex<double> s(0.0, 0.0);
      for (int j = 0; j < N; ++j) {
        double theta = 2*pi*j*k/N;
        s += w[j]*std::exp(std::complex<double>(0.0, sign*theta));
      }
      if (invert) s /= N;
      res[k] = s;
    }
    w = res;
  }

  void fft (std::vector<std::complex<double>>& w, bool invert) {
    // Fast Fourier Transform, O(n log n)
    // Cooley-Tukey: decompose into even and odd coeffs and recurse
    const int N = w.size();
    if (N == 1) return;

    double sign = invert ? 1.0 : -1.0;
    std::vector<std::complex<double>> o(N/2), e(N/2), res(N);
    for (int j = 0; j < N/2; ++j) {
      e[j] = w[2*j];
      o[j] = w[2*j + 1];
    }
    fft(e, invert);
    fft(o, invert);
    for (int k = 0; k < N/2; ++k) {
      double theta = 2*pi*k/N;
      res[k    ] = e[k] + std::exp(std::complex<double>(0.0, sign*theta))*o[k];
      res[k + N/2] = e[k] - std::exp(std::complex<double>(0.0, sign*theta))*o[k];
      if (invert) {
        res[k      ] /= 2.0;
        res[k + N/2] /= 2.0;
      }
    }
    w = res;
  }

  std::string multiply (const std::string& num1, const std::string& num2) {
    std::vector<std::complex<double>> w1, w2;
    for (int i = num1.size() - 1; i >= 0; --i) w1.push_back(num1[i] - '0');
    for (int i = num2.size() - 1; i >= 0; --i) w2.push_back(num2[i] - '0');

    // pad to power of 2 large enough to encode any i+j combo
    int n = 1;
    while (n < w1.size() + w2.size()) n <<= 1;
    w1.resize(n);
    w2.resize(n);

    fft(w1, false); fft(w2, false);  // FFT
    for (int i = 0; i < n; ++i) w1[i] *= w2[i];  // element-wise multiply
    fft(w1, true);  // inv FFT
    std::vector<int> prod;
    for (int i = 0; i < w1.size(); ++i) {
      prod.push_back(static_cast<int>(std::llround(w1[i].real())));
    }
    int carry = 0;
    for (int i = 0; i < prod.size(); ++i) {
      prod[i] += carry;
      carry = prod[i]/10;
      prod[i] %= 10;
    }
    while (prod.size() > 1 && prod.back() == 0) prod.pop_back();

    std::string res;
    for (int i = prod.size() - 1; i >= 0; --i) res.push_back('0' + prod[i]);

    return res;
  }
};


// approach v1: simulate 'human' multiplication (slow recursion)
// complexity: O(M*N*(M + N)) time, O(M + N) space, M := length num1, N := length num2
class SlowSolution {
 public:
  std::string add (const std::string& num1, const std::string& num2) {
    if (num1 == "0") return num2;
    if (num2 == "0") return num1;
    // assume non-negative, and that first is longest
    const int M = num1.size();
    const int N = num2.size();
    if (M < N) return add(num2, num1);

    std::vector<int> n1, n2, s;
    int carry = 0;
    for (int i = 0; i < M; ++i) n1.push_back(num1[i] - '0');
    for (int j = 0; j < N; ++j) n2.push_back(num2[j] - '0');

    int k = 0;
    for (; k < N; ++k) {
      int p = n1[M - 1 - k] + n2[N - 1 - k] + carry;
      s.push_back(p%10);
      carry = p/10;
    }
    for (; k < M; ++k) {
      int p = n1[M - 1 - k] + 0 + carry;
      s.push_back(p%10);
      carry = p/10;
    }
    if (carry) s.push_back(1);
    std::reverse(s.begin(), s.end());
    std::string res;
    for (int d : s) res += '0' + d;
    return res;

  }
  std::string multiply (const std::string& num1, const std::string& num2) {
    if (num1 == "0" || num2 == "0") return "0";
    if (num1 == "1") return num2;
    if (num2 == "1") return num1;

    const int M = num1.size();
    const int N = num2.size();

    if (M == 1 && N == 1) {  // single-digits base case
      return std::to_string(std::stoi(num1)*std::stoi(num2));
    }

    std::string res = "0";
    if (N == 1) {  // second number is single digit
      for (int i = 0; i < std::stoi(num2); ++i) res = add(res, num1);
      return res;
    }

    std::string base_num = "1";
    std::string base_den = "1";
    for (int i = M - 1; i >= 0; --i) {  // general case
      base_den = "1";
      std::string n1 = std::string(1, num1[i]);
      for (int j = N - 1; j >= 0; --j) {
        std::string n2 = std::string(1, num2[j]);
        res = add(res,
                  multiply(n1, n2)
                  + base_num.substr(1, base_num.size() - 1)
                  + base_den.substr(1, base_den.size() - 1) );
        base_den += "0";  // multiply(base_den, "10");
      }
      base_num += "0";  // multiply(base_num, "10");
    }
    return res;
  }
};
