#pragma GCC optimize("Ofast,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,fma,sse4,popcnt,lzcnt,bmi,bmi2")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

static constexpr size_t mxal = alignof(max_align_t);
alignas(mxal) static unsigned char buf[256 * 1024 * 1024];
static size_t pos = 0;

void *operator new(size_t sz) {
  size_t pad = (mxal - (pos % mxal)) % mxal;
  pos += pad + sz;
  return (void *)(&buf[pos - sz]);
}

void *operator new[](size_t sz) { return operator new(sz); }

void operator delete(void *) noexcept {}
void operator delete[](void *) noexcept {}
void operator delete(void *, size_t) noexcept {}
void operator delete[](void *, size_t) noexcept {}

inline bool isDigit(const char c) { return (c >= '0') && (c <= '9'); }

void parse_and_solve(const string &s1, const string &s2, ofstream &out) {
  int S1 = s1.size(), S2 = s2.size();
  if (S1 < S2) {
    parse_and_solve(s2, s1, out);
    return;
  }
  int carry = 0, i = 0, j = 0;
  while (i < S1 - 1) {
    while (i < S1 && !isDigit(s1[i]))
      ++i;
    while (j < S2 && !isDigit(s2[j]))
      ++j;
    int n1 = s1[i] - '0';
    int n2 = (j < S2) ? (s2[j] - '0') : 0;
    int n = carry + n1 + n2;
    carry = n / 10;
    out << (n % 10);
    if (i < S1 - 2)
      out << ",";
    ++i;
    ++j;
  }
  if (carry > 0)
    out << "," << carry;
}

static bool Solve = []() {
  ofstream out("user.out");
  string s1, s2;
  while (getline(cin, s1) && getline(cin, s2)) {
    out << "[";
    parse_and_solve(s1, s2, out);
    out << "]\n";
  }
  out.flush();
  exit(0);
  return true;
}();

int speedUp = [] {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();
