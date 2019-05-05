//
//  CycleLinkedList.h
//  LinkedList 循环链表
//
//  Created by 陈良静 on 2019/3/12.
//  Copyright © 2019 陈良静. All rights reserved.
//

#ifndef CycleLinkedList_h
#define CycleLinkedList_h

#include <stdio.h>

typedef struct _node {
    int value;
    struct _node *next;
}Node;

typedef struct _cycleList {
    Node *head; // 头指针，哨兵结点，不存储数据
}CycleList;


// 创建链表
CycleList * creatList(void);
// 释放链表
void freeList(CycleList *pList);

// 返回链表的长度
int listLength(CycleList *pList);

// 给链表末尾添加一个结点
void appendNode(CycleList *pList, int value);
// 删除末尾结点
void removeLastNode(CycleList *pList);

// 在指定位置插入一个结点
void insertNodeAtIndex(CycleList *pList, int index, int value);
// 在指定位置删除一个结点
void deleteNodeAtIndex(CycleList *pList, int index);


// 打印链表中所有结点值
void printList(CycleList *pList);


#endif /* CycleLinkedList_h */
