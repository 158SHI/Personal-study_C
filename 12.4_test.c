#define _CRT_SECURE_NO_WARNINGS 1

typedef struct S
{
	int data;
	struct S* next;
}S;

int main()
{
	S s;
	return 0;
}