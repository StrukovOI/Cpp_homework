#include "list.h"
#include <stdio.h>
#include <stdlib.h>

List init(size_t n) 
{
    List list;
    list.head = NULL;
    list.tail = NULL;
    list.size = 0;
    
    for (size_t i = 0; i < n; i++) 
    {
        Node* new_node = (Node*)malloc(sizeof(Node));
        if (new_node == NULL) 
        {
            printf("Memory error\n");
            exit(1);
        }
        new_node->value = 0;
        new_node->next = NULL;
        new_node->prev = list.tail;
        
        if (list.tail != NULL) 
        {
            list.tail->next = new_node;
        }
        list.tail = new_node;
        
        if (list.head == NULL) 
        {
            list.head = new_node;
        }
        
        list.size++;
    }
    
    return list;
}

void print(const List* pl) 
{
    Node* current = pl->head;
    while (current != NULL) 
    {
        printf("%i ", current->value);
        current = current->next;
    }
    printf("\n");
}

void push_back(List* pl, int value) 
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) 
    {
        printf("Memory error\n");
        exit(1);
    }
    
    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = pl->tail;
    
    if (pl->tail != NULL) 
    {
        pl->tail->next = new_node;
    }
    pl->tail = new_node;
    
    if (pl->head == NULL) 
    {
        pl->head = new_node;
    }
    
    pl->size++;
}

int pop_back(List* pl) 
{
    if (pl->tail == NULL) 
    {
        printf("List is empty\n");
        exit(1);
    }
    
    Node* last = pl->tail;
    int result = last->value;
    
    pl->tail = last->prev;
    if (pl->tail != NULL) 
    {
        pl->tail->next = NULL;
    } 
    else 
    {
        pl->head = NULL;
    }
    
    free(last);
    pl->size--;
    return result;
}

void push_front(List* pl, int value) 
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) 
    {
        printf("Memory error\n");
        exit(1);
    }
    
    new_node->value = value;
    new_node->prev = NULL;
    new_node->next = pl->head;
    
    if (pl->head != NULL) 
    {
        pl->head->prev = new_node;
    }
    pl->head = new_node;
    
    if (pl->tail == NULL) 
    {
        pl->tail = new_node;
    }
    
    pl->size++;
}

int pop_front(List* pl) 
{
    if (pl->head == NULL) 
    {
        printf("List is empty\n");
        exit(1);
    }
    
    Node* first = pl->head;
    int result = first->value;
    
    pl->head = first->next;
    if (pl->head != NULL) 
    {
        pl->head->prev = NULL;
    } 
    else 
    {
        pl->tail = NULL;
    }
    
    free(first);
    pl->size--;
    return result;
}

Node* erase(List* pl, Node* p) 
{
    if (p == NULL) 
    {
        return NULL;
    }
    
    if (p->prev != NULL) 
    {
        p->prev->next = p->next;
    } 
    else 
    {
        pl->head = p->next;
    }
    
    if (p->next != NULL) 
    {
        p->next->prev = p->prev;
    } 
    else 
    {
        pl->tail = p->prev;
    }
    
    Node* next_node = p->next;
    free(p);
    pl->size--;
    
    return next_node;
}

void splice(List* plist, Node* p, List* pother) 
{
    if (pother->head == NULL) 
    {
        return;
    }
    
    if (p == NULL) 
    {
        if (plist->tail != NULL) 
        {
            plist->tail->next = pother->head;
            pother->head->prev = plist->tail;
        } 
        else 
        {
            plist->head = pother->head;
        }
        plist->tail = pother->tail;
    } 
    else if (p == plist->head) 
    {
        pother->tail->next = plist->head;
        plist->head->prev = pother->tail;
        plist->head = pother->head;
    } 
    else 
    {
        Node* prev_node = p->prev;
        prev_node->next = pother->head;
        pother->head->prev = prev_node;
        
        pother->tail->next = p;
        p->prev = pother->tail;
    }
    
    plist->size += pother->size;
    pother->head = NULL;
    pother->tail = NULL;
    pother->size = 0;
}

void destroy(List* pl) 
{
    Node* current = pl->head;
    while (current != NULL) 
    {
        Node* next = current->next;
        free(current);
        current = next;
    }
    pl->head = NULL;
    pl->tail = NULL;
    pl->size = 0;
}

void advance(Node** pp, size_t n) 
{
    for (size_t i = 0; i < n; i++) 
    {
        if (*pp == NULL) 
        {
            break;
        }
        *pp = (*pp)->next;
    }
}