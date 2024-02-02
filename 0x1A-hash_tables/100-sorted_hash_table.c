#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * shash_table_create - Create a sorted hash table
 * @size: The size of the array
 *
 * Return: A pointer to the created hash table, or NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *ht;
    unsigned long int i;

    ht = malloc(sizeof(shash_table_t));
    if (ht == NULL)
        return (NULL);

    ht->size = size;
    ht->array = malloc(sizeof(shash_node_t *) * size);
    if (ht->array == NULL)
    {
        free(ht);
        return (NULL);
    }

    for (i = 0; i < size; i++)
        ht->array[i] = NULL;

    ht->shead = NULL;
    ht->stail = NULL;

    return (ht);
}

/**
 * shash_table_set - Set a key/value pair in the sorted hash table
 * @ht: The sorted hash table
 * @key: The key string
 * @value: The value corresponding to the key
 *
 * Return: 1 on success, 0 on failure
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;
    shash_node_t *new_node, *current;

    if (ht == NULL || key == NULL || value == NULL)
        return (0);

    index = key_index((const unsigned char *)key, ht->size);

    current = ht->array[index];
    while (current)
    {
        if (strcmp(current->key, key) == 0)
        {
            free(current->value);
            current->value = strdup(value);
            if (current->value == NULL)
                return (0);
            return (1);
        }
        current = current->next;
    }

    new_node = malloc(sizeof(shash_node_t));
    if (new_node == NULL)
        return (0);

    new_node->key = strdup(key);
    if (new_node->key == NULL)
    {
        free(new_node);
        return (0);
    }

    new_node->value = strdup(value);
    if (new_node->value == NULL)
    {
        free(new_node->key);
        free(new_node);
        return (0);
    }

    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    /* Insert into the sorted linked list */
    if (insert_sorted_list(ht, new_node) == 0)
    {
        free(new_node->key);
        free(new_node->value);
        free(new_node);
        return (0);
    }

    return (1);
}

/**
 * insert_sorted_list - Insert a node into the sorted linked list
 * @ht: The sorted hash table
 * @new_node: The new node to insert
 *
 * Return: 1 on success, 0 on failure
 */
int insert_sorted_list(shash_table_t *ht, shash_node_t *new_node)
{
    shash_node_t *current;

    if (ht == NULL || new_node == NULL)
        return (0);

    if (ht->shead == NULL)
    {
        ht->shead = new_node;
        ht->stail = new_node;
        new_node->sprev = NULL;
        new_node->snext = NULL;
        return (1);
    }

    current = ht->shead;
    while (current)
    {
        if (strcmp(new_node->key, current->key) < 0)
        {
            new_node->sprev = current->sprev;
            new_node->snext = current;
            if (current->sprev)
                current->sprev->snext = new_node;
            else
                ht->shead = new_node;
            current->sprev = new_node;
            return (1);
        }
        current = current->snext;
    }

    ht->stail->snext = new_node;
    new_node->sprev = ht->stail;
    new_node->snext = NULL;
    ht->stail = new_node;

    return (1);
}

/**
 * shash_table_get - Get the value associated with a key in the sorted hash table
 * @ht: The sorted hash table
 * @key: The key string
 *
 * Return: The value associated with the key, or NULL if key not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
    unsigned long int index;
    shash_node_t *current;

    if (ht == NULL || key == NULL)
        return (NULL);

    index = key_index((const unsigned char *)key, ht->size);

    current = ht->array[index];
    while (current)
    {
        if (strcmp(current->key, key) == 0)
            return (current->value);
        current = current->next;
    }

    return (NULL);
}

/**
 * shash_table_print - Print the sorted hash table using the sorted linked list
 * @ht: The sorted hash table
 */
void shash_table_print(const shash_table_t *ht)
{
    shash_node_t *current;

    if (ht == NULL)
        return;

    current = ht->shead;
    printf("{");
    while (current)
    {
        printf("'%s': '%s'", current->key, current->value);
        current = current->snext;
        if (current)
            printf(", ");
    }
    printf("}\n");
}

/**
 * shash_table_print_rev - Print the sorted hash table in reverse order
 * using the sorted linked list
 * @ht: The sorted hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
    shash_node_t *current;

    if (ht == NULL)
        return;

    current = ht->stail;
    printf("{");
    while (current)
    {
        printf("'%s': '%s'", current->key, current->value);
        current = current->sprev;
        if (current)
            printf(", ");
    }
    printf("}\n");
}

/**
 * shash_table_delete - Delete the sorted hash table
 * @ht: The sorted hash table
 */
void shash_table_delete(shash_table_t *ht)
{
    unsigned long int i;
    shash_node_t *current, *temp;

    if (ht == NULL)
        return;

    for (i = 0; i < ht->size; i++)
    {
        current = ht->array[i];
        while (current)
        {
            temp = current;
            current = current->next;
            free(temp->key);
            free(temp->value);
            free(temp);
        }
    }

    free(ht->array);
    free(ht);
}

