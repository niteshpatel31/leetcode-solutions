#include "../common/linked_list.cpp"
#include <bits/stdc++.h>
#include <cinttypes>

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *&head, int n) const noexcept {
    ListNode *dummy{new ListNode(0, head)}, *a{dummy}, *b{dummy};

    while (b->next) {
      if (!n) [[likely]]
        a = a->next;
      else
        --n;
      b = b->next;
    }

    if (!a->next)
      a = nullptr;
    else
      a->next = a->next->next;
    return dummy->next;

    // if (!head)
    //   return nullptr;
    // int cnt{};

    // while (ptr) {
    //   ptr = ptr->next;
    //   ++cnt;
    // }
    // cnt -= n;
    // if (cnt == 0) {
    //   fmt::println("cnt : {0}, ptr : {1}", cnt, n);
    //   return head->next;
    // }
    // ptr = head;
    // while (--cnt)
    //   ptr = ptr->next;

    // if (ptr->next)
    //   ptr->next = ptr->next->next;
    // else
    //   ptr->next = nullptr;
    // return head;
  }
};

int main() {
  Solution sl;
  const std::vector<int> v1{1, 2, 3, 4, 5}, v2{1, 2, 3}, v3{1, 2};
  ListNode *l1{nullptr}, *l2{nullptr}, *l3{nullptr};

  makeList(l1, v1);
  makeList(l2, v2);
  makeList(l3, v3);

  printList(sl.removeNthFromEnd(l1, 2));
  printList(sl.removeNthFromEnd(l2, 3));
  printList(sl.removeNthFromEnd(l3, 2));

  freeList(l1);
  freeList(l2);
  freeList(l3);
  return EXIT_SUCCESS;
}
