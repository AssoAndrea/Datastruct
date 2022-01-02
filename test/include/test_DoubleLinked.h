#include "clove.h"
#include "doubleLinked.h"




CLOVE_TEST(DoubleListRemove)
{
    dInt_item_t *list = NULL;
    dInt_item_t *int1 = dInt_create(1);
    dInt_item_t *int2 = dInt_create(2);
    dInt_item_t *int3 = dInt_create(3);


    dlist_append((DNODE_PP)&list, (DNODE_P)int1);
    dlist_append((DNODE_PP)&list, (DNODE_P)int2);
    dlist_append((DNODE_PP)&list, (DNODE_P)int3);

    dList_remove((DNODE_PP)&list, (DNODE_P)int2);
    CLOVE_IS_TRUE(dList_contain((DNODE_PP)&list, (DNODE_P)int1));
    CLOVE_IS_TRUE(dList_contain((DNODE_PP)&list, (DNODE_P)int3));

    dList_remove((DNODE_PP)&list, (DNODE_P)int1);
    CLOVE_IS_TRUE(dList_contain((DNODE_PP)&list, (DNODE_P)int3));
    
    dlist_append((DNODE_PP)&list, (DNODE_P)int1);
    dList_remove((DNODE_PP)&list, (DNODE_P)int3);
    CLOVE_IS_TRUE(dList_contain((DNODE_PP)&list, (DNODE_P)int1));
}

CLOVE_TEST(DoubleAppendAfter)
{
    dInt_item_t *list = NULL;
    dInt_item_t *int1 = dInt_create(1);
    dInt_item_t *int2 = dInt_create(2);
    dInt_item_t *int3 = dInt_create(3);


    dlist_append((DNODE_PP)&list, (DNODE_P)int1);
    dlist_append((DNODE_PP)&list, (DNODE_P)int2);
    dlist_append((DNODE_PP)&list, (DNODE_P)int3);


    dInt_item_t *int4 = dInt_create(4);

    dInt_item_t *int5 = dInt_create(5);



    dList_insert_after((DNODE_PP)&list, (DNODE_P)int2, (DNODE_P)int4);

    dlist_node_t *addedNode = (DNODE_P)int4;
    dlist_node_t *prevNode = (DNODE_P)int2;
    dlist_node_t *nextNode = (DNODE_P)int3;


    CLOVE_IS_TRUE(dList_contain((DNODE_PP)&list, addedNode));
    CLOVE_IS_TRUE(addedNode->next == nextNode);
    CLOVE_IS_TRUE(addedNode->prev == prevNode);
    CLOVE_IS_TRUE(prevNode->next == addedNode);
    CLOVE_IS_TRUE(nextNode->prev == addedNode);
    

    //test on insert after last element
    dList_insert_after((DNODE_PP)&list, (DNODE_P)int3, (DNODE_P)int5);
    addedNode = (DNODE_P)int5;
    prevNode = (DNODE_P)int3;
    CLOVE_IS_TRUE(dList_contain((DNODE_PP)&list, addedNode));
    CLOVE_IS_TRUE(addedNode->next == NULL);
    CLOVE_IS_TRUE(addedNode->prev == prevNode);
    CLOVE_IS_TRUE(prevNode->next == addedNode);
}

CLOVE_TEST(DoubleShuffle)
{
    dInt_item_t *list = NULL;
    dInt_item_t *int1 = dInt_create(1);
    dInt_item_t *int2 = dInt_create(2);
    dInt_item_t *int3 = dInt_create(3);

    int saved_value[] = {int1->n, int2->n, int3->n};

    dlist_append((DNODE_PP)&list, (DNODE_P)int1);
    dlist_append((DNODE_PP)&list, (DNODE_P)int2);
    dlist_append((DNODE_PP)&list, (DNODE_P)int3);

    list = dList_shuffle((DNODE_PP)&list);

    int one_is_changed = 0;
    int try_one_more_time = 0;

    for (int i = 0; i < 3; i++)
    {
        if (list->n != saved_value[i])
        {
            one_is_changed = 1;
            break;
        }
        list = (dInt_item_t *)list->node.next;
    }
    
    CLOVE_IS_TRUE(one_is_changed);
}

// int Check_if_changed(dInt_item_t *list,int *saved_value)
// {

// }

CLOVE_TEST(DoubleAppendBefore)
{
    dInt_item_t *list = NULL;
    dInt_item_t *int1 = dInt_create(1);
    dInt_item_t *int2 = dInt_create(2);
    dInt_item_t *int3 = dInt_create(3);


    dlist_append((DNODE_PP)&list, (DNODE_P)int1);
    dlist_append((DNODE_PP)&list, (DNODE_P)int2);
    dlist_append((DNODE_PP)&list, (DNODE_P)int3);


    dInt_item_t *int4 = dInt_create(4);

    dInt_item_t *int5 = dInt_create(5);

    dList_insert_before((DNODE_PP)&list, (DNODE_P)int2, (DNODE_P)int4);

    dlist_node_t *addedNode = (DNODE_P)int4;
    dlist_node_t *prevNode = (DNODE_P)int1;
    dlist_node_t *nextNode = (DNODE_P)int2;


    CLOVE_IS_TRUE(dList_contain((DNODE_PP)&list, addedNode));
    CLOVE_IS_TRUE(addedNode->next == nextNode);
    CLOVE_IS_TRUE(addedNode->prev == prevNode);
    CLOVE_IS_TRUE(prevNode->next == addedNode);
    CLOVE_IS_TRUE(nextNode->prev == addedNode);


    //test on insert before head
    dList_insert_before((DNODE_PP)&list, (DNODE_P)int1, (DNODE_P)int5);
    addedNode = (DNODE_P)int5;
    nextNode = (DNODE_P)int1;
    CLOVE_IS_TRUE(dList_contain((DNODE_PP)&list, addedNode));
    CLOVE_IS_TRUE(addedNode->prev == NULL);
    CLOVE_IS_TRUE(addedNode->next == nextNode);
    CLOVE_IS_TRUE(nextNode->prev == addedNode);
}