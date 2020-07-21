//
// Created by admin on 2020/7/16.
//


#include <bits/stdc++.h>

using namespace std;

/*
 * 1. Straightforward divide-conquer method
 */
int helper(const vector<int> &nums, int start, int end) {
  int mid = start + (end - start) / 2;
  int count = 0;
  for (int i = start; i < mid; ++i) {
    for (int j = mid; j < end; ++j)
      if (nums[i] > nums[j]) ++count;
  }
  return count;
}

size_t CountInversions(const vector<int> &nums, int start, int end) {
  if (start + 1 >= end) return 0;
  int mid = start + (end - start) / 2;
  size_t x = CountInversions(nums, start, mid);
  size_t y = CountInversions(nums, mid, end);
  size_t z = helper(nums, start, end);
  return x + y + z;
}

/*
 * 2. Fast divide-conquer method
 */
int FastCountSplitInversions(vector<int> &nums, int start, int end) {
  int mid = start + (end - start) / 2;
  int i = start, j = mid, k = 0, count = 0;
  vector<int> temp(end - start);
  while (i < mid && j < end) {
    if (nums[i] <= nums[j]) {
      temp[k++] = nums[i++];
    } else {
      temp[k++] = nums[j++];
      count += mid - i;
    }
  }
  if (i != mid) {
    for (; i < mid; ++i)
      temp[k++] = nums[i];
  }
  if (j != end) {
    for (; j < end; ++j)
      temp[k++] = nums[j];
  }

  copy(temp.begin(), temp.end(), nums.begin() + start);
  return count;
}

size_t FastCountInversions(vector<int> &nums, int start, int end) {
  if (start + 1 >= end) return 0;
  int mid = start + (end - start) / 2;
  size_t x = FastCountInversions(nums, start, mid);
  size_t y = FastCountInversions(nums, mid, end);
  size_t z = FastCountSplitInversions(nums, start, end);

  return x + y + z;
}

void LoadFromFile(const string &file_path, vector<int> &nums) {
  ifstream infile(file_path);
  int val;
  while (infile >> val) nums.push_back(val);
  infile.close();
}
int main() {
  vector<int> nums;
  LoadFromFile("../divide-conquer/IntegerArray.txt", nums);
//  vector<int> nums{7, 6, 5, 4, 3, 2, 1};
//  cout << CountInversions(nums, 0, nums.size()) << endl;
  cout << FastCountInversions(nums, 0, nums.size()) << endl;
  return 0;
}
