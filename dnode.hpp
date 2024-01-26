#include <iostream>

template<class T>
class DNode {

  public:
    T val;
    DNode* next;
    DNode* prev;

    DNode(T value) {
      val = value;
      initialize();
    }

    void initialize() {
      next = this;
      prev = this;
    }

    bool isUnitarian() {
      return next == this && prev == this;
    }

    void insertNext(DNode* node) {
      if (!node->isUnitarian()) node->remove();

      node->next = next;
      node->prev = this;
      next->prev = node;
      next = node;
    }

    void insertPrev(DNode* node) {
      if (!node->isUnitarian()) node->remove();

      node->prev = prev;
      node->next = this;
      prev->next = node;
      prev = node;
    }

    void printList() {
      DNode* current = this;

      std::cout << "[ ";
      do {
        std::string conector = current->next == this ? "" : ", ";
        std::cout << current->val << conector;
        current = current->next;
      } while (current != this);
      std::cout << " ]" << std::endl;
    }

    void printNodeDetails() {
      std::cout << "Node value: " << val << std::endl;
      std::cout << "Next: " << next << std::endl;
      std::cout << "Next value: " << next->val << std::endl;
      std::cout << "Prev: " << prev << std::endl;
      std::cout << "Prev value: " << prev->val << std::endl;
    }

    DNode* remove() {
      prev->next = next;
      next->prev = prev;
      initialize();
      return this;
    }

    DNode* removeNext() {
      return next->remove();
    }

    DNode* removePrev() {
      return prev->remove();
    }

    void swap(DNode* head) {
      head->prev->next = this;
      prev->next = head;
      head->next->prev = this;
      next->prev = head;

      DNode* temp = prev;
      prev = head->prev;
      head->prev = temp;

      temp = next;
      next = head->next;
      head->next = temp;
    }

    void concat(DNode* head) {
      head->prev->next = this;
      prev->next = head;
      DNode* temp = prev;
      prev = head->prev;
      head->prev = temp;
    }

    std::pair<DNode*, DNode*> split() {
      if (isUnitarian()) return std::make_pair(this, this);
      
      DNode* current = this->next;
      DNode* right = removePrev();
      DNode* left = remove();
      
      while(!current->isUnitarian()) {
        right->insertNext(current->removePrev());
        if (!current->isUnitarian()) {
          DNode* temp = current->next;
          left->insertPrev(current->remove());
          current = temp;
        }
      }
      left->insertPrev(current);
      return std::make_pair(left, right->next);
    }
};