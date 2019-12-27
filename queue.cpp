#include <bits/stdc++.h>

class Node{
  public:
    int data;
    Node* next;
    Node();
};
Node::Node(){
  next = NULL;
}

class Queue{
  public:
    Node* front;
    Node* back;
    void push(int data);
    ~Queue();
    Queue();
    int pop();
    int length;
    int frontValue();
    int backValue();
    int size();
    void clear();
    Node* createNode(int data);
};

Queue::Queue(){
  front = NULL;
  back = NULL;
  length = 0;
}

Queue::~Queue(){
  clear();
}

Node* Queue::createNode(int data){
  Node* node = new Node();
  node->data = data;
  node->next = NULL;
  return node;
}

void Queue::push(int data){
  length++;
  if(back==NULL){
    front = back = createNode(data);
    return;
  }
  Node* node = createNode(data);
  this->back->next = node;
  this->back = node;
}

int Queue::pop(){
  length--;
  if(front==NULL)return INT_MIN;
  int value = front->data;
  Node* tmp = front;
  front = front->next;
  if(front==NULL) back=NULL;
  delete tmp;
  return value;
}

int Queue::frontValue(){
  if(front==NULL)return INT_MIN;
  return front->data;
}

int Queue::backValue(){
  if(back==NULL)return INT_MIN;
  return back->data;
}

int Queue::size(){
  return this->length;
}

Node* deleteNext(Node* node){
  if(node->next != NULL){
    node->next = deleteNext(node->next);
  }
  delete node;
  return NULL;
}

void Queue::clear(){
  if (this->front == NULL){return; }
  this->front = deleteNext(this->front);
  this->back = NULL;
  this->length=0;
}



int main(int argc, char *argv[])
{
  Queue* queue = new Queue();
  std::string str;
  while(std::cin>>str){
    if(str == "push"){
      int data;
      std::cin >> data;
      queue->push(data);
      std::cout << "ok" << std::endl;
    }
    else if(str == "pop"){
      std::cout << queue->pop() << std::endl;
    }
    else if (str == "front"){
      std::cout << queue->frontValue() << std::endl;
    }
    else if (str == "back"){
      std::cout << queue->backValue() << std::endl;
    }
    else if (str == "size"){
      std::cout << queue->size() << std::endl;
    }
    else if (str == "clear"){
      queue->clear();
      std::cout << "ok" << std::endl;
    }
    else if (str == "exit"){
      std::cout << "bye" << std::endl;
      break;
    }
  }
  delete queue;
  return 0;
}
