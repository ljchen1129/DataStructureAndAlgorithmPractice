//
//  main.c
//  线性表_链表实现
//
//  Created by 陈良静 on 2017/5/27.
//  Copyright © 2017年 陈良静. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int Data; // 数据域
    struct Node *Next; // 指针域，指向下一个节点
}List;

// 1. 求表长
int Length(List *PtrL)
{
    List *p = PtrL; // p 指向表的第一个元素地址
    int j = 0; // 用来记录表元素的个数
    // 循环终止条件：P 为 null 了
    while (p)
    {
        p = p->Next;
        j++;
    }
    
    return j;
}

// 2. 查找(按序号查找)
List * FindKth(int K, List *PtrL)
{
    List *p = PtrL;
    int i = 1;
    while (p != NULL && i < K)
    {
        p = p->Next;
        i++;
    }
    
    if (i == K)
    {
        return p; // 找到第 K 个，返回指针
    }
    else
    {
       return NULL; // 没找到，返回 NULL
    }
}

// 2. 查找(按值查找)
List * Find(int X, List *PtrL)
{
    List *p = PtrL;
    // 循环终止条件：p = NULL，或者 p->Data = X
    while (p != NULL && p->Data != X)
    {
        p = p->Next;
    }
    
    return p;
}

// 3. 插入元素(在第 i-1(i <= i <= n +1) 个节点后插入一个值为 X 的新节点)
// 先构造一个新节点，用 s 指向
// 再找到第 i-1 个节点，用 p 指向
// 然后修改指针，插入节点（p 之后插入新节点是 s）

List * Insert(int X, int i, List *Ptrl)
{
    List *p, *s;
    // 如果插入的是表头
    if (i == 1)
    {
        s = (List *)malloc(sizeof(List));
        s->Data = X;
        s->Next = Ptrl;
        
        return s;
    }
    p = FindKth(i - 1, Ptrl);
    if (p == NULL)
    {
        printf("参数 i 错误！");
        return NULL;
    }
    else
    {
        // 把新节点插入到第 i-1 个节点的后面
        s = (List *)malloc(sizeof(List));
        s->Data = X;
        s->Next = p->Next;
        p->Next = s;
        
        return Ptrl;
    }
}



// 4. 删除元素(删除链表第 i (1 <= i <= n) 个位置的节点)
// 先找到链表第 i-1 个节点，用 p 指向
// 在用指针 s 指向要删除的节点（p 的下一各节点）
// 然后修改指针，删除 s 所指的节点
// 最后释放 s 所指节点的空间
List * Delete(int i, List *PtrL)
{
    List *p, *s;
    // 如果删除的是表头节点
    if (i == 1)
    {
        s = PtrL; // s 指向第一个节点
        if (PtrL != NULL)
        {
            PtrL = PtrL->Next; // 从链表中删除
            free(s);
            
            return PtrL;
        }
        else
        {
            return NULL;
        }
    }
    
    p = FindKth(i - 1, PtrL); // 查找第 i -1 个节点
    if (p == NULL)
    {
        printf("第%d个节点不存在", i -1);
        return NULL;
    }
    else if (p->Next == NULL)
    {
        printf("第%d个节点不存在", i);
        return NULL;
    }
    else
    {
        s = p->Next; // s 指向第 i 个节点
        p->Next = s->Next; // 从聊表中删除第 i 个节点
        free(s); // 释放被删除的节点
        
        return PtrL; // 返回新的链表
    }
}

int main(int argc, const char * argv[]) {

    // 1. 创建表
    List *L = NULL;
    
    // 2. 插入元素
    printf("开始插入元素\n");
    L = Insert(10, 1, L);
    L = Insert(20, 2, L);
    L = Insert(5, 3, L);
    L = Insert(30, 4, L);
    printf("结束插入元素\n");
    
    // 3. 求表长度
    int length = Length(L);
    printf("表的长度 = %d\n", length);
    
    for (int i = 1; i <= length; i++)
    {
        // 4. 按序号查找节点
        List *findL = FindKth(i, L);
        printf("第 %d 位的元素 = %d\n",  i, findL->Data);
    }
    
    // 4. 按元素值查找节点
    List *xL = Find(5, L);
    printf("元素为 5 的节点的元素值 = %d\n", xL->Data);

    // 5. 删除节点
    printf("删除节点\n");
    L = Delete(1, L);
    length = Length(L);
    for (int i = 1; i <= length; i++)
    {
        // 按序号查找节点
        List *findL = FindKth(i, L);
        printf("删除后：第 %d 位的元素 = %d\n",  i, findL->Data);
    }

    printf("删除节点\n");
    L = Delete(2, L);
    length = Length(L);
    for (int i = 1; i <= length; i++)
    {
        // 按序号查找节点
        List *findL = FindKth(i, L);
        printf("删除后：第 %d 位的元素 = %d\n",  i, findL->Data);
    }

    return 0;
}
