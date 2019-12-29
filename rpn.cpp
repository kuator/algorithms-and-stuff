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
  char input;
  Stack* stack = new Stack();
  std::string str;
  getline(std::cin, str);
  std::istringstream iss(str);
  // The input is supposed to be spaced delimited characters;
  // 8 9 + 1 7 - *
  while(iss >> input){
    if(isdigit(input)){
      int number = input - 48;
      stack->push(number);
    } else{
      int second = stack->pop();
      int first = stack->pop();
      if(input == '*'){
        stack->push(first*second);
      }
      else if(input == '-'){
        stack->push(first-second);
      }
      else if(input == '+'){
        stack->push(first+second);
      }
      else if(input == '/'){
        stack->push(first/second);
      }
    }
  }
  int result = stack->pop();
  std::cout << result << std::endl;
  delete stack;
  return 0;
}
