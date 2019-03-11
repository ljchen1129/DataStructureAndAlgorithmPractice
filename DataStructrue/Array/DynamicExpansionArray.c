//
//  DynamicExpansionArray.c
//  Array
//
//  Created by 陈良静 on 2019/3/10.
//  Copyright © 2019 陈良静. All rights reserved.
//

#include "DynamicExpansionArray.h"
#include <stdlib.h>
#include <string.h>

//typedef struct {
//    int *array;
//    int size;
//}Array;

const int BLOCK_SIZE = 20;

// 创建数组
Array array_creat(int init_size)
{
    Array a;
    a.size = init_size;
    a.array = (int *)malloc(sizeof(int) * a.size);
    
    return a;
}

// 释放数组
void array_free(Array *a)
{
    free(a->array);
    a->size = 0;
    // 防止外界重复free导致崩溃，free(NULL) 是没问题的。
    a->array = NULL;
}

// 获取数组大小
int array_size(const Array *a)
{
    return a->size;
}

// 返回对应index的内存地址
int* array_at(Array *a, int index)
{
    if (index < 0) {
        printf("下标不合法！！！！");
    }
    
    // 如果下标大于等于当前最大的size，则数组需要扩容
    if (index >= a->size) {
        array_inflate(a, (index / BLOCK_SIZE + 1) * BLOCK_SIZE - a->size);
    }
    
    // array[index] ：如果分配的是连续的内存空间，指针array可以像数组一样使用
    return &(a->array[index]);
}

// 根据下标获取值
int array_get(const Array *a, int index)
{
    return a->array[index];
}

// 根据下标设置值
void array_set(Array *a, int index, int value)
{
    if (index > a->size) {
        array_inflate(a, (index / BLOCK_SIZE + 1) * BLOCK_SIZE - a->size);
    }
    
    a->array[index] = value;
}

// 数组扩容
void array_inflate(Array *a, int more_size)
{
    int *p = (int *)malloc((a->size + more_size) * sizeof(int));
    
    // memcoy，将a->array内存拷贝到p
    memcpy(p, a->array, sizeof(int) * a->size);
//    for (int i = 0; i < a->size; i++)
//    {
//        p[i] = a->array[i];
//    }
    
//    free(a->array);
    a->array = p;
    a->size += more_size;
}
