//
//  main.c
//  Queue
//
//  Created by DuWeiWu on 2018/6/9.
//  Copyright © 2018年 DuWeiWu. All rights reserved.
//

#include <stdio.h>
#include <malloc/malloc.h>
#include <stdlib.h>
#include "stdbool.h"

// 队列是一种 先进先出的 数据存储方式

// 循环队列，也叫 静态队列，数组内核实现
#define ElemType int
#define QUEUE_LENGTH  6

typedef struct Queue {
    ElemType *pBase;  //
    /// 头指针
    int front;
    /// 尾指针
    int real;
}QUEUE, *PQUEUE;

// 初始化队列
PQUEUE init(void);
// 入队
bool en_queue(PQUEUE,ElemType);
// 出队
bool out_queue(PQUEUE,ElemType *);
// 队列是否已满
bool full_queue(PQUEUE);
// 队列是否为空
bool empty_queue(PQUEUE);
// 遍历队列
void traverse(PQUEUE);


int main(int argc, const char * argv[]) {
    
    PQUEUE pQueue = init();
    en_queue(pQueue, 1);
    en_queue(pQueue, 2);
    en_queue(pQueue, 3);
    en_queue(pQueue, 4);
    en_queue(pQueue, 5);
    // 由于队列的长度是6 我们只能存放5个元素进去.尾索引处要空一个空闲位出来
    en_queue(pQueue, 6);
    en_queue(pQueue, 7);
    en_queue(pQueue, 8);
    
    //
    traverse(pQueue);
    //
    int val;
    out_queue(pQueue, &val);
    printf("出队的值是 %d \n", val);
    //
    traverse(pQueue);
    
    
    return 0;
}


PQUEUE init(void) {
    PQUEUE queue = malloc(sizeof(QUEUE));
    // 初始化时 头索引和尾索引 相等，指向索引0处
    queue->front = 0;
    queue->real = 0;
    queue->pBase = malloc(sizeof(ElemType) * QUEUE_LENGTH);
    return queue;
}

bool en_queue(PQUEUE pQueue,ElemType val) {
    
    if (full_queue(pQueue)) {
        return false;
    }
    // 入队，先把数据放到 尾索引指向的数组处
    pQueue->pBase[pQueue->real] = val;
    // 然后将尾索引，向后移到一格
    pQueue->real = (pQueue->real + 1) % QUEUE_LENGTH;
    return true;
}

bool out_queue(PQUEUE pQueue,ElemType *e) {
    if (empty_queue(pQueue)) {
        return false;
    }
    // 先取出头索引处的数据
    *e = pQueue->pBase[pQueue->front];
    // 然后将头索引向后移动一格
    pQueue->front = (pQueue->front + 1) % QUEUE_LENGTH;
    return true;
}

void traverse(PQUEUE pQueue) {
    int val;
    int f = pQueue->front;
    while (f != pQueue->real) {
        val = pQueue->pBase[f];
        f = (f + 1) % QUEUE_LENGTH;
        printf("%d ",val);
    }
    printf("\n");
}


bool full_queue(PQUEUE pQueue) {
    // 循环静态队列，real指向的索引处，不存放数据
    // 当real再向后移到一格，将会和front的重合，队列将满
    if ((pQueue->real + 1) % QUEUE_LENGTH == pQueue->front) {
        return true;
    }
    return false;
}

bool empty_queue(PQUEUE pQueue) {
    // 当头和尾索引重合时 ，队列为空
    if (pQueue->real == pQueue->front) {
        return true;
    }
    return false;
}





