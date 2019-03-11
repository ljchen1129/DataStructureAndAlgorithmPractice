//
//  main.c
//  C指针
//
//  Created by 陈良静 on 2019/3/9.
//  Copyright © 2019 陈良静. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

// 取别名，相当于Point就是结构体体类型。
typedef struct {
    int x;
    int y;
}Point;


// 求整型数组中元素的最大值和最小值
void minmax(int a[], int len, int *max, int *min)
{
    int i;
    *min = *max = a[0];
    for (i = 1; i<len; i++)
    {
        if (a[i] < *min) {
            *min = a[i];
        }
        
        if (a[i] > *max) {
            *max = a[i];
        }
    }
}


// 如果除法成功，返回1；否则返回0
int divide(int a, int b, int *resutlt)
{
    int ret = 1;
    if (b == 0) ret = 0;
    else {
        *resutlt = a/b;
    }
    return ret;
}

int sum(int a[], int length)
{
    int result = 0;
    a[0] = 6;
    for (int i = 0; i < length; i ++)
    {
        result += a[i];
    }
    
    return result;
}

int main(int argc, const char * argv[]) {

    Point p1;
    Point *p2 = &p1;
    
    p1.x = 1;
    p1.y = 1;
    p2->x = 2;
    p2->y = 2;
    
}
