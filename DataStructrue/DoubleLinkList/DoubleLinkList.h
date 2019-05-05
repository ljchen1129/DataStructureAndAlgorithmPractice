//
//  DoubleLinkList.h
//  DataStructrue
//  双向链表
//  Created by 陈良静 on 2019/5/5.
//  Copyright © 2019 陈良静. All rights reserved.
//

#ifndef DoubleLinkList_h
#define DoubleLinkList_h

#include <stdio.h>

typedef struct listNode {
    int value;
    struct listNode *next;
    struct listNode *prev;
}ListNode;

// 创建链表
ListNode * creatList(void);
// 释放链表
void freeList(ListNode *head);

// 链表长度
int listLength(ListNode *head);
// 末尾添加结点
void appendNode(ListNode *head, int value);

// 指定位置插入结点
void insertNodeAtIndex(ListNode *head, int index, int value);
// 指定位置删除结点
void deleteNodeAtIndex(ListNode *head, int index);

// 打印链表
void printList(ListNode *head);

#endif /* DoubleLinkList_h */
