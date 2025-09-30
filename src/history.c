#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"



List *init_history() {
  List *list = (List *)malloc(sizeof(List)); //Memory allocation of new list
  list->root = NULL;
  // list->size = 0;
  return list;
}



void add_history(List *list, char *str) {
  Item *item = (Item *)malloc(sizeof(Item)); //Memory allocation of new item
  if(list->root == NULL){
    item->id = 1;
  } else {
    Item *curr = list->root;
    while(curr->next != NULL){
      curr = curr->next;
    }
    item->id = curr->id + 1;
  }

  int strLength = 0;
  while(str[strLength]!= '\0'){//gets the length of the string
    strLength++;
  }
  item->str = copy_str(str,strLength);  //copies the string
  item->next = NULL;
  
  if(list->root == NULL){
    list->root = item;
  } else {
    Item *curr = list->root;
    while(curr->next != NULL){
      curr = curr->next;
    }
    curr->next = item;
  }
}



char *get_history (List *list, int id) {
  Item *curr = list->root;
  while (curr) {
    if (curr->id == id) return curr->str; //loops until it matches id
    curr = curr->next;
  }
  return NULL;
}



void print_history(List *list) {
  Item *curr = list->root;
  while (curr) {
    printf("%d: %s\n", curr->id, curr->str);
    curr = curr->next;
  }
}


void free_history(List *list) {
  Item *curr = list->root;
  while (curr) {
    Item *tmp = curr;
    curr = curr->next;
    free(tmp->str);
    free(tmp);
  }
  free(list);
} 
