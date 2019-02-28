#ifndef LINKED_LIST_LINKED_LIST_H
#define LINKED_LIST_LINKED_LIST_H

typedef struct linked_list_node
{
    int value;
    struct linked_list_node *next;
} linked_list_node_t;

// creates linked list with given value
linked_list_node_t *linked_list_create(int value);
// push back node if linked list exists (has atleast 1 node)
void linked_list_push_back(linked_list_node_t *linked_list, int value);
// prints all of the elements of the linked list
void linked_list_print(linked_list_node_t *linked_list);
// deallocate the linked list
void linked_list_dealloc(linked_list_node_t *linked_list);
// inserts a node after the last node in the linked list
void linked_list_insert_at_end(linked_list_node_t *linked_list, int value);
// inserts a node before the head and makes it new head node
void linked_list_insert_at_beginning(linked_list_node_t **linked_list, int value);
// inserts a node with the given value after given node
void linked_list_insert_after(linked_list_node_t *linked_list, int value, int at);
// returns the size of the linked list
int linked_list_size(linked_list_node_t *linked_list);
// returns a "bool" if the list is empty 1 else 0
int linked_list_empty(linked_list_node_t *linked_list);
// deletes the first node in the list and gives back the new head node's memory address
linked_list_node_t *linked_list_delete_first(linked_list_node_t *linked_list);
// deletes every node with the same value as given value
int linked_list_delete_by_value(linked_list_node_t **linked_list, int value);
// searches for the first occurence of the given value and returns the memory address
linked_list_node_t *linked_list_search(linked_list_node_t *linked_list, int value);

void bubble_sort(linked_list_node_t *linked_list);

#endif //LINKED_LIST_LINKED_LIST_H
