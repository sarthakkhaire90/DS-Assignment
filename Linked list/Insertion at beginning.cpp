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

int main(){
   insertatbegin(11);
   insertatbegin(29);
   insertatbegin(32);
   insertatbegin(84);
   insertatbegin(100);
   cout << "Linked List: ";

   printList();
}
