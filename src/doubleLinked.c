#include "doubleLinked.h"
#include "linkedList.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stddef.h>



dlist_node_t *dlist_get_tail(dlist_node_t **head)
{
    dlist_node_t *current_node = *head;
    dlist_node_t *last_node = NULL;

    while (current_node)
    {
        last_node = current_node;
        current_node = current_node->next;
    }
    return last_node;
}

dInt_item_t *dInt_create(int n)
{
    dInt_item_t *item = malloc(sizeof(dInt_item_t));
    if (!item)
    {
        return NULL;
    }
    item->n = n;
    return item;
}

void dList_print(dInt_item_t *list)
{
    while (list)
    {
        printf("%d\n", list->n);
        list = (dInt_item_t *)list->node.next;
    }
}

void dList_remove(dlist_node_t **head,dlist_node_t *item)
{
    if (*head==item)
    {
        *head = item->next; //se l'elemento da rimuovere è la testa il successivo diventa la nuova testa
        return;
    }

    if (item == dlist_get_tail(head)) //se l'elemento è l'ultimo rendo il successivo del precedente nullo
    {
        item->prev->next = NULL;
        return;
    }
    
    
    if(dList_contain(head,item))   //rimuovo l'elemento solo se appartiene alla lista specificata
    {
        item->prev->next = item->next;
        item->next->prev = item->prev;
    }
    else
    {
        perror("list don't contain item");
    }

}

int dList_insert_before(dlist_node_t **head,dlist_node_t *before_this,dlist_node_t *item)
{
    if(dList_contain(head,item))
    {
        printf("item already on list\n");
        return -1;
    }
    if (dList_contain(head,before_this))
    {
        dlist_node_t *prev_node = before_this->prev;

        if (!prev_node)
        {
            *head = item;
            item->next = before_this;
            item->prev = NULL;
            
            before_this->prev = item;
            return 0;
        }
        else
        {
            prev_node->next = item;
            item->prev = prev_node;
            item->next = before_this;
            before_this->prev = item;
            return 0;
        }
        
    }

    printf("elemento selezionato non in lista");
    return -1;
}

int dList_insert_after(dlist_node_t **head,dlist_node_t *after_this,dlist_node_t *item)
{
    if (dList_contain(head,item))
    {
        printf("item already on list\n");
        return -1;
    }
    if (dList_contain(head,after_this))
    {
        dlist_node_t *next_node = after_this->next;

        if (!next_node)  //si sta inserendo a fine lista
        {
            item->next = NULL;
        }
        else
        {
            item->next = next_node;
            next_node->prev = item;
        }
        
        after_this->next = item;
        item->prev = after_this;
        return 0;
    }
    else return -1;
    
}

int dList_contain(dlist_node_t **head,dlist_node_t *item)
{
    dlist_node_t *current_node = *head;
    dlist_node_t *last_node = NULL;

    while (current_node)
    {
        if (current_node == item)
        {
            return 1;
        }
        
        last_node = current_node;
        current_node = current_node->next;
    }
    return 0;
}

dlist_node_t *dlist_append(dlist_node_t **head, dlist_node_t *item)
{
    dlist_node_t *tail = dlist_get_tail(head);
    if (!tail)
    {
        * head = item;
    }
    else
    {
        tail->next = item;
    }
    item->prev = tail;
    item->next = NULL;
    return item;
}



