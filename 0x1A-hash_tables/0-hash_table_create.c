#include "hash_tables.h"
/**
 * hash_table_create - create a hash table
 * @size: Table size
 * Return: success
 */
hash_table_t *hash_table_create(unsigned long int size)
{
hash_table_t *table;
table = malloc(sizeof(hash_table_t));
if (table == NULL)
return (NULL);
table->size = size;
table->array = malloc(sizeof(table->array) * size);
if (table->array == NULL)
return (NULL);
return (table);
}
