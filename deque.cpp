#include <bits/stdc++.h>

class Node{
  public:
    int data;
    Node* next;
};

class Deque{
  public:
    Node* front;
    Node* rear;
    Node* createNode(int data);
    void push_front(int data);
    void push_back(int data);
    int pop_front();
    int length;
    int pop_back();
    int backValue();
    int frontValue();
    int size();
    void clear();
    void exit();
    Deque();
    ~Deque();
};

Deque::Deque(){
  front = rear = NULL;
  length = 0;
}

Node* Deque::createNode(int data){
  Node* node = new Node();
  node->data = data;
  node->next = NULL;
  return node;
}

Deque::~Deque(){
  clear();
}

void Deque::push_back(int data){
  if(front == NULL && rear == NULL){
    front = rear = createNode(data);
    length++;
    return;
  }
  Node* node = createNode(data);
  rear->next = node;
  rear = node;
  length++;
}

void Deque::push_front(int data){
  if(front == NULL && rear == NULL){
    front = rear = createNode(data);
    length++;
    return;
  }
  Node* node = createNode(data);
  node->next = front;
  front = node;
  length++;
}

int Deque::pop_back(){
  if(front == NULL){return INT_MIN;}

  if(front->next == NULL){
    int data = front->data;
    delete front;
    front = NULL;
    rear = NULL;
    length=0;
    return data;
  }

  Node* tmp = front;
  while(tmp->next != rear){
    tmp = tmp->next;
  }
  int data = rear->data;
  tmp->next = NULL;
  delete rear;
  rear = tmp;
  length--;
  return data;
}

int Deque::pop_front(){
  if(front == NULL){return INT_MIN;}

  if(front->next==NULL){
    int data = front->data;
    delete front;
    front = NULL;
    rear = NULL;
    length=0;
    return data;
  }

  Node* tmp = front;
  int data = front->data;
  front = front->next;
  delete tmp;
  length--;
  return data;
}

int Deque::frontValue(){
  if (front == NULL) return INT_MIN;
  int data = front->data;
  return data;
}

int Deque::backValue(){
  if (front == NULL) return INT_MIN;
  int data = rear->data;
  return data;
}

Node* removeNextNode(Node* node){
  if(node->next != NULL){
    node->next = removeNextNode(node->next);
  }
  delete node;
  return NULL;
}

void Deque::clear(){
  if(front == NULL){
    return;
  }
  front = removeNextNode(front);
  rear = NULL;
  length = 0;
}

int Deque::size(){
  return length;
}

int main(int argc, char *argv[])
{
  std::string str;
  Deque* deque = new Deque();
  while(std::cin >> str){
    if(str == "push_front"){
      int data;
      std::cin >> data;
      deque->push_front(data);
      std::cout << "ok" << std::endl;
    }
    else if(str == "push_back"){
      int data;
      std::cin >> data;
      deque->push_back(data);
      std::cout << "ok" << std::endl;
    }
    else if(str == "pop_front"){
      std::cout << deque->pop_front() << std::endl;
    }
    else if(str == "pop_back"){
      std::cout << deque->pop_back() << std::endl;
    }
    else if(str == "front"){
      std::cout << deque->frontValue() << std::endl;
    }
    else if(str == "back"){
      std::cout << deque->backValue() << std::endl;
    }
    else if(str == "size"){
      std::cout << deque->size() << std::endl;
    }
    else if(str == "clear"){
      deque->clear();
      std::cout << "ok" << std::endl;
    }
    else if(str == "exit"){
      std::cout << "bye" << std::endl;
      break;
    }
  }
  delete deque;
  return 0;
}
