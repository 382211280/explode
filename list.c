#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "log.h"
void insert_list(llink *head, int custom_data)
{
    llink node = malloc(sizeof(struct List));
    if (!node)
    {
        fprintf(stderr, " malloc error\n");
        return;
    }
    node->vertex = custom_data;
    node->next = NULL;
    if (!*head)
    {
        *head = node;
        return;
    }
    llink cur = *head;
    while (cur->next)
    {
        cur = cur->next;
    }
    cur->next = node;
}
void print_list(llink head)
{
    char str[100] = {0};
    int len = 0;
    len = snprintf(str, 11, "list info:");
    while (head)
    {
        len += snprintf(str+len, sizeof(head->vertex), "%d\t", head->vertex);
        head = head->next;
    }
    snprintf(str+len, 3, "");
    DEBUG("%s", str);
}
void destroy_list(llink head)
{
    while (head)
    {
        head = head->next;
        free(head);
        head = NULL;
    }
}
