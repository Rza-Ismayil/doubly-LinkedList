#include "LinkedList.h"

LinkedList * LL_newEmpty()
{
    return NULL;
}

LinkedList * LL_addFirst(LinkedList * list, item value)
{
    LinkedList * new = (LinkedList *) calloc(1, sizeof(LinkedList));
    
    new->data = value;
    new->next = list;
    new->prev = NULL;

    if(list != NULL)
        list->prev = new;

    return new;
}

LinkedList * LL_addLast(LinkedList * list, item value)
{
    LinkedList * new = (LinkedList *) calloc(1, sizeof(LinkedList));
    new->data = value;
    new->next = NULL;
    if(list == NULL)
    {
        new->prev = NULL;
        return new;
    }
    else
    {
        LinkedList * last = LL_getLast(list);
        last->next = new;
        new->prev = last;
        return list;
    }
}

LinkedList * LL_add(LinkedList * list, item value, int index)
{
    int size = LL_length(list);
    if(index == 0)
    {
        return LL_addFirst(list,value);
    }
    else if(size == index)
    {
        return LL_addLast(list,value);
    }
    else if(size > index)
    {
        LinkedList * front = LL_get(list, index-1);
        LinkedList * back = LL_get(list, index);

        LinkedList * new = (LinkedList *) calloc(1, sizeof(LinkedList));
        new->data = value;
        new->next = back;
        new->prev = front;
        
        front->next = new;
        back->prev = new;

        return list;
    }
    else
    {
        printf("Out of range!\n");
        return list;
    }
}

LinkedList * LL_removeFirst(LinkedList * list)
{
    LinkedList * returnValue = list->next;
    free(list);
    returnValue->prev = NULL;
    return returnValue;
}

LinkedList * LL_removeLast(LinkedList * list)
{
    LinkedList * newLast;
    for (newLast = list; newLast->next->next !=  NULL; newLast = newLast->next);
    free(newLast->next);
    newLast->next = NULL;
    return list;
}

LinkedList * LL_removeElement(LinkedList *list, LinkedList * element)
{
    LinkedList * front = element->prev;
    LinkedList * back = element->next;
    if(element == NULL)
    {
        printf("Null element!\n");
        return list;
    }
    if(LL_contains(list, element))
    {
        if(front != NULL && back != NULL)
        {
            front->next = back;
            back->prev = front;
            
            free(element);
            return list;
        }
        else if(front == NULL && back != NULL)
        {
            back->prev = NULL;
            
            free(element);
            return back;
        }
        else if(front != NULL && back == NULL)
        {
            front->next = NULL;

            free(element);
            return list;
        }
        else
        {
            free(element);
            return NULL;
        }
    }
    else
    {
        printf("Element not found!\n");
        return list;
    }
    
}

LinkedList * LL_removeFirstValue(LinkedList *list, item value)
{
    for (LinkedList * i = list; i != NULL; i = i->next)
    {
        if(i->data == value) // depend on the data type different way of comparison will be needed
        {
            return LL_removeElement(list, i);
        }
    }
    printf("Value not found!\n");
    return list;
}

LinkedList * LL_removeLastValue(LinkedList *list, item value)
{
    LinkedList * lastValue = NULL;
    for (LinkedList * i = list; i != NULL; i = i->next)
    {
        if(i->data == value) // depend on the data type different way of comparison will be needed
        {
            lastValue = i;
        }
    }
    if(lastValue == NULL)
    {
        printf("Value not found!\n");
    }
    else
    {
        return LL_removeElement(list, lastValue);
    }

}

LinkedList * LL_removeAllValues(LinkedList *list, item value)
{
    if (list == NULL)
    {
        printf("Empty list!\n");
        return list;
    }
    int size = 0;
    LinkedList * elements[LL_length(list)];
    for (LinkedList * i = list; i != NULL; i = i->next)
    {
        if(i->data == value) // depend on the data type different way of comparison will be needed
        {
            elements[size] = i;
            size++;
        }
    }
    if(size == 0)
    {
        printf("Value not found!\n");
    }
    else
    {
        for(int i = 0; i < size; i++)
        {
            list = LL_removeElement(list, elements[i]);
        }
    }
    return list;
}

LinkedList * LL_remove(LinkedList * list, int index)
{
    if(list == NULL)
    {
        printf("Empty list!\n");
        return list;
    }
    LinkedList * element = LL_get(list, index);
    if(element == NULL)
    {
        return list;
    }
    return LL_removeElement(list, element);
}

LinkedList * LL_clear(LinkedList * list)
{
    if(list == NULL)
    {
        return NULL;
    }
    else
    {
        LL_clear(list->next);
        free(list);
        return NULL;
    }
}

LinkedList * LL_clone(LinkedList * list)
{
    LinkedList * new = LL_newEmpty();
    if(list == NULL)
    {
        return NULL;
    }
    for(LinkedList * i = list; i != NULL; i = i->next)
    {
        new = LL_addLast(new, i->data);
    }
    return new;
}

LinkedList * LL_get(LinkedList * list, int index)
{
    LinkedList * element = list;
    for(int i=0; element != NULL; i++, element = element->next)
    {
        if(i == index)
        {
            return element;
        }
    }
    printf("Out of range!\n");
    return NULL;
}

LinkedList * LL_getLast(LinkedList * list)
{
    if(list == NULL)
    {
        printf("Empty list!\n");
        return NULL;
    }
    LinkedList * i;
    for (i = list; i->next != NULL; i = i->next);
    return i;
}

LinkedList * LL_getFirst(LinkedList * list)
{
    return list;
}

item LL_getValue(LinkedList * list, int index)
{
    return LL_get(list, index)->data;
}

item LL_getLastValue(LinkedList * list)
{
    return LL_getLast(list)->data;
}

item LL_getFirstValue(LinkedList * list)
{
    return LL_getFirst(list)->data;
}

int LL_isEmpty(LinkedList * list)
{
    if(list == NULL) return 1;
    return 0;
}

int LL_contains(LinkedList * list, LinkedList * element)
{
    if (list == NULL)
    {
        printf("Empty list!\n");
        return 0;
    }
    else if(element == NULL)
    {
        printf("Null element!");
        return 0;
    }

    for (LinkedList * i = list; i != NULL; i = i->next)
    {
        if(i == element)
        {
            return 1;
        }
    }
    return 0;
}

int LL_containsValue(LinkedList * list, item value)
{
    if (list == NULL)
    {
        printf("Empty list!\n");
        return 0;
    }

    for (LinkedList * i = list; i != NULL; i = i->next)
    {
        if(i->data == value)// depend on the data type different way of comparison will be needed
        {
            return 1;
        }
    }
    return 0;
}

int LL_equals(LinkedList * list1, LinkedList * list2)
{
    int size = LL_length(list1);
    if( size != LL_length(list2) )
    {
        return 0;
    }
    else
    {
        int result = 1;

        LinkedList * L1 = list1;
        LinkedList * L2 = list2;
        
        while (L1 != NULL && L2 != NULL)
        {
            if(L1->data != L2->data) // depend on the data type different way of comparison will be needed
            {
                result = 0;
            }
            L1 = L1->next; L2 = L2->next;
        }
        return result;
    }
}

int LL_length(LinkedList * list)
{
    if(list == NULL)
    {
        return 0;
    }
    else
    {
        int size = 0;
        for (LinkedList * i = list; i != NULL; i = i->next, size++);
        return size;
    }
}

int LL_indexOfElement(LinkedList * list, LinkedList * element)
{
    if(list == NULL)
    {
        printf("Empty list!\n");
        return -1;
    }
    if(element == NULL)
    {
        printf("Null element!\n");
        return -1;
    }

    int index = 0;
    for(LinkedList * i = list; i != NULL; i = i->next, index ++)
    {
        if(i == element)
        {
            return index;
        }
    }

    return -1;
}

int LL_indexOfFirstValue(LinkedList * list, item value)
{
    if(list == NULL)
    {
        printf("Empty list!\n");
        return -1;
    }

    int index = 0;
    for(LinkedList * i = list; i != NULL; i = i->next, index ++)
    {
        if(i->data == value) // depend on the data type different way of comparison will be needed
        {
            return index;
        }
    }

    return -1;
}

int LL_indexOfLastValue(LinkedList * list, item value)
{
    if(list == NULL)
    {
        printf("Empty list!\n");
        return -1;
    }
    int result = -1;
    int index = 0;
    for(LinkedList * i = list; i != NULL; i = i->next, index ++)
    {
        if(i->data == value) // depend on the data type different way of comparison will be needed
        {
            result = index;
        }
    }

    return result;
}

int LL_indexesOfValue(LinkedList * list, item value, int * indexes)
{
    int size = 0;
    int index = 0;
    for(LinkedList * i = list; i != NULL; i = i->next, index ++)
    {
        if(i->data == value) // depend on the data type different way of comparison will be needed
        {
            indexes[size] = index;
            size++;
        }
    }
    if(size == 0)
    {
        printf("Value not found!\n");
    }
    return size;
}


void LL_show(LinkedList * list)
{
    if(list == NULL)
    {
        printf("Empty list!");
    }
    for (LinkedList * i = list; i != NULL; i = i->next)
    {
        // Valid print form should be provided for i->data (item)
    }
    printf("\n");
}
