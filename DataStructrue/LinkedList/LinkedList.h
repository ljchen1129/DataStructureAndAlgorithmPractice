//
//  LinkedList.h
//  LinkedList
//
//  Created by 陈良静 on 2019/3/8.
//  Copyright © 2019 陈良静. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h

#include <stdio.h>

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(List L);
Position Find(int X, List L);





#endif /* LinkedList_h */
