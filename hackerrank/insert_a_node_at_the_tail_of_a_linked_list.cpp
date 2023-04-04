#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
        ~SinglyLinkedListNode(){
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;

        SinglyLinkedList() {
            this->head = nullptr;
        }
        ~SinglyLinkedList(){
          while (head) {
              SinglyLinkedListNode * tmp = head;
              head = head->next;
              delete tmp;
          }
        }

};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep) {
    while (node) {
        cout << node->data;

        node = node->next;

        if (node) {
            cout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the insertNodeAtTail function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) { 
  if (head == nullptr) {
    head = new SinglyLinkedListNode(data);
    return head;
  }
  SinglyLinkedListNode * tmp = head;
  while (tmp->next) 
    tmp = tmp->next;
  cout << tmp->data;
  SinglyLinkedListNode * newnode = new SinglyLinkedListNode(data);
  tmp->next = newnode;
  return head;
}

int main()
{
    SinglyLinkedList* llist = new SinglyLinkedList();
    llist->head = new SinglyLinkedListNode(1);
    vector<int> arr = {2,3,4};
    for (int i : arr) {
      cout << i;
      SinglyLinkedListNode * newnode = new SinglyLinkedListNode(i);
      llist->head->next = newnode;
      llist->head = newnode;
    }
    /* print_singly_linked_list(llist->head, "\n"); */
    free_singly_linked_list(llist->head);
    return 0;
}
