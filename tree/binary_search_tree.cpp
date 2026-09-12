#include <iostream>

#define endl "\n";

struct Node {
  int data;
  // Node *prev{nullptr};
  Node *left{nullptr};
  Node *right{nullptr};
  Node() : data(0), left(nullptr), right(nullptr) {}
};

Node *insert(Node *root, int data) {
  if (root == nullptr) {
    Node *tmp = new Node();
    tmp->data = data;
    root = tmp;
    return root;
  }

  Node *temp = new Node();
  temp = root;
  while (true) {
    if (temp->data >= data) {
      if (temp->left == nullptr) {
        Node *tmp = new Node();
        tmp->data = data;
        temp->left = tmp;
        return tmp;
      }
      temp = temp->left;
    } else if (temp->data < data) {
      if (temp->right == nullptr) {
        Node *tmp = new Node();
        tmp->data = data;
        temp->right = tmp;
        return tmp;
      }
      temp = temp->right;
    } else {
    }
  }
  return temp;
}

Node *search(Node *root, int key) {
  if (root == nullptr)
    return nullptr;
  if (root->data == key)
    return root;

  Node *temp = new Node();
  temp = root;
  while (temp != nullptr) {
    if (temp->data == key)
      return temp;
    if (temp->data > key)
      temp = temp->left;
    else if (temp->data < key)
      temp = temp->right;
    else
      return nullptr;
  }
  return nullptr;
}

Node *root = new Node();

int main(int argc, char *argv[]) {
  Node *addr;
  addr = insert(root, 34);
  std::cout << addr << " : " << root << endl;
  std::cout << "data : " << addr->data << ", left : " << root->left
            << ", right : " << root->right << endl;
  addr = insert(root, 56);
  std::cout << addr << " : " << root << endl;
  std::cout << "data : " << addr->data << ", left : " << root->left
            << ", right : " << root->right << endl;
  addr = insert(root, 5);
  std::cout << addr << " : " << root << endl;
  std::cout << "data : " << addr->data << ", left : " << root->left
            << ", right : " << root->right << endl;
  addr = insert(root, 15);
  std::cout << addr << " : " << root << endl;
  std::cout << "data : " << addr->data << ", left : " << root->left
            << ", right : " << root->right << endl;
  std::cout << search(root, 15) << endl;
  return 0;
}
