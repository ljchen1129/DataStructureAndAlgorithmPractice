//
//  main.c
//  LinkedList
//
//  Created by 陈良静 on 2019/3/8.
//  Copyright © 2019 陈良静. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "SingleLinkedList.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }
    
    struct ListNode *fast = head;
    struct ListNode *slow = head;
   
    while(slow && fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) {
            break;
        }
    }
    
    // 有环
    if(fast == slow) {
        // 寻找环的起始结点
        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        
        return fast;
    } else {
        return NULL;
    }
}

// 给出一个链表，每 k 个节点一组进行翻转，并返回翻转后的链表。
Node * reverseKGroup(Node *head, int k){
    if (head == NULL || head->next == NULL || k < 2) {
        return head;
    }
    
    // 不够翻转
    Node *temp = head;
    for (int i = 0; i < k; i++, temp = temp->next) {
        if (temp == NULL) {
            // 不够翻转
            return head;
        }
    }
    
    Node *current = head;
    Node *previous = NULL;
    for (int i = 0; i < k; i ++) {
        Node *temp = current->next;
        current->next = previous;
        previous = current;
        current = temp;
    }
    
    head->next = reverseKGroup(current, k);
    return previous;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){

    // 异常判断
    if (l1 == NULL) {
        return l2;
    }
    
    if (l2 == NULL) {
        return l1;
    }
    
    struct ListNode *firsthead = l1;
    struct ListNode *secouondhead = l2;
    // 用第三个链表来保存数据
    struct ListNode *l3 = malloc(sizeof(struct ListNode));
    // 临时变量，指向新申请的结点l3
    struct ListNode *thirdhead = l3;
    
    // 同时遍历两个长短链表
    while (firsthead && secouondhead) {
        // 那个链表的结点值比较小就将该结点插入到新链表中
        if (firsthead->val <= secouondhead->val) {
            l3->next = firsthead;
            firsthead = firsthead->next;
        }else {
            l3->next = secouondhead;
            secouondhead = secouondhead->next;
        }
        l3 = l3->next;
    }
    
    if (firsthead == NULL) {
        // 还剩第二个链表，将第二个链表中的所有结点都插入到新链表中
        while (secouondhead) {
            l3->next = secouondhead;
            secouondhead = secouondhead->next;
            l3 = l3->next;
        }
    }
    
    if (secouondhead == NULL) {
        // 还剩第一个链表，将第一个链表中的所有结点都插入到新链表中
        while (firsthead) {
            l3->next = firsthead;
            firsthead = firsthead->next;
            l3 = l3->next;
        }
    }
    
    // 该结点的next指针指向的才是真正合并后的第一个结点
    return thirdhead->next;
}


int main(int argc, const char * argv[]) {
 
    SingleList *pList = creatList();

    // 加入结点
    printf("------加入结点\n");
    appendNode(pList, 10);
    appendNode(pList, 20);
    appendNode(pList, 30);
    appendNode(pList, 40);
    appendNode(pList, 50);
    
    reverseKGroup(pList->head, 2);
    
    printList(pList);
    
    // 中间节点
    Node *mid = getMiddleNode(pList);
    printf("mid.value = %d\n", mid->value);
    
    printf("------删除结点\n");
    removeLastNode(pList);
    printList(pList);

    printf("------插入新结点到头结点位置\n");
    insertNodeAtIndex(pList, 0, 100);
    printList(pList);

    printf("------插入新结点到尾结点位置\n");
    insertNodeAtIndex(pList, 4, 200);
    printList(pList);

    printf("------插入新结点到中间结点位置\n");
    insertNodeAtIndex(pList, 1, 300);
    printList(pList);

  
    
    printf("------插入新结点到中间结点位置\n");
    insertNodeAtIndex(pList, 3, 500);
    printList(pList);
    


    printf("------删除头结点\n");
    deleteNodeAtIndex(pList, 0);
    printList(pList);

    printf("------删除尾结点\n");
    deleteNodeAtIndex(pList, 6);
    printList(pList);

    printf("------删除中间结点\n");
    deleteNodeAtIndex(pList, 3);
    printList(pList);

//    printf("------删除中间结点\n");
//    deleteNodeAtIndex(pList, 2);
//    printList(pList);
    
//    // 翻转链表
//    printf("------翻转链表\n");
//    reverseList(pList);
//    printList(pList);
//
//    removeLastNode(pList);
//    removeLastNode(pList);
//    removeLastNode(pList);
//    removeLastNode(pList);
//
//    printList(pList);
    
//    printf("------加入结点\n");
//    appendNode(pList, 1);
//    appendNode(pList, 2);
//    appendNode(pList, 3);
//    appendNode(pList, 2);
//    appendNode(pList, 1);
//    printList(pList);
//
//    printf("isPalindrome = %d\n", isPalindrome(pList));
    
    swapNodesInPairs(pList);
    
    
    // 释放链表
    freeList(pList);
    
    
    
    return 0;
}
