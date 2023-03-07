#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//int main()
//{
//	srand((unsigned int)time(NULL));
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", rand() % 1);
//	}
//	printf("\n");
//	return 0;
//}

struct ListNode
{
    int val;
    struct ListNode* next;    
};

typedef struct
{
    struct ListNode* head;
} Solution;


Solution* solutionCreate(struct ListNode* head)
{
    Solution* newSolution = (Solution*)malloc(sizeof(Solution));
    assert(newSolution);
    newSolution->head = head;
    return newSolution;
}

//水塘抽样
int solutionGetRandom(Solution* obj)
{
    int num = 1;
    int ans = 0;
    struct ListNode* cur = obj->head;
    while (cur)
    {
        //随机选择[0, num)中的一个整数
        if (rand() % num == 0) {
            ans = cur->val;
        }
        cur = cur->next;
        num++;
    }
    return ans;
}

void solutionFree(Solution* obj)
{
    free(obj->head);
    free(obj);
}

int main()
{

    return 0;
}