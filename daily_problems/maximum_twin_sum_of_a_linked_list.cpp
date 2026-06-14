#include <bits/stdc++.h>
#include <cstdlib>
#include <fmt/base.h>
#include <fmt/format.h>
#include <queue>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void makeList(ListNode *&head, std::vector<int> v) {
  ListNode *crt{nullptr};
  for (const int x : v) {
    ListNode *node = new ListNode(x);
    if (!head) {
      head = node;
      crt = head;
    } else {
      crt->next = node;
      crt = crt->next;
    }
  }
  return;
}

void freeList(ListNode *head) {
  while (head) {
    ListNode *tmp = head;
    head = head->next;
    delete tmp;
  }
}

void printList(ListNode *head) {
  ListNode *crt{head};
  while (crt) {
    fmt::print("{} -> ", crt->val);
    crt = crt->next;
  }
  fmt::println("");
  return;
}

static std::vector<int> v(100000, 0);

class Solution {
public:
  int pairSum(ListNode *head) const noexcept {
    int max{0};
    v.clear();
    while (head) {
      v.emplace_back(head->val);
      head = head->next;
    }
    const size_t size{v.size()};
    for (size_t i{size}; i > size / 2; --i)
      max = std::max(max, v[i - 1] + v[size - i ]);
    return max;
  }
};

int main() {
  Solution sl;
  const std::vector<int> v1{5, 4, 2, 1}, v2{4, 2, 2, 3}, v3{1, 100000},
      v4{47, 22, 81, 46, 94, 95, 90, 22, 55, 91, 6,  83, 49, 65, 10, 32, 41,
         26, 83, 99, 14, 85, 42, 99, 89, 69, 30, 92, 32, 74, 9,  81, 5,  9},
      v5{7,  57, 13, 31, 17, 65, 32, 3,  97, 22, 7,  20, 69,
         35, 69, 75, 13, 33, 50, 80, 64, 71, 15, 28, 2,  27,
         39, 48, 13, 22, 84, 5,  51, 46, 26, 78, 56, 63};
  ListNode *l1{nullptr}, *l2{nullptr}, *l3{nullptr}, *l4{nullptr}, *l5{nullptr};
  makeList(l1, v1);
  makeList(l2, v2);
  makeList(l3, v3);
  makeList(l4, v4);
  makeList(l5, v5);
  // printList(l1);
  // printList(l2);
  // printList(l3);
  // printList(l4);
  // printList(l5);

  fmt::println("ans : {}", sl.pairSum(l1));
  fmt::println("ans : {}", sl.pairSum(l2));
  fmt::println("ans : {}", sl.pairSum(l3));
  fmt::println("ans : {}", sl.pairSum(l4));
  fmt::println("ans : {}", sl.pairSum(l5));

  freeList(l1);
  freeList(l2);
  freeList(l3);
  freeList(l4);
  freeList(l5);
  return EXIT_SUCCESS;
}
