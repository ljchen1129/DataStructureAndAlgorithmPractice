//
//  main.c
//  DoubleLinkList
//  双向链表
//  Created by 陈良静 on 2019/5/5.
//  Copyright © 2019 陈良静. All rights reserved.
//

#include <stdio.h>
#include "DoubleLinkList.h"

int main(int argc, const char * argv[]) {
    
    ListNode *head = creatList();
    
    printf("-----插入结点\n");
    appendNode(head, 10);
    appendNode(head, 20);
    appendNode(head, 30);
    appendNode(head, 40);
    appendNode(head, 50);
    
    printList(head);
    
    printf("------指定位置插入结点\n");
    insertNodeAtIndex(head, 3, 100);
    printList(head);
    
    printf("------指定位置删除结点\n");
    deleteNodeAtIndex(head, 5);

    printList(head);
    
    freeList(head);
    
    return 0;
}
