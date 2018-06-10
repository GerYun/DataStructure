//
//  main.c
//  Hanoi
//
//  Created by DuWeiWu on 2018/6/10.
//  Copyright © 2018年 DuWeiWu. All rights reserved.
//

#include <stdio.h>

// 先借助于 c 把 a上的 n-1个盘子移动到b上，
// 再将a上剩下一个盘子直接移动到c
// 最后 将b上剩下的n-1个盘子 借助于a移到到 c上


// 参数a表示的是要移动的柱子
// 参数b表示被借助的柱子
// 参数c表示终点的柱子
void hanoi(int n,char a,char b,char c) {
    
    if (1 == n) {
        printf("将编号%d的盘子从%c移到%c上\n",n,a,c);
    }
    else {
        // 先借助于 c 把 a上的 n-1个盘子移动到b上
        hanoi(n - 1, a, c, b);
        // 第一步完成后，将移动的柱子上只剩一个的 移到 到 目标柱子上
        printf("将编号%d的盘子从%c移到%c上\n",n,a,c);
        // 最后 将b上剩下的n-1个盘子 借助于a移到到 c上
        hanoi(n - 1, b, a,c);
    }
}

int main(int argc, const char * argv[]) {
    
    hanoi(3, 'A', 'B', 'C');
    
    return 0;
}
