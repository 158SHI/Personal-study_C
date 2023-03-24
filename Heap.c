#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

void Swap(int* p1, int* p2)
{
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void AdjustDown(int* a, int n, int root)
{
    int parent = root;
    int child = parent * 2 + 1;
    while(child < n)
    {
        //注意对 child + 1进行检查
        if((child + 1 < n) && (a[child + 1] > a[child])) {
            child++;
        }
        
        if(a[child] > a[parent])
        {
            Swap(a + child, a + parent);
            parent = child;
            child = parent * 2 + 1;
        }
        else {
            break;
        }
    }
}

void AdjustUp(int* a, int n, int child)
{
    int parent = (child - 1) / 2;
    while (child > 0)
    {
        if(a[child] > a[parent])
        {
            Swap(a + child, a + parent);
            child = parent;
            parent = (child - 1) / 2;
        }
        else {
            break;
        }
    }
}

void HeapCreate(Heap* hp, HPDataType* a, int n)
{
    assert(hp);
    hp->a = (HPDataType*)malloc(sizeof(HPDataType) * n);
    assert(hp->a);
    hp->capacity = n;
    hp->size = n;
    for(int i = 0; i < n; i++) {
        (hp->a)[i] = a[i];
    }
    for(int i = (n - 2) / 2; i >= 0; i--) {
        AdjustDown(hp->a, n, i);
    }
}

void HeapDestory(Heap* hp)
{
    assert(hp);
    hp->size = 0;
    hp->capacity = 0;
    free(hp->a);
}

void HeapPush(Heap* hp, HPDataType x)
{
    assert(hp);
    if(hp->size == hp->capacity)
    {
        HPDataType* tmp = (HPDataType*)malloc(sizeof(HPDataType) * 2 * hp->capacity);
        if(tmp == NULL) {
            perror("HeapPush::realloc");
            return;
        }
        else {
            hp->a = tmp;
            hp->capacity *= 2;
        }
    }
    (hp->a)[hp->size++] = x;
    AdjustUp(hp->a, hp->size, hp->size - 1);
}

void HeapPop(Heap* hp)
{
    assert(hp);
    Swap(&(hp->a)[0], &(hp->a)[hp->size - 1]);
    hp->size--;
    AdjustDown(hp->a, hp->size, 0);
}

HPDataType HeapTop(Heap* hp)
{
    assert(hp);
    return (hp->a)[0];
}

int HeapSize(Heap* hp)
{
    assert(hp);
    return hp->size;
}

bool HeapEmpty(Heap* hp)
{
    assert(hp);
    return hp->size == 0;
}

void HeapSort(int* a, int n)
{
    for(int i = (n - 2) / 2; i >= 0; i--) {
        AdjustDown(a, n, i);
    }
    int end = n - 1;
    while (end >= 0)
    {
        Swap(a, a + end);
        AdjustDown(a, end, 0);
        end--;
    }
}
