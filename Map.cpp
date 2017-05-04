#include "Map.h"

int Map::funcionHash(string key, int reHash)
{
    int suma = 0;
    for(int i=0; i<key.size(); i++)
        suma += key[i];

    return suma + reHash;
}

Map::Map()
{
    int size = 10000;
    array_key = new string[size];
    array_value = new int[size];

    for(int i=0; i<size; i++)
        array_key[i]=" ";
}

void Map::put(string key, int value)
{
    int reHash = 0;
    int pos;

    do
    {
        pos = funcionHash(key, reHash);
        reHash++;
    }while(array_key[pos]!= " " && array_key[pos] != removedFlag);

    array_key[pos] = key;
    array_value[pos] = value;
}

int Map::get(string key)
{
    int reHash = 0;
    int pos;

    do
    {
        pos = funcionHash(key, reHash);
        reHash++;
    }while(array_key[pos] != key);

    return array_value[pos];
}
int Map::getPos(string key)
{
    int reHash = 0;
    int pos;
    do
    {
        pos = funcionHash(key, reHash);
        reHash++;

    }while(array_key[pos] != key);

    return pos;
}

bool Map::exists(string key)
{
    int reHash = 0;
    int pos;
    do
    {
        pos = funcionHash(key, reHash);
        reHash++;
    }while(array_key[pos] != key && array_key[pos] != " ");

    if(key == array_key[pos])
        return true;

    return false;
}

void Map::remove(string key)
{
    if(exists(key))
    {
        int temp = getPos(key);
        array_key[temp] = "D";
        array_value[temp] = 0;
    }
}
