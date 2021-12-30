#include "clove.h"
#include "linkedList.h"


CLOVE_TEST(ReverseLinkedList)
{
    string_item_t *my_linked_list = NULL;
    string_item_t *str_1 = string_item_new("1");
    string_item_t *str_2 = string_item_new("2");
    string_item_t *str_3 = string_item_new("3");

    string_item_t *strings[] = {str_1, str_2, str_3};

    list_append((NODE_PP)&my_linked_list, (NODE_P)str_1);
    list_append((NODE_PP)&my_linked_list, (NODE_P)str_2);
    list_append((NODE_PP)&my_linked_list, (NODE_P)str_3);

    list_reverse((NODE_PP)&my_linked_list);

    string_item_t *list = my_linked_list;
    for (int i = 2; i >= 0; i--)
    {
        CLOVE_PTR_EQ(list, strings[i]);
        list = (string_item_t *)list->node.next;
    }
    
}