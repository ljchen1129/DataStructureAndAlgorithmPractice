//
//  SortArray.c
//  Array
//
//  Created by 陈良静 on 2019/3/11.
//  Copyright © 2019 陈良静. All rights reserved.
//

#include "SortArray.h"
#include <stdlib.h>

//typedef struct {
//    int size;// 数组大小
//    int *array; // 指针
//}Array;

// 创建固定大小数组
Array arrayCreat(int init_size)
{
    Array a;
    a.array = (int *)malloc(init_size*sizeof(int));
    a.size = init_size;
    a.used = 0;
    
    return a;
}

// 释放空间
void arrayFree(Array *a)
{
    free(a->array);
    a->size = 0;
    a->used = 0;
    // 防止外界重复free导致崩溃，free(NULL) 是没问题的。
    a->array = NULL;
}

// 增，在数组末尾插入新数据
void arrayAdd(Array *a, int value)
{
    // 先判断数组空间是否满了
    if (a->used == a->size) {
        printf("添加失败，数组空间已满！！！");
    } else {
        // 如果数组为空
        if (a->used == 0) {
            a->array[a->used] = value;
        } else if (value >= a->array[a->used - 1]) {
            // 比数组中最大的还大
            a->array[a->used] = value;
        } else {
            // 循环遍历数组中的元素，比较新加入的值是否比原来每一个元素大，大的话就往前再比
            for (int i = a->used - 1; i >= 0; i--) {
                // 将 i ~ used -1 下标都要往后移动一位
                a->array[i+1] = a->array[i];
                if (value >= a->array[i]) {
                    a->array[i + 1] = value;
                    break;
                } else {
                    if (i == 0) {
                        a->array[i] = value;
                    }
                }
            }
        }
       
        // 加入元素成功，更新used
        a->used += 1;
    }
}

// 删，根据下标删除一个元素
void arrayDelete(Array *a, int index)
{
    // 判断下标是否合法
    if (index >= a->size || index < 0) {
        printf("下标不合法!!!");
    } else {
        // 从 index + 1 ~ used 位置的元素都需要向前移动
        for (int i = index + 1; i < a->used; i ++) {
            a->array[i - 1] = a->array[i];
        }
        
        // 更新used
        a->used -= 1;
    }
}

// 改，修改指定下标位置的值
void arrayUpdate(Array *a, int index, int value)
{
    // 判断下标是否合法
    if (index >= a->used || index < 0) {
        printf("下标 = %d 不合法!!!", index);
    } else {
        if (value != a->array[index]) {
            // 先删掉index位置的元素
            arrayDelete(a, index);
            
            // 重新把value加入进来
            arrayAdd(a, value);
        }
    }
}
