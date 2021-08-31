#ifndef  _LINKEDLIST_H_
#define  _LINKEDLIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef int item;

typedef struct linkedlist
{
    item data;
    struct linkedlist * next;
    struct linkedlist * prev;

}LinkedList;

LinkedList * LL_newEmpty();
LinkedList * LL_addFirst(LinkedList * list, item value);
LinkedList * LL_addLast(LinkedList * list, item value);
LinkedList * LL_add(LinkedList * list, item value, int index);
LinkedList * LL_removeFirst(LinkedList * list);
LinkedList * LL_removeLast(LinkedList * list);
LinkedList * LL_removeElement(LinkedList *list, LinkedList * element);
LinkedList * LL_removeFirstValue(LinkedList *list, item value);
LinkedList * LL_removeLastValue(LinkedList *list, item value);
LinkedList * LL_removeAllValues(LinkedList *list, item value);
LinkedList * LL_remove(LinkedList * list, int index);

LinkedList * LL_clear(LinkedList * list);
LinkedList * LL_clone(LinkedList * list);

LinkedList * LL_get(LinkedList * list, int index);
LinkedList * LL_getLast(LinkedList * list);
LinkedList * LL_getFirst(LinkedList * list);

item LL_getValue(LinkedList * list, int index);
item LL_getLastValue(LinkedList * list);
item LL_getFirstValue(LinkedList * list);

int LL_isEmpty(LinkedList * list);
int LL_contains(LinkedList * list, LinkedList * element);
int LL_containsValue(LinkedList * list, item value);
int LL_equals(LinkedList * list1, LinkedList * list2);

int LL_length(LinkedList * list);
int LL_indexOfElement(LinkedList * list, LinkedList * element);
int LL_indexOfFirstValue(LinkedList * list, item value);
int LL_indexOfLastValue(LinkedList * list, item value);
int LL_indexesOfValue(LinkedList * list, item value, int * indexes);

void LL_show(LinkedList * list);

#endif//_LINKEDLIST_H_