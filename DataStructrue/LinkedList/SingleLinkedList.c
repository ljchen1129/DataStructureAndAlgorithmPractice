//
//  SingleLinkedList.c
//  LinkedList
//
//  Created by 陈良静 on 2019/3/11.
//  Copyright © 2019 陈良静. All rights reserved.
//

#include "SingleLinkedList.h"
#include <stdlib.h>

//typedef struct _node {
//    int value; // 数据域
//    struct _node *next; // 指针域
//} Node;

SingleList * creatList(void)
{
    SingleList *pList = (SingleList *)malloc(sizeof(SingleList));
    pList->head = NULL;
    pList->tail = NULL;
    pList->length = 0;

    return pList;
}

// 释放链表
void freeList(SingleList *pList)
{
    if(pList == NULL) {
        return;
    }

    if (pList->head == NULL) {
        free(pList);
        return;
    }

    // 用 q 来保存下一个p节点
    Node *p, *q = NULL;
    for (p = pList->head; p; p = q) {
        q = p->next;
        free(p);
    }

    free(pList);
}

// 给链表末尾添加一个结点
void appendNode(SingleList *pList, int value)
{
    // 制造一个结点，加入链表中去
    Node *p = (Node *)malloc(sizeof(Node));
    p->value = value;
    p->next = NULL;

    // 如果链表为空
    if (pList->head == NULL) {
        // p 结点就是头结点，也是尾结点
        pList->head = pList->tail = p;
    } else {
        pList->tail->next = p;
        // 更新尾指针
        pList->tail = p;
    }

    pList->length += 1;
}

// 删除末尾结点
void removeLastNode(SingleList *pList)
{
    if (pList->tail == NULL) {
        // 链表为空
        printf("链表为空!!!!");
        return;
    }

    if (pList->head == pList->tail) {
        // 链表只有一个结点
        pList->head = pList->tail = NULL;
        pList->length -= 1;

        return;
    }

    // 需要先遍历的到尾结点的上一个结点，然后删除尾结点，再更新尾结点
    Node *p = pList->head;
    while (p->next != pList->tail) {
        p = p->next;
    }

    // 释放尾结点
    free(pList->tail);
    p->next = NULL;
    pList->length -= 1;

    // 更新尾结点
    pList->tail = p;
}

// 在指定位置插入一个结点，下标从 0 开始
void insertNodeAtIndex(SingleList *pList, int index, int value)
{
    if (index >= pList->length || index < 0) {
        // 下标越界
        printf("下标不合法!!!");
        return;
    }

    // 制造一个结点，加入链表中去
    Node *s = (Node *)malloc(sizeof(Node));
    s->value = value;
    s->next = NULL;

    Node *p = pList->head;
    Node *q = NULL;

    for (int i = 0; i < pList->length; i ++) {
        // 找到了要插入的节点位置
        if (i == index) {
          if (i == 0) {
              // 插入到头结点
              s->next = pList->head;
              pList->head = s;

          } else {
              s->next = p;
              q->next = s;
          }

          pList->length += 1;
          break;
        }

        q = p;
        p = p->next;

  }

}

// 在指定位置删除一个结点
void deleteNodeAtIndex(SingleList *pList, int index)
{
    if (index >= pList->length || index < 0) {
        // 下标越界
        printf("下标不合法!!!");
        return;
    }

    Node *p = pList->head;
    Node *q = NULL;
    for (int i = 0; i < pList->length; i ++) {
        if (index == i) {
            if (i == 0) {
                // 首节点，将链表的首节点指向
                pList->head = p->next;
            } else {
                q->next = p->next;
            }

            free(p);
            pList->length -= 1;
            break;
        }

        // 用 q 来记录 p 的上一个结点
        q = p;
        p = p->next;
    }
}

// 打印链表中所有结点值
void printList(SingleList *pList)
{
    Node *p = pList->head;
    if (p == NULL) {
        printf("链表为空!!!");
    }
    while (p) {
        printf("%d\n", p->value);
        p = p->next;
    }
}


// 求中间节点
Node *getMiddleNode(SingleList *pList)
{
    if (pList->head == NULL) {
        printf("链表为空！！！");
    }
    
    // 快指针，每次走两步
    Node *fast = pList->head;
    // 慢指针，每次走一步
    Node *slow = pList->head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    
    return slow;
}

// 翻转链表
// 输入：1->2->3->4->null
// 输出：4->3->2->1->null
void reverseList(SingleList *pList)
{
    // 当前节点
    Node *current = pList->head;
    // 保存上一个结点的指针
    Node *previous = NULL;
    
    while (current) {
        // 临时变量保存current->next
        Node *temp = current->next;
        // 让当前结点指向上一个结点
        current->next = previous;
        // 将当前节点保存起来
        previous = current;
  
        // p 移动到下一个指针
        current = temp;
    }
    
    // 更新尾指针
    pList->tail = pList->head;
    // 最后一个结点就是头指针
    pList->head = previous;
}

// 判断是否回文串
bool isPalindrome(SingleList *pList)
{
    // 快慢指针获取中间结点指针
    // 快指针，每次走两步
    Node *fast = pList->head;
    // 慢指针，每次走一步
    Node *slow = pList->head;
    Node *previous = NULL;
    while (fast && fast->next) {
        fast = fast->next->next;
        // 将前半部分链表翻转
        Node *temp = slow->next;
        slow->next = previous;
        previous = slow;
        slow = temp;
    }
    
    // 最后一个结点就是头指针
    pList->head = previous;
    
    // 链表长度是偶数时，fast 为空
    if (fast) {
        // 链表数是奇数，此时 slow 指向中间结点，provious 指向头结点，slow指针需要向前走一步，
        slow = slow->next;
    }

    while (slow) {
        if (slow->value != previous->value) {
            return false;
        }
        
        slow = slow->next;
        previous = previous->next;
    }
    
    return true;
}

// 两两交换相邻的结点
void swapNodesInPairs(SingleList *pList)
{
    Node *current = pList->head;
    Node *previous = NULL;
    while (current && current->next) {
        Node *a = current->next;
        Node *b = a->next;
        a->next = current;
        current->next = b;
        if (previous) {
            previous->next = a;
        } else {
            pList->head = a;
        }
        
        previous = current;
        // 每次走两步
        current = b;
    }
}
