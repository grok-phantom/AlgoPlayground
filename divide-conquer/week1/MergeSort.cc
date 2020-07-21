//
// Created by admin on 2020/7/16.
//

#include <bits/stdc++.h>

using namespace std;

void helper(int start, int end, vector<int> &nums) {
  if (start + 1 == end) return;
  int mid = start + (end - start) / 2;
  helper(start, mid, nums);
  helper(mid, end, nums);
  vector<int> tmp(end - start);
  int i = start, j = mid, k = 0;
  while (i < mid && j < end) {
    if (nums[i] < nums[j]) {
      tmp[k++] = nums[i++];
    } else {
      tmp[k++] = nums[j++];
    }
  }
  if (i != mid) {
    while (i < mid)
      tmp[k++] = nums[i++];
  }
  if (j != end) {
    while (j < end)
      tmp[k++] = nums[j++];
  }
  copy(tmp.begin(), tmp.end(), nums.begin() + start);
}

void MergeSort(vector<int> &nums) {
  int start = 0, end = nums.size();
  helper(start, end, nums);
}

int main() {
  vector<int> nums{2, 4, 1, 6, 4, 7};
  MergeSort(nums);
  for (auto num:nums)
    cout << num << ' ';
  return 0;
}
