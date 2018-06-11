//
//  main.c
//  DymicStack
//
//  Created by DuWeiWu on 2018/6/9.
//  Copyright © 2018年 DuWeiWu. All rights reserved.
//

#include <stdio.h>
#include <malloc/malloc.h>
#include <stdlib.h>
#include "stdbool.h"


// 动态栈使用链表实现
typedef struct Node {
    struct Node * pNext;
    int data;
}NODE, *PNODE;

typedef struct Stack {
    PNODE pTop;
    PNODE pBottom;
}STACK, *PSTACK;

// 初始化一个栈
PSTACK init(void);
// 入栈
void push(PSTACK,int);
// 出栈
bool pop(PSTACK,int *);
// 判断栈是否为空
bool isEmpty(PSTACK);
// 清除所有元素
void clearStack(PSTACK);
// 遍历输出所有元素
void traverser(PSTACK);


int main(int argc, const char * argv[]) {
    
    PSTACK pst = init();
    push(pst, 1);
    push(pst, 2);
    push(pst, 3);
    push(pst, 4);
    push(pst, 5);
    traverser(pst);
    
    int val;
    pop(pst, &val);
    printf("弹出的值是 %d \n",val);
    
    traverser(pst);
    clearStack(pst);
    traverser(pst);
    
    return 0;
}


PSTACK init(void) {
    PSTACK pst = malloc(sizeof(STACK));
    PNODE node = malloc(sizeof(NODE));
    pst->pBottom = node;
    pst->pTop = pst->pBottom;
    return pst;
}

bool isEmpty(PSTACK pst) {
    return (pst->pTop == pst->pBottom);
}

void push(PSTACK pst,int val) {
    PNODE node = malloc(sizeof(NODE));
    node->data = val;
    node->pNext = pst->pTop;
    pst->pTop = node;
}

bool pop(PSTACK pst,int *e) {
    
    if (isEmpty(pst)) {
        return false;
    }
    
    PNODE p = pst->pTop;
    *e = p->data;
    pst->pTop = pst->pTop->pNext;
    free(p);

    return true;
}


void clearStack(PSTACK pst) {
    
    while (!isEmpty(pst)) {
        PNODE p = pst->pTop;
        pst->pTop = pst->pTop->pNext;
        free(p);
    }
}

void traverser(PSTACK pst) {
    
    PNODE p = pst->pTop;
    
    while (p != pst->pBottom) {
        printf("%d",p->data);
        p = p->pNext;
    }
    
    printf("\n");
}








