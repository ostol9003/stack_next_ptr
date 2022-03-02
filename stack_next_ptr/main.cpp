//
//  main.cpp
//  stack_next_ptr
//
//  Created by Marcin Ostolski on 02/03/2022.
//

#include <iostream>
#include <stdlib.h>

using namespace std;

typedef int item_t;

typedef struct node {
  item_t item;
  node* next_ptr;
} node_t;

typedef node_t *list_ptr_t;

typedef node_t *Stack;

// Wersja z przekazywaniem parametrów przez referencję
void create(list_ptr_t &list_ptr) {
  if (list_ptr != NULL) {
    cout << "Lista juz istnieje. Nalezy ja najpierw skasowac.\n";
    return;
  }
  node_t *new_list_ptr = new node_t;
  new_list_ptr -> item = 0;
  new_list_ptr -> next_ptr = NULL;
  cout << "Lista zostala utworzona (tylko glowa).\n";
  list_ptr = new_list_ptr;
}

// Wersja z przekazywaniem parametrów przez wskaniki (wskanik do
// wskanika)
void create2(node_t **list_ptr) {}

// wstawienie x za elementem wskazywanym przez p
void insert(node_t *p, item_t x) {
  node_t *old_list_ptr = p -> next_ptr;
  node_t *new_list_ptr = new node_t;
  new_list_ptr -> item = x;
  new_list_ptr -> next_ptr = old_list_ptr;

  p -> next_ptr = new_list_ptr;
}

// wypisuje liste zaczynajšc od elementu wskazywanego przez głowę
void print(node_t *list_ptr) {
  if (list_ptr == NULL) {
    cout << "Błąd - przekazano wskaźnik pusty.\n";
    return;
  }
  node_t* p = list_ptr->next_ptr;
  cout << "Elementy listy: ";
  while (p != NULL ){
    cout << p -> item << " ";
    p = p -> next_ptr;
  }
  
  cout << endl;

}

// sprawdza czy x jest na liscie (funkcja iteracyjna)
bool found_iter(node_t *list_ptr, int x) {
if (list_ptr == NULL) {
    return false;
  }
  node_t *p = list_ptr -> next_ptr;
  if (p == NULL) {
    return false;
  }
  while (p != NULL) {
    if (p -> item == x) return true;
    p = p -> next_ptr;
  }
  return false;
  
}

void delete_next(node_t *p) {
  if (p == NULL || p -> next_ptr == NULL) {
    cout << "Lista nie istnieje lub nie ma elementow.\n";
    return;
  }
  node_t *delete_element = p -> next_ptr;
  p -> next_ptr = (p -> next_ptr) -> next_ptr;
  int x = delete_element->item;
  delete delete_element ;
  cout << "Element " << x << " zostal bezpiecznie usuniety.\n";

  
}

void delete_list(list_ptr_t &list_ptr) {
  if (list_ptr == NULL) {
    cout << "Blad: przekazano wskaznik pusty.\n";
    return;
  }
  node_t *p = list_ptr->next_ptr;
  while (p!=NULL){
    node_t *q;
    q = p-> next_ptr;
    delete p ;
    p = q;
  }
  delete list_ptr;
  list_ptr = NULL;

}


void createStack(Stack &s){
   create(s);
}

int isEmpty(Stack s){
  return ( (s == NULL) || (s->next_ptr == NULL) );
}

int isFull(Stack s){
  return false;
}

void push(Stack s, item_t x){
  insert(s, x);
}

item_t pop(Stack &s){
 
}

item_t top(Stack &s){
 
}


int main() {
  Stack s;

}
