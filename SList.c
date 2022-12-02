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
	Slist* newnode = BuyNode(x);//���������ݵ��½ڵ�
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
		//��β�ڵ�
		Slist* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		tail->next = newnode;//���ӽڵ�

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
	//ͷ�岻��Ҫ�޽ڵ���нڵ�ֿ�����
	Slist* newnode = BuyNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

void SlistPopFront(Slist** pphead)
{
	//ͷɾ����Ҫ���ڵ�Ͷ�ڵ�ֿ�����
	if (*pphead == NULL)//������
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
	if (*pphead == NULL)//������
	{
		printf("NULL\n");
		return;
	}
	else if ((*pphead)->next == NULL)//ֻ��һ���ڵ�
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
	if (cur == ins)//�ڵ�һ���ڵ�֮ǰ����
	{
		SlistPushFront(pphead, ins_num);
	}
	else
	{
		while (cur->next != ins)//Ѱ��Ŀ��ڵ�
		{
			cur = cur->next;
		}

		Slist* newnode = BuyNode(ins_num);

		//����
		cur->next = newnode;
		newnode->next = ins;
	}
}

void SlistDelet(Slist** pphead, Slist* pos)
{
	
	Slist* pre = *pphead;
	if (pos == pre)//ɾ����һ���ڵ�
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

	//�ͷ��м�ڵ��β�ڵ�
	while (head->next != NULL)
	{
		p = head->next;
		head->next = p->next;
		free(p);
		p = NULL;
	}

	free(head);//�ͷ�ͷ���
	head = NULL;
}