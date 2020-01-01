#include <bits/stdc++.h>

class Node {
  public:
    int data; 
    Node* next;
};

class Stack {
  public:
    Node* root;
    void push(int data);
    ~Stack();
    int pop();
    int back();
    int size();
    bool isEmpty();
    Node* createNode(int data);
    void clear();
};

Stack::~Stack(){
  clear();
}

bool Stack::isEmpty(){
  return !root;
}

Node* Stack::createNode(int data){
  Node* node = new Node();
  node->data = data;
  return node;
}

void Stack::push(int data){
    Node* node = createNode(data);
    Node** root = &this->root;
    node->next = *root;
    *root = node;
}

int Stack::pop(){
  if (isEmpty()) throw std::string("error");
  Node* tmp = this->root;
  Node** root = &this->root;
  *root = this->root->next; 
  int value = tmp->data;
  delete tmp;
  return value;
}

int Stack::back(){
  if (isEmpty()) throw std::string("error");
  return root->data;
}

Node* clearNext(Node* node){
  if(node->next != NULL){
    node->next = clearNext(node->next);
  }
  delete node;
  return NULL;
}

int Stack::size(){
  Node* temp = this->root;
  int size = 0;
  while(temp != NULL){
    size++;
    temp = temp->next;
  }
  return size;
}

void Stack::clear(){
  if(this->root != NULL){
    this->root = clearNext(this->root);
  }
}

int main(int argc, char *argv[])
{
  std::string str;
  Stack* stack = new Stack();
  stack->root = NULL;
  while(std::cin >>str){
    if(str == "push"){
      int data;
      std::cin >> data;
      stack->push(data);
      std::cout << "ok" << std::endl;
    }
    else if (str == "pop"){
      try {
        std::cout << stack->pop() << std::endl;
      }catch(std::string& error) {
        std::cout << "error" << std::endl;
      }
    }
    else if (str == "back"){
      try {
        std::cout << stack->back() << std::endl;
      }catch(std::string& error) {
        std::cout << "error" << std::endl;
      }
    }
    else if (str == "clear"){
      stack->clear();
      std::cout << "ok" << std::endl;
    }
    else if (str == "size"){
      std::cout << stack->size() << std::endl;
    }
    else if (str == "exit"){
      std::cout << "bye" << std::endl;
      break;
    }
  }
  delete stack;
  return 0;
}
