#include <stdio.h>
#include "dArray.h"
#include "linkedList.h"




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


    list_remove((NODE_PP)&my_linked_list,(NODE_P)str_5);

    list_reverse((NODE_PP)&my_linked_list);

    
    
    string_item_t *string_item = my_linked_list;
    while (string_item)
    {
        printf("%s\n", string_item->string);
        string_item = (string_item_t *)string_item->node.next;
    }
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
    Test_LinkedList();
    
    return 0;
}


