#include <stdio.h>
#include "dArray.h"
#include "linkedList.h"
#include "doubleLinked.h"


void PrintLinkedList(string_item_t *list)
{
    while (list)
    {
        printf("%s\n", list->string);
        list = (string_item_t *)list->node.next;
    }
}

void Test_DoubleLinkedList()
{
    dInt_item_t *list = NULL;
    dInt_item_t *int1 = dInt_create(1);
    dInt_item_t *int2 = dInt_create(2);
    dInt_item_t *int3 = dInt_create(3);
    dInt_item_t *int4 = dInt_create(4);
    dInt_item_t *int5 = dInt_create(5);
    dInt_item_t *int6 = dInt_create(6);


    dlist_append((DNODE_PP)&list,(DNODE_P)int1);
    dlist_append((DNODE_PP)&list,(DNODE_P)int2);
    dlist_append((DNODE_PP)&list,(DNODE_P)int3);
    dlist_append((DNODE_PP)&list,(DNODE_P)int4);
    dlist_append((DNODE_PP)&list,(DNODE_P)int5);

    //dList_remove((DNODE_PP)&list,(DNODE_P)int5);
    dList_insert_before((DNODE_PP)&list,(DNODE_P)int1,(DNODE_P)int6);
    if (int6->node.prev)
    {
        printf("\nè nullo");
    }
    


    dList_print(list);
}

void Test_LinkedList()
{
    string_item_t *my_linked_list = NULL;
    string_item_t *str_1 = string_item_new("1");
    string_item_t *str_2 = string_item_new("2");
    string_item_t *str_3 = string_item_new("3");
    string_item_t *str_4 = string_item_new("4");
    string_item_t *str_5 = string_item_new("5");

    list_append((NODE_PP)&my_linked_list, (NODE_P)str_1);
    list_append((NODE_PP)&my_linked_list, (NODE_P)str_2);
    list_append((NODE_PP)&my_linked_list, (NODE_P)str_3);
    list_append((NODE_PP)&my_linked_list, (NODE_P)str_4);


    list_remove((NODE_PP)&my_linked_list,(NODE_P)str_2);

    PrintLinkedList(my_linked_list);
    printf("\n\n");
    printf("reversed list:\n");

    list_reverse((NODE_PP)&my_linked_list);
    PrintLinkedList(my_linked_list);
    
    

}

void Test_dynarray()
{
    dynarray_t array;
    dynarray_init_type(&array,int);

    int a = 100;
    int b = 300;
    int c = 500;
    dynarray_append(&array,&a);
    dynarray_append(&array,&b);
    dynarray_append(&array,&c);
    int val;
    dynarray_get(&array,1,&val);
    printf("res: %d",val);
}

int main(int argc, char const *argv[])
{
    Test_DoubleLinkedList();
    
    return 0;
}


