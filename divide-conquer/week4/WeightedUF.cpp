//
// Created by Lei Chen on 2020/7/21.
//

#include "WeightedUF.h"

#include <algorithm>

WeightedUF::WeightedUF(int N) : sz(N + 1, 1), count(N) {
  for (int i = 0; i <= N; ++i) id.push_back(i);
}

int WeightedUF::getCount() const { return count; }

bool WeightedUF::connected(int p, int q) { return find(p) == find(q); }

int WeightedUF::find(int p) {
  while (p != id[p]) p = id[p];
  return p;
}

void WeightedUF::wfUnion(int p, int q) {
  int i = find(p);
  int j = find(q);

  if (i == j) return;

  // make smaller root point to larger one
  if (sz[i] < sz[j]) {
    id[i] = j;
    sz[j] += sz[i];
  } else {
    id[j] = i;
    sz[i] += sz[j];
  }
  --count;
}

int WeightedUF::getMax() { return *std::max_element(sz.begin(), sz.end()); }
