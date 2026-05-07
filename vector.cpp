#include <iostream>

constexpr char endl = '\n';

// vector container
template <typename T> struct vector {
private:
  size_t v_size = 0uz;
  size_t v_capacity = 1uz;
  T *ptr;

  T &access(const size_t &idx) {
    if (idx == 0)
      return *this->ptr;
    else
      return *(this->ptr + (sizeof(*this->ptr) * (idx - 1)));
  }

public:
  vector() { return; }
  vector(const vector &v) { this = v; }
  ~vector() { delete ptr; }

  const size_t size() { return this->v_size - 1; }
  const size_t capacity() { return this->v_capacity; }
  void reserve(const int &size) {
    this->ptr = new T[size];
    this->v_capacity = size;
    return;
  }
  void push_back(const T &data) {
    this->access(this->v_size) = data;
    v_size++;
    return;
  }
  void emplace_back(const T &data) const {}

  T &operator[](const int &idx) const {
    if (idx == 0)
      return *this->ptr;
    else
      return *(this->ptr + (sizeof(*this->ptr) * (idx - 1)));
  }
};

int main(const int argc, const char *argv[]) {
  vector<char> v;
  v.reserve(45);
  v.push_back('A');
  v.push_back('B');
  v.push_back('C');
  std::cout << v[0] << endl;
  std::cout << v[1] << endl;
  std::cout << "size : " << v.size() << endl;
  std::cout << "capacity: " << v.capacity() << endl;
}
