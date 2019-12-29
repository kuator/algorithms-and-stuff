#include <bits/stdc++.h>

class Node {
  public:
    char data; 
    Node* next;
};

class Stack {
  public:
    Node* root;
    void push(char data);
    ~Stack();
    char pop();
    char back();
    int size();
    bool isEmpty();
    Node* createNode(char data);
    void clear();
};

Stack::~Stack(){
  clear();
}

bool Stack::isEmpty(){
  return !root;
}

Node* Stack::createNode(char data){
  Node* node = new Node();
  node->data = data;
  return node;
}

void Stack::push(char data){
    Node* node = createNode(data);
    Node** root = &this->root;
    node->next = *root;
    *root = node;
}

char Stack::pop(){
  if (isEmpty()) throw std::string("error");
  Node* tmp = this->root;
  Node** root = &this->root;
  *root = this->root->next; 
  char value = tmp->data;
  delete tmp;
  return value;
}

char Stack::back(){
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
  std::cin >> str;
  Stack* stack = new Stack();
  stack->root = NULL;
  for(char& c : str) {
    if(c == '(' || c == '[' || c == '{'){
      stack->push(c);
    }
    else if(c == ')' || c == ']' || c== '}'){
      if(stack->root == NULL){
        std::cout << "no" << std::endl;
        delete stack;
        return 0;
      }

      char a = stack->pop();
      if((c == ')' && a != '(') || (c == ']' && a != '[') || (c == '}' && a != '{')){
        std::cout << "no" << std::endl;
        delete stack;
        return 0;
      }
    }
  }

  if(stack->root != NULL)
    std::cout << "no" << std::endl;

  std::cout << "yes" << std::endl;
  delete stack;
  return 0;
}
