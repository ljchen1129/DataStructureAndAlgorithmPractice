//
//  LinkedList.c
//  LinkedList
//
//  Created by 陈良静 on 2019/3/8.
//  Copyright © 2019 陈良静. All rights reserved.
//

#include "LinkedList.h"

struct Node
{
    ElementType Element;
    Position Next;
};

int IsEmpty(List L) {
    return L->Next == NULL;
}

