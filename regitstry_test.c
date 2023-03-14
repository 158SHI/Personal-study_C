#define _CRT_SECURE_NO_WARNINGS 1

#include"registry.h"

int main()
{
	registry* newRegistry = CreatRegistry(4, 5);
//    coordinate coor = {2, 3};
//    RegistryInsert(newRegistry, &coor);
    coordinate coor = { 2, 3 };
    RegistryPush(newRegistry, &coor);
    
    coor.C = 3;
    coor.S = 2;
    RegistryPush(newRegistry, &coor);
	return 0;
}
