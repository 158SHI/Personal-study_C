#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int StackDataType;

typedef struct Stack
{
	StackDataType* data;
	int capacity;
	int top;
}Stack;

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

void StackInit(Stack* ps)
{
	assert(ps);
	ps->data = (StackDataType*)malloc(sizeof(StackDataType) * 20);
	assert(ps->data);
	ps->capacity = 20;
	ps->top = 0;
}

void StackDestory(Stack* ps)
{
	assert(ps);
	free(ps->data);
	ps->data = NULL;
	ps->capacity = 0;
	ps->top = 0;
}

bool StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == 0;
}

void StackPush(Stack* ps, StackDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		StackDataType* tmp = NULL;
		tmp = (StackDataType*)realloc(ps->data,
			sizeof(StackDataType) * (2 * ps->capacity));
		if (tmp != NULL) {
			ps->data = tmp;
			ps->capacity *= 2;
		}
		else {
			perror("StackPush::realloc");
		}
	}
	(ps->data)[ps->top] = x;
	ps->top++;
}

void StackPop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->top--;
}

int StackSize(Stack* ps)
{
	return ps->top;
}

StackDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return (ps->data)[ps->top - 1];
}

/*-----------------------------------------*/

bool InOrderAndJudge(struct TreeNode* root, Stack* sT)
{
	if (root == NULL) {
		return true;
	}

	bool ret1 = InOrderAndJudge(root->left, sT);
	if (!ret1) {
		return false;
	}

	if (!StackEmpty(sT) && StackTop(sT) >= root->val) {
		return false;
	}
	StackPush(sT, root->val);

	bool ret2 = InOrderAndJudge(root->right, sT);
	if (!ret2) {
		return false;
	}
	return true;
}

bool isValidBST(struct TreeNode* root)
{
	Stack sT;
	StackInit(&sT);
	return InOrderAndJudge(root, &sT);
}