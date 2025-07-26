#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 100

typedef struct SqList
{
		int length;
		int data[MAXSIZE];
};

SqList* InitList()
{
		SqList* list = (SqList*)malloc(sizeof(SqList));
		list->length = 0;
		return list;
}

bool IsEmpty(SqList* sqlist)
{
		if (sqlist->length == 0)
		{
				return true;
		}
		else
		{
				return false;
		}
}

bool Append(SqList * sqlist, int data)
{
		if (sqlist->length > MAXSIZE || sqlist->length == MAXSIZE)
		{
				return false;
		}
		else
		{
				sqlist->data[sqlist->length] = data;
				sqlist->length++;
				return true;
		}
}

void PrintTable(SqList * sqlist)
{
		for (int i = 1; i < sqlist->length+1; i++)
		{
				printf("%5d", sqlist->data[i-1]);
				if (i % 10 == 0 && i!=0)
				{
						printf("\n");
				}
		}
}

bool Insert(SqList *sqlist, int PhysicalPosition, int data)
{
		if (PhysicalPosition<0 || PhysicalPosition>MAXSIZE || sqlist->length > MAXSIZE)
		{
				return false;
		}
		else
		{
				for (int i = sqlist->length; i > PhysicalPosition; i--)
				{
						sqlist->data[i] = sqlist->data[i-1];
				}
				sqlist->data[PhysicalPosition] = data;
				sqlist->length++;
				return true;
		}
}

bool DeleteAsPosition(SqList *sqlist, int PhysicalPosition)
{
		if (PhysicalPosition<0 || PhysicalPosition>sqlist->length-1)
		{
				return false;
		}
		else
		{
				for (int i = PhysicalPosition; i < sqlist->length; i++)
				{
						sqlist->data[i] = sqlist->data[i + 1];
				}
				sqlist->length--;
				return true;
		}
}

bool DeleteFirstAimedElement(SqList *sqlist, int data)
{
		for (int i = 0; i < sqlist->length; i++)
		{
				if (sqlist->data[i] == data)
				{
						for (int j = i; j < sqlist->length; j++)
						{
								sqlist->data[j] = sqlist->data[j + 1];
						}
						sqlist->length--;
						return true;
				}
		}
		return false;
}

bool DeleteAllAimedElement(SqList *sqlist, int aimedData)
{
		bool result = false;
		for (int i = 0; i < sqlist->length; i++)
		{
				if (sqlist->data[i] == aimedData)
				{
						for (int j = i; j < sqlist->length; j++)
						{
								sqlist->data[j] = sqlist->data[j + 1];
						}
						sqlist->length--;
						result = true;
				}
		}
		return result;
}

void SetUp(SqList *sqlist)
{ 
		char beginning = 'y';
		printf("是否要初始化一个长度为25的顺序表 y / n  ?:\n");
		scanf("%c", &beginning);
		if (beginning=='y')
		{
				for (int i = 0; i < 25; i++)
				{
						sqlist->data[i] = i;
						sqlist->length++;
				}
		}
		printf("初始化完成\n================================\n\n");
		int commmand = -1;
		while (commmand != 0)
		{
				scanf("%d", &commmand);
				int data;
				int position = 0;
				switch (commmand)
				{
						case 1:
						{
								printf("请输入要在顺序表末尾添加的元素:\n");
								scanf("%d", &data);
								printf("执行状态:  %d\n\n",Append(sqlist, data));
								break;
						}
						case 2:
						{
								printf("正在打印列表:\n");
								PrintTable(sqlist);
								printf("\n\n");
								break;
						}
						case 3:
						{
								printf("请输入要插入的物理位置（如果表头写0）:\n");
								scanf("%d", &position);
								printf("请输入插入的数据:\n");
								scanf("%d", &data);
								Insert(sqlist, position, data);
								printf("\n\n");
								break;
						}
						case 4:
						{
								printf("请输入要删除的元素的物理位置:\n");
								scanf("%d", &position);
								DeleteAsPosition(sqlist, position);
								break;
						}
						case 5:
						{
								printf("请输入要删除的数据，方法将会删除第一个value的元素:\n");
								scanf("%d", &data);
								DeleteFirstAimedElement(sqlist, data);
								printf("\n\n");
								break;
						}
						case 6:
						{
								printf("请输入要删除的数据，方法将会删除所有value的元素:\n");
								scanf("%d", &data);
								DeleteAllAimedElement(sqlist, data);
								printf("\n\n");
								break;
								break;
						}
						case 0:
						{
								if (IsEmpty(sqlist))
								{
										printf("列表为空.\n\n");
								}
								else
								{
										printf("列表不为空.\n\n");
								}
								break;
						}
						case 7:
						{

						}
						default:
						{
								printf("请参考提示输入有效数字!\n\n");
								break;
						}
				}
		}
}

int main()
{
		SqList* sqlist = NULL;
		sqlist = InitList();
		SetUp(sqlist);
		return 0;
}