//
// Created by admin on 2020/7/17.
//

#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

/*
 * 1. Straightforward method
 */
void QuickSort(vector<int> &nums, int start, int end) {
  if (start >= end) return;
  int pivot{nums[start]}, i{start}, j{end - 1};
  while (i < j) {
    while (j >= 0 && nums[j] > pivot) --j;
    if (i < j) nums[i++] = nums[j];
    while (i < j && nums[i] <= pivot) ++i;
    if (i < j) nums[j--] = nums[i];
  }
  nums[i] = pivot;
  QuickSort(nums, start, i);
  QuickSort(nums, i + 1, end);
}

/*
 * 2. With out define partition
 */

int Partition(vector<int> &nums, int l, int r) {
  int pivot = nums[l];
  int i = l + 1;
  for (int j = l + 1; j < r; ++j) {
    if (nums[j] < pivot) {
      swap(nums[j], nums[i]);
      ++i;
    }
  }
  swap(nums[l], nums[i - 1]);
  return i - 1;
}

int PartitionLast(vector<int> &nums, int l, int r) {
  swap(nums[l], nums[r - 1]);
  int pivot = nums[l];
  int i = l + 1;
  for (int j = l + 1; j < r; ++j) {
    if (nums[j] < pivot) {
      swap(nums[j], nums[i]);
      ++i;
    }
  }
  swap(nums[l], nums[i - 1]);
  return i - 1;
}

int PartitionMedianOfThree(vector<int> &nums, int l, int r) {
  int a = nums[l], b = nums[l + (r - l - 1) / 2], c = nums[r - 1];
  if ((a < b && b < c) || (c < b && b < a))
    swap(nums[l], nums[l + (r - l - 1) / 2]);
  else if ((a < c && c < b) || (b < c && c < a))
    swap(nums[l], nums[r - 1]);
  int pivot = nums[l];
  int i = l + 1;
  for (int j = l + 1; j < r; ++j) {
    if (nums[j] < pivot) {
      swap(nums[j], nums[i]);
      ++i;
    }
  }
  swap(nums[l], nums[i - 1]);
  return i - 1;
}
int res_count = 0;
void QuickSortV2(vector<int> &nums, int l, int r) {
  if (l >= r) return;
  res_count += r - l - 1;
//  int mid = Partition(nums, l, r);
//  int mid = PartitionLast(nums, l, r);
  int mid = PartitionMedianOfThree(nums, l, r);
  QuickSortV2(nums, l, mid);
  QuickSortV2(nums, mid + 1, r);
}

void LoadFromFile(const string &file_path, vector<int> &nums) {
  ifstream infile(file_path);
  int val;
  while (infile >> val) nums.push_back(val);
  infile.close();
}
int main() {
  vector<int> nums;
  LoadFromFile("../divide-conquer/QuickSort.txt", nums);
//  vector<int> nums{5, 2, 1, 4, 6, 7, 3};
  QuickSortV2(nums, 0, nums.size());
  cout << res_count << endl;
//  for (auto a:nums)
//    cout << a << ' ';
  return 0;
}

