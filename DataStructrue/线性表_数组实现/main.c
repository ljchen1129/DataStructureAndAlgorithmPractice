//
//  main.c
//  线性表
//
//  Created by 陈良静 on 2017/5/26.
//  Copyright © 2017年 陈良静. All rights reserved.
//

#include <stdio.h>

// 定义一个线性表结构体
#define kListMaxSize 100
typedef struct{
    int data[kListMaxSize]; // 数组
    int last; // 数组最后一个元素下标索引
}List;

// 1. 初始化（建立空的线性表）
List *MakeEmpty()
{
    List *PtrL; // 定义一个指针，指向线性表
    PtrL = (List *)malloc(sizeof(List)); // 分配空间
    PtrL->last = -1; // 初始化数组最大下标为 -1，即：空数组
    printf("创建线性表成功！");
    return PtrL;
}

// 2. 根据位序 k,返回相应的元素
int FindKth(int k, List *PtrL)
{
    // 保证下标不越界
    if (0 <= k && k <= PtrL->last)
    {
        return PtrL->data[k];
    }
    else
    {   // 如果越界，就返回第一个元素
        return PtrL->data[0];
    }
}

// 3. 在线性表 L 中查找 X 元素第一次出现的位置
int Find(List *PtrL, int X)
{
    int i = 0;
    while (i <= PtrL->last && PtrL->data[i] != X)
    {
        i++;
    }
    if (i > PtrL->last)
    {
        return -1; // 没找到，返回 -1
    }
    else
    {
        return i;
    }
}

// 4. 在下标 i 出插入一个新元素 X
void Insert(int X, int i, List *PtrL)
{
    int j;
    
    if (PtrL->last == kListMaxSize)
    {
        printf("表满了！");
        return;
    }
    if (i < 0 || i > PtrL->last)
    {
        printf("位置不合法！");
        return;
    }
    for (j = PtrL->last; j >= i; j--)
    {
        // 先移动。把 i 后面的元素全部向后移动一位
        PtrL->data[j + 1] = PtrL->data[j];
    }
    // 再插入
    PtrL->data[i] = X;
    
    // 新的最大下标索引加一
    PtrL->last++;
}

// 5. 删除指定下标 i 的元素
void delete(int i, List *PtrL)
{
    int j;
    if (i < 0 || i > PtrL->last)
    {
        printf("不存在%d元素",i);
        return;
    }
    for (j = i + 1; j <= PtrL->last; j ++)
    {
        // 将 i 后面的所有元素都向前移动一位
        PtrL->data[j - 1] = PtrL->data[j];
    }
    // 新的最大下标索引减一
    PtrL->last--;
}

// 在末尾追加元素
void add(List *PtrL, int X)
{
    if (PtrL->last < 0)
    {
        PtrL->data[0] = X;
    }
    else
    {
        PtrL->data[PtrL->last + 1] = X;
    }
    
    PtrL->last++;
}

// 6. 返回线性表 L 的长度 n
int Length(List *PtrL)
{
    return PtrL->last + 1;
}

int main(int argc, const char * argv[]) {

    // 1. 初始化线性表
    List *PtrL = MakeEmpty();
    
    // 2. 追加元素
    add(PtrL, 10);
    add(PtrL, 20);
    add(PtrL, 5);
    add(PtrL, 30);
    
    for (int i = 0; i < PtrL->last + 1; i++)
    {
        printf("\n%d", PtrL->data[i]);
    }
    
    // 3. 查找指定位置的元素
    printf("\n第3位置的元素是%d\n",  FindKth(3, PtrL));
    // 4. 查找指定元素的位置
    printf("\n%d元素在第%d位置\n",  5, Find(PtrL, 5));
    
    // 5. 插入
    Insert(100, 2, PtrL);
    for (int i = 0; i < PtrL->last + 1; i++)
    {
        printf("\n插入后：%d", PtrL->data[i]);
    }
    
    printf("\n%d元素在第%d位置\n",  100, Find(PtrL, 100));
    
    // 6. 删除
    delete(2, PtrL);
    for (int i = 0; i < PtrL->last + 1; i++)
    {
        printf("\n删除后：%d", PtrL->data[i]);
    }
    
    // 7. 表长度
    printf("\n表元素个数为：%d", Length(PtrL));
    printf("\n");
    
    return 0;
}



