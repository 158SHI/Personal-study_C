#include "Heap.h"

void PrintTest(HPDataType* a, int n)
{
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void HeapTest1(void)
{
    Heap newHp;
    int arr[] = { 2, 3, 5, 7, -13, -17, 19 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    HeapCreate(&newHp, arr, sz);
    PrintTest(newHp.a, newHp.size);
    
    HeapPush(&newHp, 20);
    PrintTest(newHp.a, newHp.size);
    
    HeapPush(&newHp, 21);
    PrintTest(newHp.a, newHp.size);
    
    HeapPop(&newHp);
    PrintTest(newHp.a, newHp.size);
    
    HeapPop(&newHp);
    PrintTest(newHp.a, newHp.size);
    
    HeapDestory(&newHp);
}

void HeapTest2(void)
{
    Heap newHp;
    int arr[] = { 2, 3, 5, 7, -13, -17, 19 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    HeapCreate(&newHp, arr, sz);
    
    //PrintTest(newHp.a, newHp.size);
    
    int k = 5;
    while(!HeapEmpty(&newHp) && (k--))
    {
        printf("%d ", HeapTop(&newHp));
        HeapPop(&newHp);
    }
    printf("\n");
    
    HeapDestory(&newHp);
}

void HeapSortTest(void)
{
    int arr[] = { 2, 3, 5, 7, -13, -17, 19, 11 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    
    HeapSort(arr, sz);
    PrintTest(arr, sz);
}

int main()
{
    //HeapTest1();
    //HeapTest2();
    HeapSortTest();
    return 0;
}
