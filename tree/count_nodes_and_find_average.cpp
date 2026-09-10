#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
  std::pair<long, long> solve(long &count, TreeNode *node) {
    if (!node)
      return {0, 0};
    auto left{solve(count, node->left)}, right{solve(count, node->right)};

    long sum{left.first + right.first + node->val};
    long cnt{left.second + right.second + 1};
    if (sum / cnt == node->val)
      ++count;
    return {sum, cnt};
  }

public:
  int averageOfSubtree(TreeNode *root) {
    long count{};
    solve(count, root);
    return count;
  }
};

// Helper to build a binary tree from level-order representation.
// -1 represents nullptr.
TreeNode *buildTree(const vector<int> &nodes) {
  if (nodes.empty() || nodes[0] == -1)
    return nullptr;

  TreeNode *root = new TreeNode(nodes[0]);
  queue<TreeNode *> q;
  q.push(root);

  int i = 1;

  while (!q.empty() && i < (int)nodes.size()) {
    TreeNode *cur = q.front();
    q.pop();

    if (i < (int)nodes.size() && nodes[i] != -1) {
      cur->left = new TreeNode(nodes[i]);
      q.push(cur->left);
    }
    i++;

    if (i < (int)nodes.size() && nodes[i] != -1) {
      cur->right = new TreeNode(nodes[i]);
      q.push(cur->right);
    }
    i++;
  }

  return root;
}

// Optional cleanup helper
void deleteTree(TreeNode *root) {
  if (!root)
    return;

  deleteTree(root->left);
  deleteTree(root->right);
  delete root;
}

int main() {
  Solution sol;
  // Test Case 0
  // Expected: 6
  {
    TreeNode *root = buildTree({6, 4, 8, 2, 5, 7, 10, 1, 3});
    int expected = 6;
    int actual = sol.averageOfSubtree(root);

    cout << "Test 0: " << (actual == expected ? "PASSED" : "FAILED")
         << " | Expected: " << expected << " | Actual: " << actual << '\n';

    deleteTree(root);
  }

  // Test Case 1
  // Expected: 5
  {
    TreeNode *root = buildTree({4, 8, 5, 0, 1, -1, 6});
    int expected = 5;
    int actual = sol.averageOfSubtree(root);

    cout << "Test 1: " << (actual == expected ? "PASSED" : "FAILED")
         << " | Expected: " << expected << " | Actual: " << actual << '\n';

    deleteTree(root);
  }

  // Test Case 2
  // Expected: 1
  {
    TreeNode *root = buildTree({1});
    int expected = 1;
    int actual = sol.averageOfSubtree(root);

    cout << "Test 2: " << (actual == expected ? "PASSED" : "FAILED")
         << " | Expected: " << expected << " | Actual: " << actual << '\n';

    deleteTree(root);
  }

  // Test Case 3
  // Expected: 3
  {
    TreeNode *root = buildTree({2, 3, 4});
    int expected = 3;
    int actual = sol.averageOfSubtree(root);

    cout << "Test 3: " << (actual == expected ? "PASSED" : "FAILED")
         << " | Expected: " << expected << " | Actual: " << actual << '\n';

    deleteTree(root);
  }

  // Test Case 4
  // Expected: 7
  {
    TreeNode *root = buildTree({5, 6, 7, 8, 9, 10, 11});
    int expected = 7;
    int actual = sol.averageOfSubtree(root);

    cout << "Test 4: " << (actual == expected ? "PASSED" : "FAILED")
         << " | Expected: " << expected << " | Actual: " << actual << '\n';

    deleteTree(root);
  }

  // Test Case 5
  // Expected: 7
  {
    TreeNode *root = buildTree({7, 7, 7, 7, 7, 7, 7});
    int expected = 7;
    int actual = sol.averageOfSubtree(root);

    cout << "Test 5: " << (actual == expected ? "PASSED" : "FAILED")
         << " | Expected: " << expected << " | Actual: " << actual << '\n';

    deleteTree(root);
  }

  // Test Case 6
  // Expected: 3
  {
    TreeNode *root = buildTree({3, 0, 0, 0, 0});
    int expected = 3;
    int actual = sol.averageOfSubtree(root);

    cout << "Test 6: " << (actual == expected ? "PASSED" : "FAILED")
         << " | Expected: " << expected << " | Actual: " << actual << '\n';

    deleteTree(root);
  }

  // Test Case 7
  // Expected: 4
  {
    TreeNode *root = buildTree({4, 2, 6, 1, 3, 5, 7});
    int expected = 4;
    int actual = sol.averageOfSubtree(root);

    cout << "Test 7: " << (actual == expected ? "PASSED" : "FAILED")
         << " | Expected: " << expected << " | Actual: " << actual << '\n';

    deleteTree(root);
  }

  // Test Case 8
  // Expected: 5
  {
    TreeNode *root = buildTree({10, 5, 15, -1, 7, -1, 20});
    int expected = 5;
    int actual = sol.averageOfSubtree(root);

    cout << "Test 8: " << (actual == expected ? "PASSED" : "FAILED")
         << " | Expected: " << expected << " | Actual: " << actual << '\n';

    deleteTree(root);
  }

  // Test Case 9
  // Expected: 1
  {
    TreeNode *root = buildTree({1, 0, 2, 0, 0, 2, 2});
    int expected = 1;
    int actual = sol.averageOfSubtree(root);

    cout << "Test 9: " << (actual == expected ? "PASSED" : "FAILED")
         << " | Expected: " << expected << " | Actual: " << actual << '\n';

    deleteTree(root);
  }

  return 0;
}
