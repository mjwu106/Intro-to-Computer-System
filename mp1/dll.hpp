namespace LinkedList {

#ifndef NULL
#define NULL ((void*)0)
#endif

template <typename T> class List;

template <typename T> class Node {
  T data;
  Node* next;
  Node* prev;
public:
  void detach() {
    if (prev) prev->next = next;
    if (next) next->prev = prev;
    prev = next = NULL;
  }
  friend List<T>;
};

template <typename T> class List {
  Node<T>* head;
  Node<T>* tail;
public:
  List() { head = tail = NULL; }
  List(T& value) { head = tail = new Node<T>(); head->data = value; }
  ~List() { while(head) this->pop(T()); }
  Node<T>* find(const T value) const {
    Node<T>* cursor = head;
    while(cursor) {
      if (cursor->data == value) return cursor;
      cursor = cursor->next;
    }
    return NULL;
  }
  T pop(T ifEmpty) {
    if (!head) return ifEmpty;
    Node<T>* tmp = head;
    head = tmp->next;
    if (!tmp->next) head = tail = NULL;
    tmp->detach();
    T ans = tmp->data;
    delete tmp;
    return ans;
  }
  T shift(T ifEmpty) {
    if (!tail) return ifEmpty;
    Node<T>* tmp = tail;
    if (!tmp->prev) head = tail = NULL;
    tail = tmp->prev;
    tmp->detach();
    T ans = tmp->data;
    delete tmp;
    return ans;
  }
  void push(T value) {
    Node<T>* tmp = new Node<T>();
    tmp->data = value;
    tmp->next = head;
    tmp->prev = NULL;
    if (head) head->prev = tmp;
    head = tmp;
    if (!tail) tail = head;
  }
  void enqueue(T value) {
    Node<T>* tmp = new Node<T>();
    tmp->data = value;
    tmp->prev = tail;
    tmp->next = NULL;
    if (tail) tail->next = tmp;
    tail = tmp;
    if (!head) head = tail;
  }
};



}
