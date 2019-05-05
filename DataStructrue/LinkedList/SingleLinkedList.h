//
//  SingleLinkedList.h
//  LinkedList 单链表实现
//
//  Created by 陈良静 on 2019/3/11.
//  Copyright © 2019 陈良静. All rights reserved.
//

#ifndef SingleLinkedList_h
#define SingleLinkedList_h

#include <stdio.h>
#include <stdbool.h>

typedef struct _node {
    int value; // 数据域
    struct _node *next; // 指针域
} Node;

typedef struct _list {
    Node *head; // 头指针
    Node *tail; // 尾指针
    int length; // 链表的长度
} SingleList;

// 创建链表
SingleList * creatList(void);
// 释放链表
void freeList(SingleList *pList);

// 给链表末尾添加一个结点
void appendNode(SingleList *pList, int value);
// 删除末尾结点
void removeLastNode(SingleList *pList);

// 在指定位置插入一个结点
void insertNodeAtIndex(SingleList *pList, int index, int value);
// 在指定位置删除一个结点
void deleteNodeAtIndex(SingleList *pList, int index);

// 打印链表中所有结点值
void printList(SingleList *pList);


// 求中间节点
Node *getMiddleNode(SingleList *pList);

// 翻转链表
// 输入：1->2->3->4->null
// 输出：4->3->2->1->null
void reverseList(SingleList *pList);

// 判断是否回文串
bool isPalindrome(SingleList *pList);

// 两两交换相邻的结点
void swapNodesInPairs(SingleList *pList);

#endif /* SingleLinkedList_h */
