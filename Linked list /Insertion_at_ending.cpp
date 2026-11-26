#include <bits/stdc++.h>
#include <string>
using namespace std;
struct node {
   int data;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

void printList() {
   struct node *p = head;
   cout << "\n[";

   while(p != NULL) {
      cout << " " << p->data << " ";
      p = p->next;
   }
   cout << "]";
}

void insertatbegin(int data) {

   struct node *lk = (struct node*) malloc(sizeof(struct node));
   lk->data = data;
   lk->next = head;
   head = lk;
}

void insertatend(int data) {

   struct node *lk = (struct node*) malloc(sizeof(struct node));
   lk->data = data;
   struct node *linkedlist = head;
   while(linkedlist->next != NULL)
   linkedlist = linkedlist->next;

   linkedlist->next = lk;
}

int main(){
   insertatbegin(11);
   insertatend(29);
   insertatend(32);
   insertatend(84);
   insertatend(100);
   cout << "Linked List: ";

   printList();
}
