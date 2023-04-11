#include <bits/stdc++.h>
#include <string>
using namespace std;

class Node {
  public:
    int data;
    Node * next;
    Node(int data) { this->data = data; }
};

class Stack {
  Node* head;
  public:
    Stack();

    void push(int data){
      Node* tmp = head;
      while (tmp->next) 
        tmp = tmp->next;
      Node * newnode = new Node(data);
      tmp->next = newnode;
    };

    void clear(){
      while (head) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
      }
    }

    int size(){
      Node* tmp = head;
      int size = 0;
      while (tmp) {
        size++;
        tmp = tmp->next;
      }
      return size;
    }

    void pop(){
      Node* tmp = head;
      if (!head->next) 
        head = nullptr;
      while (tmp->next->next)
        tmp = tmp->next;
      std::cout << tmp->next->data << std::endl;
      tmp->next = nullptr; 
    };

    Node* back(){
      Node* tmp = head;
      while (tmp->next)
        tmp = tmp->next;
      cout << tmp->data;
      return tmp;
    };
    ~Stack() {
      clear();
    };
};

int main(int argc, char *argv[]) {
  string line;

  while (getline(cin, line)) {
    if (line == "exit") 
      std::cout << "bye" << std::endl;
    if (line == "push") 
      std::cout << "bye" << std::endl;
  }
  return 0; 
}
