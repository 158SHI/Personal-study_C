#define _CRT_SECURE_NO_WARNINGS 1

#include"SList.h"

//int c_count = 0;

static Slist* BuyNode(SLDtype x)
{
	Slist* newnode = (Slist*)malloc(sizeof(Slist));
	if (newnode == NULL)
	{
		printf("Creat a newnode:%s\n", strerror(errno));
		return NULL;
	}

	newnode->next = NULL;
	newnode->data = x;
	//newnode->count = ++c_count;

	return newnode;
}

void SlistPushBack(Slist** pphead, SLDtype x)
{
	Slist* newnode = BuyNode(x);//创建含数据的新节点
	if (*pphead == NULL)
	{
		*pphead = (Slist*)malloc(sizeof(Slist));
		if (*pphead == NULL)
		{
			return;
		}
		*pphead = newnode;

	}
	else
	{
		//找尾节点
		Slist* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		tail->next = newnode;//链接节点

	}
}

void SlistPrint(const Slist** pphead)
{
	Slist* cur = *pphead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void SlistPushFront(Slist** pphead, SLDtype x)
{
	//头插不需要无节点和有节点分开进行
	Slist* newnode = BuyNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

void SlistPopFront(Slist** pphead)
{
	//头删不需要单节点和多节点分开进行
	if (*pphead == NULL)//空链表
	{
		printf("NULL\n");
		return;
	}
	else
	{
		Slist* next = (*pphead)->next;
		free(*pphead);
		*pphead = next;
	}
}

void SlistPopBack(Slist** pphead)
{
	if (*pphead == NULL)//空链表
	{
		printf("NULL\n");
		return;
	}
	else if ((*pphead)->next == NULL)//只有一个节点
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		Slist* pre = NULL;
		Slist* tail = *pphead;
		while (tail->next != NULL)
		{
			pre = tail;
			tail = tail->next;
		}
		free(tail);
		pre->next = NULL;
	}
}

Slist* SlistSearch(const Slist** pphead, const SLDtype aim)
{
	Slist* cur = *pphead;
	while (cur != NULL)
	{
		if (cur->data == aim)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void SlistInsert(Slist** pphead, Slist* ins, SLDtype ins_num)
{
	Slist* cur = *pphead;
	if (cur == ins)//在第一个节点之前插入
	{
		SlistPushFront(pphead, ins_num);
	}
	else
	{
		while (cur->next != ins)//寻找目标节点
		{
			cur = cur->next;
		}

		Slist* newnode = BuyNode(ins_num);

		//链接
		cur->next = newnode;
		newnode->next = ins;
	}
}

void SlistDelet(Slist** pphead, Slist* pos)
{
	
	Slist* pre = *pphead;
	if (pos == pre)//删除第一个节点
	{
		SlistPopFront(pphead);
	}
	else
	{
		while (pre->next != pos)
		{
			pre = pre->next;
		}

		pre->next = pos->next;
		free(pos);
	}
}

void SlistDestory(Slist** pphead)
{
	Slist* head = *pphead;
	Slist* p = NULL;

	//释放中间节点和尾节点
	while (head->next != NULL)
	{
		p = head->next;
		head->next = p->next;
		free(p);
		p = NULL;
	}

	free(head);//释放头结点
	head = NULL;
}