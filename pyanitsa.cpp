//https://informatics.mccme.ru/mod/statements/view3.php?id=206&chapterid=50#1
//B. Игра в пьяницу
#include <bits/stdc++.h>

class Node{
  public:
    Node* next;
    int data;
    Node(int data);
};

Node::Node(int data){
  next = NULL;
  this->data = data;
}

class Player{
  public:
    Node* last;
    Node* head;
    ~Player();
};

Player::~Player(){
  Node* current = head;
  while(current != NULL){
    Node* next = current->next;
    delete current;
    current = next;
  }
}

void display(Node* head){
  Node* current = head;
  while(current != NULL){
    Node* next = head->next;
    std::cout << current->data;
    current = next;
  }
}

int main(int argc, char *argv[])
{
  int counter = 0;
  Player* firstPlayer = new Player();
  Player* secondPlayer = new Player();
  std::string first_input;
  getline(std::cin, first_input);
  std::istringstream first_iss(first_input);
  int current;
  while (first_iss >> current){
    if(firstPlayer->head == NULL){
      firstPlayer->head = new Node(current);
      firstPlayer->last = firstPlayer->head;
    } else {
      firstPlayer->last->next = new Node(current);
      firstPlayer->last = firstPlayer->last->next;
    }
  }
  std::string second_input;
  getline(std::cin, second_input);
  std::istringstream second_iss(second_input);
  while (second_iss >> current){
    if(secondPlayer->head == NULL){
      secondPlayer->head = new Node(current);
      secondPlayer->last = secondPlayer->head;
    } else {
      secondPlayer->last->next = new Node(current);
      secondPlayer->last = secondPlayer->last->next;
    }
  }

  while(secondPlayer->head != NULL && firstPlayer->head != NULL){
    int first = firstPlayer->head->data;
    int second = secondPlayer->head->data;

    if(first == 9 && second == 0){
      secondPlayer->last->next = new Node(firstPlayer->head->data);
      secondPlayer->last->next->next = new Node(secondPlayer->head->data);
      secondPlayer->last = secondPlayer->last->next->next;
    }

    else if(first == 0 && second == 9){
      firstPlayer->last->next = new Node(first);
      firstPlayer->last->next->next = new Node(second);
      firstPlayer->last = firstPlayer->last->next->next;
    }

    else if(first > second){
      firstPlayer->last->next = new Node(first);
      firstPlayer->last->next->next = new Node(second);
      firstPlayer->last = firstPlayer->last->next->next;
    }

    else if(first < second){
      secondPlayer->last->next = new Node(firstPlayer->head->data);
      secondPlayer->last->next->next = new Node(secondPlayer->head->data);
      secondPlayer->last = secondPlayer->last->next->next;
    }

    Node* firstTemp = firstPlayer->head;
    Node* secondTemp = secondPlayer->head;
    firstPlayer->head = firstPlayer->head->next;
    secondPlayer->head = secondPlayer->head->next;
    delete firstTemp;
    delete secondTemp;
    firstTemp = NULL;
    secondTemp = NULL;
    counter++;
  }
  if(secondPlayer->head == NULL){
    std::cout << "first " << counter << std::endl;
  }
  else if(firstPlayer->head == NULL){
    std::cout << "second " << counter << std::endl;
  }

  delete firstPlayer;
  delete secondPlayer;

  return 0;
}
