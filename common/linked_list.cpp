#pragma once

#include <bits/stdc++.h>
#include <fmt/format.h>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void makeList(ListNode *&head, const std::vector<int> &v) {
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
