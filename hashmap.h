#ifndef HASHMAP_H
#define HASHMAP_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#define HASH_MAP_SIZE 1000
#define LOAD_FACTOR 0.8

typedef uint64_t key_type;
typedef uint64_t value_type;
typedef size_t (*hash_func)(key_type key);
typedef enum stat_e
{
    EMPTY,
    VALID,
    INVALID
} state;

typedef struct hash_elem_s
{
    key_type key;
    value_type value;
    state stat;
} hash_elem_t;

typedef struct hash_table_s
{
    hash_elem_t data[HASH_MAP_SIZE];
    size_t size;
    hash_func hashfunc;
} hash_table_t;

void hash_table_init(hash_table_t *map);
int hash_table_insert(hash_table_t *map, key_type key,value_type value);
int hash_table_find(hash_table_t* map,key_type key,value_type* values);
void hash_table_remove(hash_table_t *map,key_type key);
bool hash_table_empty(hash_table_t *map);
size_t hash_table_size(hash_table_t *map);
void hash_destroy(hash_table_t *map);
void print_hashtable(hash_table_t *map,const char* msg);
void hashmap_main();
#endif // HASHMAP_H