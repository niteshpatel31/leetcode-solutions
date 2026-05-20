/*
  Product of Array Except Self
  Given an integer array nums, return an array answer such that answer[i] is
equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
integer.

You must write an algorithm that runs in O(n) time and without using the
division operation.

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

Constraints:

    2 <= nums.length <= 105
    -30 <= nums[i] <= 30
    The input is generated such that answer[i] is guaranteed to fit in a 32-bit
integer.

Follow up: Can you solve the problem in O(1) extra space complexity? (The output
array does not count as extra space for space complexity analysis.)
*/
#include <cstdlib>
#include <fmt/format.h>
#include <vector>

void print(const std::vector<int> &vec) {
  fmt::print("vec : [");
  for (auto &e : vec)
    fmt::print("{}, ", e);
  fmt::println("]");
}

class Solution {
public:
  // prefix and suffix
  std::vector<int> productExceptSelf1(std::vector<int> &nums) {
    size_t size{nums.size()};
    std::vector<int> prefix(size, 1), suffix(size, 1);
    for (size_t i = 1; i < size; i++)
      prefix[i] = prefix[i - 1] * nums[i - 1];
    for (int64_t i = size - 2; i >= 0; i--)
      suffix[i] = suffix[i + 1] * nums[i + 1];
    for (size_t i = 0; i < size; i++)
      nums[i] = prefix[i] * suffix[i];
    return nums;
  }

  std::vector<int> productExceptSelf(std::vector<int> &nums) {
    int n = nums.size();
    std::vector<int> output(n);
    output[0] = 1;
    for (int i = 1; i < n; i++) {
      output[i] = output[i - 1] * nums[i - 1];
    }
    int right = 1;
    for (int i = n - 1; i >= 0; i--) {
      output[i] *= right;
      right *= nums[i];
    }
    return output;
  }
};

int main(int argc, const char *argv[]) {
  std::vector<int> v1 = {-1, 1, 0, -3, 3};
  std::vector<int> v2 = {1, 2, 3, 4};
  std::vector<int> v3 = {-9, 9, 0, -3, 3, 0};
  Solution sol;
  print(sol.productExceptSelf(v2));
  print(sol.productExceptSelf(v1));
  print(sol.productExceptSelf(v3));
  return EXIT_SUCCESS;
}
