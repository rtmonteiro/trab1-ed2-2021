#include <stdio.h>
#include "item.h"


// encontre o menor elemento do array
// trocando esse elemento pelo elemento da primeira posição.
// encontre o segundo menor elemento 
// troque-o com o elemento da segunda posição. 
// Continue dessa forma até que todo o array esteja ordenado

extern void sort(Item *a, int lo, int hi){
    int menor, j, k;

    for (int i = lo; i < hi; i++)
    {
        menor = a[i];
        k = i;
        for (j = i + 1; j < hi; j++)
        {
            if (menor > a[j])
            {
                k = j;
                menor = a[j];
            }
        } 
        compexch(a[i], a[k]);
    }
        
}