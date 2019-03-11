//
//  DynamicExpansionArray.h
//  Array 动态数组
//
//  Created by 陈良静 on 2019/3/10.
//  Copyright © 2019 陈良静. All rights reserved.
//

#ifndef DynamicExpansionArray_h
#define DynamicExpansionArray_h

#include <stdio.h>

typedef struct {
    int *array;// 指针数组
    int size; // 数组大小
}Array;

// 创建数组
Array array_creat(int init_size);
// 释放数组
void array_free(Array *a);
// 获取数组大小
int array_size(const Array *a);

// 根据下标获取数组
int* array_at(Array *a, int index);

// 根据下标获取值
int array_get(const Array *a, int index);
// 根据下标设置值
void array_set(Array *a, int index, int value);

// 数组扩容
void array_inflate(Array *a, int more_size);


#endif /* DynamicExpansionArray_h */
