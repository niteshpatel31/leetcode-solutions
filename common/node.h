template <typename T>
struct Node{
    public:
        T val;
        Node *next{nullptr};
        Node(T val):val(val), next(nullptr){}
};

template <typename T>
struct DoubleNode{
    public:
        T val;
        DoubleNode<T> *prev{nullptr};
        DoubleNode<T> *next{nullptr};
        DoubleNode(T val):val(val), next(nullptr), prev(nullptr){}
};
