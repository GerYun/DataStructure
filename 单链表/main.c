//
//  main.c
//  SinglyLinkedList
//
//  Created by DuWeiWu on 2018/6/8.
//  Copyright © 2018年 DuWeiWu. All rights reserved.
//

#include <stdio.h>
#include <malloc/malloc.h>
#include <stdlib.h>
#include "stdbool.h"

#define ElemType int

typedef struct Node {
    ElemType data;
    struct Node *pNext;
}NODE, *PNODE;

// 创建链表，用户可以输入链表的个数，和每一个的值
PNODE create_list(void);
// 遍历打印出链表的所有元素值
void traverse(PNODE);
// 判断链表是否为kong
bool is_empty(PNODE);
// 返回链表的长度
int lengh_list(PNODE);
// 把链表排序
void sort_list(PNODE);
// 插入值
bool insert_list(PNODE,int,ElemType);
// 删除一个元素
bool delete_list(PNODE,int,ElemType *);


int main(int argc, const char * argv[]) {
    
    PNODE pHead = create_list();
    traverse(pHead);
    printf("链表的长度是 %d\n",lengh_list(pHead));
    sort_list(pHead);
    traverse(pHead);
    printf("请输入插入元素的位置:");
    int i;
    int val;
    scanf("%d",&i);
    printf("请输入插入的值:");
    scanf("%d",&val);
    insert_list(pHead, i, val);
    traverse(pHead);
    
    int e;
    delete_list(pHead, 3, &e);
    printf("删除的值是 %d \n",e);
    traverse(pHead);
    
    return 0;
}


PNODE create_list(void) {
    
    PNODE pHead = (PNODE)malloc(sizeof(NODE));
    pHead->data = 0;
    pHead->pNext = NULL;
    //请输入链表的节点个数：
    printf("请输入链表的节点个数：");
    int num;
    scanf("%d",&num);
    
    int val;
    PNODE p = pHead;
    for (int i = 0; i < num; i++) {
        printf("请输入第%d个节点的值:",i+1);
        scanf("%d",&val);
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        pNew->data = val;
        pNew->pNext = NULL;
        p->pNext = pNew;
        p = pNew;  // p = p->pNext;
    }
    
    return pHead;
}


void traverse(PNODE pHead) {
    PNODE p = pHead->pNext;
    while (p) {
        printf("%d ",p->data);
        p = p->pNext;
    }
    printf("\n");
}

bool is_empty(PNODE pHead) {
    return (pHead->pNext != NULL);
};

int lengh_list(PNODE pHead) {
    
    int i = 0;
    PNODE p = pHead->pNext;
    while (p!= NULL) {
        i++;
        p = p->pNext;
    }
    return i;
}

void sort_list(PNODE pHead) {
    
    int i,j,t;
    PNODE p,q;
    
    int lengh = lengh_list(pHead);
    
    // 需要对链表的每个节点进行一次排序 的 操作 循环
    for (i = 0, p = pHead->pNext; i < lengh - 1; i++,p = p->pNext) {
        
        //取出当前节点。和之后的每一个节点进行比较 的 循环
        for (j = i, q = p->pNext; j < lengh - 1; j++,q = q->pNext) {
            if (p->data > q->data) {
                t = p->data;
                p->data = q->data;
                q->data = t;
            }
        }
    }
}


bool insert_list(PNODE pHead,int pos,ElemType data) {
    
    //首先找到第pos个元素 之前的一个元素
    // 所以 pos - 1
    int i = 0;
    // 这里要从头节点开始，因为很有可能要插入在 第一个有效节点前面
    PNODE p = pHead;
    while (p->pNext != NULL && i < pos - 1) {
        i++;
        p = p->pNext;
    }
    
    // 条件满足，插入新元素
    if (p->pNext != NULL && i < pos) {
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        pNew->data = data;
        pNew->pNext = p->pNext;
        p->pNext = pNew;
    }
    else {
        return false;
    }
    
    return true;
}

bool delete_list(PNODE pHead,int pos,ElemType *e) {
    
    // 首先找到pos之前的一个元素
    PNODE p = pHead;
    int i = 0;
    while (p->pNext && i < pos - 1) {
        p = p->pNext;
        ++i;
    }
    
    if (p->pNext && i < pos) {
        PNODE r = p->pNext;
        p->pNext = p->pNext->pNext;
        *e = r->data;
        free(r);
    }
    else {
        return false;
    }
    
    return true;
}




