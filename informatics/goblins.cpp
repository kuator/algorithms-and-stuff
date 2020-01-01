#include <bits/stdc++.h>

class Node{
  public:
    int data;
    Node* next;
    Node* prev;
    Node();
};
Node::Node(){
  next = NULL;
  prev = NULL;
}

class Queue{
  public:
    Node* front;
    Node* back;
    Node* middle;
    void push(int data,char type);
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
  middle = NULL;
  length = 0;
}

Queue::~Queue(){
  clear();
}

Node* Queue::createNode(int data){
  Node* node = new Node();
  node->data = data;
  node->next = NULL;
  node->prev = NULL;
  return node;
}

void Queue::push(int data, char type='+'){
  if(back==NULL){
    middle = front = back = createNode(data);
    length++;
    return;
  }

  if(type == '*'){
    Node* node = createNode(data);
    node->next = this->middle->next;
    node->prev = this->middle;
    this->middle->next = node;
    if((length % 2)==0){
      this->middle = node;
    }
    length++;
    return;
  }

  if(type == '+' && (length % 2)==0){
    middle->next->prev = middle;
    middle = middle->next;
  }

  Node* node = createNode(data);
  this->back->next = node;
  this->back = node;
  length++;

}

int Queue::pop(){
  if(front==NULL)return INT_MIN;

  if(length % 2 == 1){
    middle = middle->prev;
  }

  int value = front->data;
  Node* tmp = front;
  front = front->next;
  if(front==NULL) {back=NULL;middle=NULL;}
  delete tmp;
  length--;
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
  int n;
  std::cin >> n;
  int i = 0;
  char type;
  int id;
  while(i < n){
    std::cin >> type;
    if(type == '+'){
      std::cin >> id;
      queue->push(id, type);
    }
    else if(type == '*'){
      std::cin >> id;
      queue->push(id, type);
    }
    else if(type == '-'){
      std::cout << queue->pop() << std::endl;
    }
    i++;
  }
  delete queue;
  return 0;
}
