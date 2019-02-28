#include <stdio.h>
#include "linked_list.h"

int main()
{
    linked_list_node_t *linked_list = linked_list_create(1);

    linked_list_insert_at_end(linked_list, 20);
    linked_list_insert_at_end(linked_list, 50);
    linked_list_insert_at_end(linked_list, 50);
    linked_list_insert_at_beginning(&linked_list, 40);
    linked_list_insert_after(linked_list, 25, 3);

    int size_of_linked_list = linked_list_size(linked_list);
    printf("The size of list: %d\n", size_of_linked_list);

    printf("The list is empty: %d\n", linked_list_empty(linked_list));
    linked_list_print(linked_list);
    // deleting first element of linked list and returning the new head
    linked_list = linked_list_delete_first(linked_list);
    printf("%p\n",linked_list);

    linked_list_print(linked_list);

    int deleted_nodes = linked_list_delete_by_value(&linked_list, 20);
    printf("%d node(s) have been deleted!\n", deleted_nodes);
    deleted_nodes = linked_list_delete_by_value(&linked_list, 1);
    printf("%d node(s) have been deleted!\n", deleted_nodes);
    deleted_nodes = linked_list_delete_by_value(&linked_list, 25);
    printf("%d node(s) have been deleted!\n", deleted_nodes);
    linked_list_print(linked_list);
    deleted_nodes = linked_list_delete_by_value(&linked_list, 50);
    printf("%d node(s) have been deleted!\n", deleted_nodes);
    printf("The list is empty: %d\n", linked_list_empty(linked_list));

    linked_list = linked_list_create(10);
    linked_list_push_back(linked_list, 5);
    linked_list_push_back(linked_list, 20);
    linked_list_push_back(linked_list, 15);
    linked_list_push_back(linked_list, 5);
    linked_list_print(linked_list);
    printf("The list is empty: %d\n", linked_list_empty(linked_list));
    printf("The memory address of the given value is: %p\n", linked_list_search(linked_list, 5));
    linked_list = linked_list_bubble_sort(linked_list);
    linked_list_print(linked_list);



    linked_list_dealloc(linked_list);
    return 0;
}