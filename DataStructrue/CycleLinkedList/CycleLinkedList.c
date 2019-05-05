//
//  CycleLinkedList.c
//  LinkedList
//
//  Created by 陈良静 on 2019/3/12.
//  Copyright © 2019 陈良静. All rights reserved.
//

#include "CycleLinkedList.h"
#include <stdlib.h>

// 创建链表，至少有一个结点
CycleList * creatList(void)
{
    CycleList *pList = (CycleList *)malloc(sizeof(CycleList));
    Node *head = (Node *)malloc(sizeof(Node));
    // 自己的 next 指针指向自己
    head->next = head;
    pList->head = head;

    return pList;
}

// 释放链表
void freeList(CycleList *pList)
{
    Node *p = pList->head;
    // 用指针 q 来保存上一次的 p 指针
    Node *q = NULL;
    
    while (p->next != pList->head) {
        q = p;
        p = p->next;
        free(q);
    }
    
    free(pList);
}

// 给链表末尾添加一个结点
void appendNode(CycleList *pList, int value)
{
    Node *s = (Node *)malloc(sizeof(Node));
    s->value = value;
    s->next = NULL;

    Node *p = pList->head;
    while (p->next != pList->head) {
        p = p->next;
    }
    
    p->next = s;
    s->next = pList->head;
}


// 在指定位置插入一个结点
void insertNodeAtIndex(CycleList *pList, int index, int value)
{
    int length = listLength(pList);
    if (index < 0 || index > length) {
        printf("下标不合法!!!!");
        return;
    }
    
    // 在末尾插入
    if (index == length) {
        appendNode(pList, value);
        return;
    }
    
    // 在中间插入
    Node *p = pList->head;
    int i = 0;
    while (p->next != pList->head) {
        if (i == index) {
            // 插入结点
            Node *s = (Node *)malloc(sizeof(Node));
            
            s->value = value;
            s->next = p->next;
            p->next = s;
        }
        p = p->next;
        i++;
    }
}


// 在指定位置删除一个结点
void deleteNodeAtIndex(CycleList *pList, int index)
{
    int length = listLength(pList);
    if (index < 0 || index >= length) {
        printf("下标不合法!!!!");
        return;
    }
    
    Node *p = pList->head;
    int i = 0;
    while (p->next != pList->head) {
        if (i == index) {
            if (index == length - 1) {
                // 在末尾删除
                Node *q = p->next;
                p->next = pList->head;
                free(q);
                return;
            } else {
                // 在中间删除
                Node *q = p->next;
                p->next = p->next->next;
                free(q);
            }
        }
  
        p = p->next;
        i++;
    }
}

// 返回链表的长度
int listLength(CycleList *pList)
{
    Node *p = pList->head;
    int length = 0;
    while (p->next != pList->head) {
        p = p->next;
        length ++;
    }

    // 还要加上尾结点
    return length;
}

// 打印链表中所有结点值
void printList(CycleList *pList)
{
    Node *p = pList->head;
    while (p->next != pList->head) {
        p = p->next;
        printf("%d\n", p->value);
    }
}

