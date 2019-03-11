//
//  SortArray.h
//  Array 大小固定的有序数组
//
//  Created by 陈良静 on 2019/3/11.
//  Copyright © 2019 陈良静. All rights reserved.
//

#ifndef SortArray_h
#define SortArray_h

#include <stdio.h>

typedef struct {
    int size;// 数组大小
    int used; // 数组已经使用了多少
    int *array; // 指针
}Array;

// 根据数组大小初始化一个数组
Array arrayCreat(int init_size);

// 释放空间
void arrayFree(Array *a);

// 增，在数组末尾插入新数据
void arrayAdd(Array *a, int value);

// 删
void arrayDelete(Array *a, int index);

// 改，修改指定下标位置的值
void arrayUpdate(Array *a, int index, int value);

#endif /* SortArray_h */
