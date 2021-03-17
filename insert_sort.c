#include <stdio.h>
#include "item.h"


extern void sort(Item *a, int lo, int hi){
    for (int i = lo; i < hi; i++)
    {
        for (int j = i; j > lo && a[j] < a[j-1]; j--)
        {
            exch(a[j], a[j-1]);
        }   
    }
}