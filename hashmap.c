#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "log.h"
#include "hashmap.h"

size_t hash_func_default(key_type key)
{
    return key % HASH_MAP_SIZE;
}

void hash_table_init(hash_table_t *map)
{
    if (map == NULL)
    {
        return;
    }
    map->size = 0;
    map->hashfunc = hash_func_default;
    for (size_t i = 0; i < HASH_MAP_SIZE; i++)
    {
        map->data[i].key = 0;
        map->data[i].stat = EMPTY;
        map->data[i].value = 0;
    }
}

int hash_table_insert(hash_table_t *map, key_type key, value_type value)
{
    if (map == NULL)
    {
        return 0;
    }
    if (map->size >= HASH_MAP_SIZE * LOAD_FACTOR)
    {
        return 0;
    }
    size_t cur = map->hashfunc(key);
    while (1)
    {
        if (map->data[cur].key == key)
        {
            return 0;
        }
        if (map->data[cur].stat != VALID)
        {
            map->data[cur].key = key;
            map->data[cur].value = value;
            map->data[cur].stat = VALID;
            map->size++;
            return 1;
        }
        cur++;
    }
}

int hash_table_find(hash_table_t *map, key_type key, value_type *values)
{
    if (map == NULL)
    {
        return 0;
    }
    size_t offset = map->hashfunc(key);
    if (map->data[offset].key == key && map->data[offset].stat == VALID)
    {
        *values = map->data[offset].value;
        return 1;
    }
    else
    {
        while (map->data[offset].stat != EMPTY)
        {
            if (map->data[offset].key != key)
            {
                offset++;
                if (offset >= HASH_MAP_SIZE)
                {
                    offset = 0;
                }
                else
                {
                    if (map->data[offset].stat == VALID)
                    {
                        *values = map->data[offset].value;
                        return 1;
                    }
                    else
                    {
                        offset++;
                    }
                }
            }
        }
        return 0;
    }
}

int hash_table_find_cur(hash_table_t *map, key_type key, size_t *cur)
{
    if (map == NULL)
    {
        return 0;
    }
    for (size_t i = 0; i < HASH_MAP_SIZE; i++)
    {
        if (map->data[i].key == key && map->data[i].stat == VALID)
        {
            *cur = i;
            return 1;
        }
    }
    return 0;
}

void hash_table_remove(hash_table_t *map, key_type key)
{
    if (map == NULL)
    {
        return;
    }
    value_type value = 0;
    size_t cur = 0;
    int ret = hash_table_find_cur(map, key, &cur);
    if (ret == 0)
    {
        return;
    }
    else
    {
        map->data[cur].stat = INVALID;
        map->size--;
    }
}

size_t hash_table_size(hash_table_t *map)
{
    if (map == NULL)
    {
        return 0;
    }
    return map->size;
}

void print_hashtable(hash_table_t *map, const char *msg)
{
    if (map == NULL || map->size == 0)
    {
        return;
    }
    DEBUG("%s", msg);
    for (size_t i = 0; i < HASH_MAP_SIZE; i++)
    {
        if (map->data[i].stat != EMPTY)
        {
            DEBUG("[%d]  key=%d  value=%d,  stat=%d",i, map->data[i].key, map->data[i].value,
                   map->data[i].stat);
        }
    }
}

void hashmap_main()
{
    hash_table_t map;
    hash_table_t *p_map;
    p_map=&map;
    hash_table_init(p_map);
    hash_table_insert(p_map,1,1);
    hash_table_insert(p_map,2,2);
    hash_table_insert(p_map,34,1);
    DEBUG("The hash size :%d",hash_table_size(p_map));
    print_hashtable(p_map,"------------------------HASH_TABLE__________________________");
}