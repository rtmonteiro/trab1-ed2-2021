#ifndef UF_H
#define UF_H

#include <stdbool.h>
typedef struct uf UF;

UF* unionFindInit (int N);

int getID (UF *id, int i);

void putID (UF* id, int i, int j);

int getSize (UF* id, int i);

void increaseSize (UF* id, int i, int j);

int getRoot (UF *id, int i);

bool connected (UF* id, int p, int q);

void createUnion (UF* id, int p, int q);

bool allObjectsConnected (UF* id); 

void showUnionFind (UF* id);

void freeUnionFind(UF* id);

#endif