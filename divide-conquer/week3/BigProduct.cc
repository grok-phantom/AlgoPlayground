//
// Created by admin on 2020/7/16.
//

#include <bits/stdc++.h>

using namespace std;

/*
 * 1. Straightforward method
 */
string helper(const string &a, char c, int i) {
  string r(i, '0');
  int m = 0, base = c - '0';
  int len_a = a.size();
  for (auto j = len_a - 1; j >= 0; --j) {
    int b = a[j] - '0';
    int mul = b * base + m;
    m = mul / 10;
    r += to_string(mul % 10);
  }
  if (m) r += to_string(m);
  return r;
}

string BigReverseSum(const string &a, const string &b) {
  string r;
  int m = 0;
  size_t i = 0, j = 0;
  while (i < a.size() && j < b.size()) {
    int sum = (a[i] - '0') + (b[j] - '0') + m;
    m = sum / 10;
    r += to_string(sum % 10);
    ++i, ++j;
  }
  if (i != a.size()) {
    for (; i < a.size(); ++i) {
      int sum = (a[i] - '0') + m;
      m = sum / 10;
      r += to_string(sum % 10);
    }
  }
  if (j != b.size()) {
    for (; j < b.size(); ++j) {
      int sum = (b[j] - '0') + m;
      m = sum / 10;
      r += to_string(sum % 10);
    }
  }
  if (m) r += to_string(m);
  return r;
}

string BigProduct(const string &a, const string &b) {
  int len_b = b.size();
  string r;
  for (auto i = len_b - 1; i >= 0; --i) {
    auto cur_str = helper(a, b[i], len_b - 1 - i);
    if (r.empty()) r = cur_str;
    else r = BigReverseSum(r, cur_str);
  }
  reverse(r.begin(), r.end());
  return r;
}

/*
 * 2. Recursive algorithm
 * x = 10^(n/2)*a + b, y = 10^(n/2)*c + d
 * x * y = 10^n*ac + 10^(n/2)*(ad+bc) + bd
 * T(n) = 4T(n/2) + O(n)
 */

string BigProductRecursive(const string &x_, const string &y_) {
  int len_x = x_.size(), len_y = y_.size();
  string x, y;
  if (len_x < len_y) {
    x = string(len_y - len_x, '0') + x_;
    y = y_;
    len_x = len_y;
  } else {
    x = x_;
    y = string(len_x - len_y, '0') + y_;
    len_y = len_x;
  }
  if (len_x == 0) return "";
  else if (len_x < 20) return to_string(stoi(x) * stoi(y));
  int half_n = len_x / 2;
  auto a = x.substr(half_n);
  auto b = x.substr(0, half_n);
  auto c = y.substr(half_n);
  auto d = y.substr(0, half_n);
  return BigProductRecursive(a, c) + string(len_x, '0'); // Need to implement Big Sum
}

/*
 * 3. A better recursive algorithm
 * ad+bc = (a+b)(c+d) - ac - bd
 * T(n) = 3T(n/2) + O(n)
 */

int main() {
  string a{"3141592653589793238462643383279502884197169399375105820974944592"};
  string b{"2718281828459045235360287471352662497757247093699959574966967627"};
  cout << BigProduct(a, b) << endl;
  return 0;
}