// 2095. Delete the Middle Node of a Linked List
#include "../common/linked_list.cpp"
#include <cstdlib>
#include <fmt/base.h>

class Solution {
public:
  ListNode *deleteMiddle(ListNode *head) const noexcept {
    ListNode *ptr{head}, *prev{head};
    int cnt{};

    while (ptr) {
      ptr = ptr->next;
      ++cnt;
    }

    if (cnt == 1)
      return nullptr;
    cnt /= 2;
    ++cnt;

    ptr = head;

    while (--cnt) {
      prev = ptr;
      ptr = ptr->next;
    }

    prev->next = ptr->next;
    delete ptr;
    return head;
  }
};

int main() {
  ListNode *l1{nullptr}, *l2{nullptr}, *l3{nullptr};
  const std::vector<int> v1{1, 3, 4, 7, 1, 2, 6}, v2{1, 2, 3, 4}, v3{2, 1};

  makeList(l1, v1);
  makeList(l2, v2);
  makeList(l3, v3);

  Solution sl;
  printList(sl.deleteMiddle(l1));
  printList(sl.deleteMiddle(l2));
  printList(sl.deleteMiddle(l3));

  freeList(l1);
  freeList(l2);
  freeList(l3);
  return EXIT_SUCCESS;
}
