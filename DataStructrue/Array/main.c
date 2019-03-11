//
//  main.c
//  Array
//
//  Created by 陈良静 on 2019/3/10.
//  Copyright © 2019 陈良静. All rights reserved.
//

#include <stdio.h>
//#include "DynamicExpansionArray.h"
#include "SortArray.h"
#include <stdlib.h>
#include <string.h>

// 合并两个有序数组
Array mergeSortArray(const Array *a, const Array *b)
{
    Array p;
    
//    // 传入a数组为空
//    if (a->used == 0) {
//        p.array = (int *)malloc(sizeof(int) * b->used);
//        p.size = b->used;
//
//        memcpy(p.array, b->array, p.size * sizeof(int));
//        p.used = b->used;
//
//        return p;
//    }
//
//    // 传入b数组为空
//    if (b->used == 0) {
//        p.array = (int *)malloc(sizeof(int) * a->used);
//        p.size = a->used;
//
//        memcpy(p.array, b->array, p.size * sizeof(int));
//        p.used = a->used;
//
//        return p;
//    }
//
//    // 来到这里，传入数组都不为空
    // 申请内存空间
    p.array = (int *)malloc(sizeof(int) * (a->used + b->used));
    p.size = a->used + b->used;
    p.used = a->used + b->used;
//
//    if (a->array[a->used - 1] <= b->array[0])
//    {
//        // 如果a数组的最大值小于b数组的最小值
//        // 直接将a数组拼接到b数组的前面
//        memcpy(p.array, a->array, a->used * sizeof(int));
//        // 从a数组的末尾开始将b数组拷贝进来
//        memcpy(p.array + a->used, b->array, b->used* sizeof(int));
//
//        return p;
//    } else if (b->array[b->used - 1] <= a->array[0]) {
//        // 如果b数组的最大值小于a数组的最小值
//        // 直接将b数组拼接到a数组的前面
//        memcpy(p.array, b->array, b->used * sizeof(int));
//        // 从b数组的末尾开始将b数组拷贝进来
//        memcpy(p.array + b->used, a->array, a->used* sizeof(int));
//
//        return p;
//
//    } else {
        // a数组和b数组数据有交叉部分
        int i = 0, j = 0, k = 0;
        while (i < a->used && j < b->used) {
            if (a->array[i] <= b->array[j]) {
                p.array[k++] = a->array[i++];
            } else {
                p.array[k++] = b->array[j++];
            }
        }
        
        while (i < a->used) {
            p.array[k++] = a->array[i++];
        }
        
        while (j < b->used) {
            p.array[k++] = b->array[j++];
        }
        
        return p;
//    }
}


int main(int argc, const char * argv[]) {

//    // 创建一个大小 100 数组结构
//    Array a = array_creat(10);
//    int b[] = {0,1,2,3,4,5,6,7,8,9};
//    a.array = b;
//
//    printf("size = %d\n", array_size(&a));
//
//    // 根据索引下标设置值
//    *array_at(&a, 0) = 10;
//    *array_at(&a, 1) = 12;
//
//    // 根据索引下标取值
//    int index_0_Value = *array_at(&a, 0);
//    int index_1_Value = *array_at(&a, 1);
//    printf("index_0_Value = %d\nindex_1_Value = %d\n",index_0_Value, index_1_Value);
//
//    // 设置值
//    array_set(&a, 2, 20);
//    array_set(&a, 3, 21);
//
//    // 测试超出数组下标出插入，动态扩容数组，原来数组空间为 10，现在是120
//    *array_at(&a, 101) = 101;
//    int index_101_Value = *array_at(&a, 101);
//    printf("index_101_Value = %d\n", index_101_Value);
//
//    // 打印原来的值
//    for (int i = 0; i < 10; i ++) {
//        printf("---index_%d_Value %d\n", i, array_get(&a, i));
//    }
//
//
//    // 释放内存空间
//    array_free(&a);
    
//    // 1. 创建一个 10 大小的固定数组
//    Array a = arrayCreat(10);
//
//    // 2.添加元素
//    printf("-----插入\n");
//    arrayAdd(&a, -4);
//    arrayAdd(&a, 8);
//    arrayAdd(&a, 2);
//    arrayAdd(&a, 19);
//    arrayAdd(&a, 4);
//    arrayAdd(&a, 78);
//    arrayAdd(&a, 100);
//    arrayAdd(&a, 11);
//    arrayAdd(&a, 12);
//    arrayAdd(&a, 5);
//    // 插入失败
//    arrayAdd(&a, 10);
//
//    printf("\n");
//
//    // 打印数组元素
//    for (int i = 0; i < a.used; i++) {
//        printf("a[%d] = %d\n", i, a.array[i]);
//    }
//
//    // 3. 删除
//    printf("-----删除\n");
//    arrayDelete(&a, 0);
//    arrayDelete(&a, 1);
//    arrayDelete(&a, 2);
//    arrayDelete(&a, 3);
//    arrayDelete(&a, 4);
//    printf("\n");
//
//    for (int i = 0; i < a.used; i++) {
//        printf("a[%d] = %d\n", i, a.array[i]);
//    }
//
//    // 4. 修改
//    printf("-----修改\n");
//    arrayUpdate(&a, 0, 10);
//    arrayUpdate(&a, 5, 50);
//    printf("\n");
//
//    for (int i = 0; i < a.used; i++) {
//        printf("a[%d] = %d\n", i, a.array[i]);
//    }
//
//    // 释放空间
//    arrayFree(&a);
    
    Array a = arrayCreat(10);
    Array b = arrayCreat(10);
    
    printf("-----a数组插入数据\n");
    arrayAdd(&a, 20);
    arrayAdd(&a, 93);
    arrayAdd(&a, 3);
    arrayAdd(&a, 43);
    arrayAdd(&a, 65);
    
    for (int i = 0; i < a.used; i++) {
        printf("a[%d] = %d\n", i, a.array[i]);
    }
    
    printf("-----b数组插入数据\n");
    arrayAdd(&b, 100);
    arrayAdd(&b, 125);
    arrayAdd(&b, 34);
    arrayAdd(&b, 2);
    arrayAdd(&b, 11);
    arrayAdd(&b, 19);
    arrayAdd(&b, 78);
    arrayAdd(&b, 89);
    
    for (int i = 0; i < b.used; i++) {
        printf("b[%d] = %d\n", i, b.array[i]);
    }
    
    printf("数组合并\n");
    Array c = mergeSortArray(&a,  &b);
    for (int i = 0; i < c.used; i++) {
        printf("c[%d] = %d\n", i, c.array[i]);
    }
    
    arrayFree(&a);
    arrayFree(&b);
    
    return 0;
}

