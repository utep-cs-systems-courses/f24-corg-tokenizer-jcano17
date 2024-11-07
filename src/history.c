#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

/* Initialize the linked list to keep the history. */
List* init_history(){
  List *Lhistory = (List*) malloc(sizeof(List));
  Lhistory -> root = NULL;
  return Lhistory;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str){
    
    short len = 0;
    for (int i = 0; str[i]!='\0';i++){
        len++;
    }
    
    Item *item = (Item*)malloc(sizeof(Item));
    //copy contents of str into item
    item->str = copy_str(str,len);
    item->next = NULL;
    //checks that list isnt empty else adds the item to the first node
    if (list->root==NULL){
        list->root= item;
        item->id = 1;
    //adds to the next node
    }else{
        Item *prevItem = list->root;
        int prevItmID = prevItem->id;
        while(prevItem->next != NULL){
            prevItem = prevItem->next;
            prevItmID = prevItem->id;
        }
        prevItem->next = item;
        item -> id = prevItmID+1;
    }
  }

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id){
    Item *item = list->root;
    while(item!= NULL){
        if(item ->id == id){
            
            return item ->str;
        }
        item = item->next;
        }
    
    return NULL;
}

/*Print the entire contents of the list. */
void print_history(List *list){
    Item *item = list ->root;
    if (item == NULL || list ==NULL){
        printf("No history.");
    }
    while(item!=NULL){
        printf("%d. %s \n", item->id,item->str);
        item = item->next;
    }
}

/*Free the history list and the strings it references. */
void free_history(List *list){
    Item *item = list->root;
    Item *tmp;
    while (item !=NULL){
        tmp = item;
        item = item ->next;
        free(tmp);
    }
}
