#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

linked_list_node_t *linked_list_create(int value)
{
    linked_list_node_t *linked_list = (linked_list_node_t*)malloc(sizeof(linked_list_node_t));

    linked_list->value = value;
    linked_list->next = NULL;

    return linked_list;
}

void linked_list_push_back(linked_list_node_t *linked_list, int value)
{
    // allocate memory for a new node and initialize it
    linked_list_node_t *new_node = (linked_list_node_t*)malloc(sizeof(linked_list_node_t));
    new_node->value = value;
    new_node->next = NULL;
    if (linked_list == NULL) {
        linked_list = new_node;
    }
    // iterate through the list to find the last element
    linked_list_node_t *it = linked_list;
    while (it->next != NULL) {
        it = it->next;
    }

    // set the pointer of the last element to the new node
    it->next = new_node;
}

void linked_list_print(linked_list_node_t *linked_list)
{
    //iterate through the list
    linked_list_node_t *it;
    if (linked_list == NULL) {
        printf("the list is empty\n");
    }
    it = linked_list;
    while (it != NULL) {
        printf("%p: %d\n", it, it->value);
        it = it->next;
    }
}

void linked_list_dealloc(linked_list_node_t *linked_list)
{
    linked_list_node_t *node_to_free = linked_list;

    while (node_to_free != NULL) {
        linked_list_node_t *next_node = node_to_free->next;
        free(node_to_free);
        node_to_free = next_node;
    }
}

void linked_list_insert_at_end(linked_list_node_t *linked_list, int value)
{
    // create new node
    linked_list_node_t *new_node = (linked_list_node_t*)malloc(sizeof(linked_list_node_t));

    if (new_node == NULL) {
        printf("Unable to allocate memory for new node\n");
        return;
    }

    new_node->value = value;
    new_node->next = NULL;

    // check for first insertion
    if (linked_list->next == NULL) {
        linked_list->next = new_node;
        //printf("added at the beginning\n");
    } else {
        // loop through the list and find the last element
        // insert new node
        linked_list_node_t *it = linked_list;
        while (it->next != NULL) {
            it = it->next;
        }
        it->next = new_node;
        //printf("added at the end\n");
    }
}

void linked_list_insert_at_beginning(linked_list_node_t **linked_list, int value)
{
    linked_list_node_t *new_node = (linked_list_node_t*)malloc(sizeof(linked_list_node_t));

    if (new_node == NULL) {
        printf("Unable to allocate memory for new node\n");
        return;
    }

    new_node->value = value;
    new_node->next = (*linked_list);

    (*linked_list) = new_node;
    //printf("inserted at the beginning\n");
}

void linked_list_insert_after(linked_list_node_t *linked_list, int value, int at)
{
    linked_list_node_t *new_node = (linked_list_node_t*)malloc(sizeof(linked_list_node_t));
    new_node->value = value;
    new_node->next = NULL;
    if (at == 1) {
        linked_list->next = new_node;
        return;
    }
    linked_list_node_t *temp = linked_list;
    for (int i = 0; i < at - 1; i++) {
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

int linked_list_size(linked_list_node_t *linked_list)
{
    linked_list_node_t *it = linked_list;
    int count = 0;
    if (it == NULL) {
        printf("the list is empty\n");
        return count;
    } else {
        if (it->next == NULL) {
            count = 1;
            return count;
        }
        while (it != NULL) {
            it = it->next;
            count++;
        }
    }
    return count;
}

int linked_list_empty(linked_list_node_t *linked_list)
{
    if (linked_list == NULL) {
        return 1;
    }
    return 0;
}

linked_list_node_t *linked_list_delete_first(linked_list_node_t *linked_list)
{
    linked_list_node_t *to_delete;
    if (linked_list == NULL) {
        printf("The list is empty!\n");
    }
    to_delete = linked_list;
    linked_list = linked_list->next;

    printf("Data deleted = %d\n", to_delete->value);

    // clear the first node
    free(to_delete);

    return linked_list;
}

int linked_list_delete_by_value(linked_list_node_t **linked_list, int value)
{
    int total_deleted = 0;
    linked_list_node_t *current = *linked_list, *prev = NULL, *next = NULL;

    while (current != NULL) {
        next = current->next;
        if (current->value == value) {
            free(current);
            total_deleted++;
            if (prev != NULL) {
                prev->next = next;
            } else {
                *linked_list = next;
            }
        } else {
            prev = current;
        }
        current = next;
    }
    return total_deleted;
}

linked_list_node_t *linked_list_search(linked_list_node_t *linked_list, int value)
{
    linked_list_node_t *next = linked_list->next;
    linked_list_node_t *current = linked_list;
    while (current != NULL) {
        if (current->value == value) {
            return current;
        } else {
            if (current->next != NULL) {
                current = next;
                next = next->next;
            } else {
                return NULL;
            }
        }
    }
}

void bubble_sort(linked_list_node_t *linked_list)
{
    int swapped, i;
    linked_list_node_t *ptr, *lptr = NULL;

    if (linked_list == NULL) {
        return;
    }

    
}

