//
//  main.c
//  DoubleLinkedList
//
//  Created by 陈良静 on 2019/5/2.
//  Copyright © 2019 陈良静. All rights reserved.
//

#include <stdio.h>
#include "CycleLinkedList.h"

int main(int argc, const char * argv[]) {
  
    CycleList *pList = creatList();

    // 加入结点
    printf("----加入结点\n");
    appendNode(pList, 10);
    appendNode(pList, 20);
    appendNode(pList, 30);
    printList(pList);
    
    printf("----插入结点\n");
    insertNodeAtIndex(pList, 3,  40);
    printList(pList);
    //删除结点
    printf("----删除结点\n");
    deleteNodeAtIndex(pList, 3);
    
//    removeLastNode(pList);
//    removeLastNode(pList);
    printList(pList);

    printf("----插入结点\n");
    insertNodeAtIndex(pList, 2,  50);
    printList(pList);
    

//    // 插入结点
//    printf("----插入结点\n");
//    insertNodeAtIndex(pList, 0, 100);
//    insertNodeAtIndex(pList, 1, 200);
//    insertNodeAtIndex(pList, 1, 300);
////    insertNodeAtIndex(pList, 1, 400);
//
//    printList(pList);

    
    return 0;
}
