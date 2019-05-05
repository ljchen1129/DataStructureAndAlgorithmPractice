//
//  DoubleLinkList.c
//  DataStructrue
//
//  Created by 陈良静 on 2019/5/5.
//  Copyright © 2019 陈良静. All rights reserved.
//

#include "DoubleLinkList.h"
#include <stdlib.h>

// 创建链表
ListNode * creatList(void)
{
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    head->next = NULL;
    head->prev = NULL;
    
    return head;
}

// 释放链表
void freeList(ListNode *head)
{
    ListNode *p = head;
    ListNode *q = NULL;
    while (p) {
        q = p;
        p = p->next;
        free(q);
    }
    
    head->next = NULL;
    head->prev = NULL;
}

// 链表长度
int listLength(ListNode *head)
{
    ListNode *p = head;
    int length = 0;
    while (p && p->next) {
        p = p->next;
        length ++;
    }
    
    return length;
}

// 末尾添加结点
void appendNode(ListNode *head, int value)
{
    ListNode *s = (ListNode *)malloc(sizeof(ListNode));
    s->value = value;
    s->next = NULL;
    s->prev = NULL;
    
    ListNode *p = head;
    while (p && p->next) {
        p = p->next;
    }
    
    // 新结点的前驱结点指向p
    s->prev = p;
    // p结点的后继结点指向新结点
    p->next = s;
}

// 指定位置插入结点
void insertNodeAtIndex(ListNode *head, int index, int value)
{
    int length = listLength(head);
    if (index < 0 || index > length) {
        printf("下表不合法！！！\n");
        return;
    }
    
    // 在末尾插入
    if (index == length) {
        appendNode(head, value);
        return;
    }
    
    // 在中间插入
    ListNode *p = head;
    int i = 0;
    while (p && p->next) {
        if (index == i) {
            // 插入结点
            ListNode *s = (ListNode *)malloc(sizeof(ListNode));
            s->value = value;
            // 新结点的前驱结点为上一个结点
            s->prev = p;
            // 新结点的下一个结点的前驱结点为新结点
            p->next->prev = s;
            // 新结点的后继结点为p的下一个结点
            s->next = p->next;
            // p 结点的后继结点为s
            p->next = s;
        }
        
        p = p->next;
        i++;
    }
}

// 指定位置删除结点
void deleteNodeAtIndex(ListNode *head, int index)
{
    int length = listLength(head);
    if (index < 0 || index >= length) {
        printf("下表不合法！！！\n");
        return;
    }
    
    ListNode *p = head;
    ListNode *q = NULL;
    int i = 0;
    while (p && p->next) {
        if (index == i) {
            // 保存要删除的结点
            q = p->next;
            
            if (index == length - 1) {
                // 删除最后一个结点
                // 直接让p的next指针置空
                p->next = NULL;
            } else {
                 // 删除中间结点
                // p 的下一个结点的下一个结点的前驱结点变成p
                p->next->next->prev = p;
                // p的下一个结点变成下下个结点
                p->next = p->next->next;
            }
           
            // 释放要删除的结点
            free(q);
        }
        
        p = p->next;
        i++;
    }
    
}

// 打印链表
void printList(ListNode *head)
{
    ListNode *p = head;
    while (p && p->next) {
        p = p->next;
        printf("%d\n", p->value);
    }
}
