//
//  main.c
//  二叉树遍历
//
//  Created by DuWeiWu on 2018/6/11.
//  Copyright © 2018年 DuWeiWu. All rights reserved.
//

#include <stdio.h>
#include <malloc/malloc.h>
#include <stdlib.h>
#include "stdbool.h"

/*假设如下二叉树
    A

B       C
      D   E
            F
 */

struct BinaryTree {
    char data;
    struct BinaryTree *leftChild;
    struct BinaryTree *rightChild;
};

// 初始化一个二叉树
struct BinaryTree *create(void);
// 先序遍历
void preTraversal(struct BinaryTree *);
// 中序遍历
void midTraversal(struct BinaryTree *);
//后序遍历
void lastTraversal(struct BinaryTree *);

int main(int argc, const char * argv[]) {
    
    struct BinaryTree *pTree = create();
    preTraversal(pTree);
    printf("\n");
    midTraversal(pTree);
    printf("\n");
    
    return 0;
}


struct BinaryTree *create() {
    
    struct BinaryTree *pTree = (struct BinaryTree *)malloc(sizeof(struct BinaryTree));
    struct BinaryTree *pB = (struct BinaryTree *)malloc(sizeof(struct BinaryTree));
    struct BinaryTree *pC = (struct BinaryTree *)malloc(sizeof(struct BinaryTree));
    struct BinaryTree *pD = (struct BinaryTree *)malloc(sizeof(struct BinaryTree));
    struct BinaryTree *pE = (struct BinaryTree *)malloc(sizeof(struct BinaryTree));
    struct BinaryTree *pF = (struct BinaryTree *)malloc(sizeof(struct BinaryTree));
    
    pTree->data = 'A';
    pTree->leftChild = pB;
    pTree->rightChild = pC;
    
    pB->data = 'B';
    pB->leftChild = pB->rightChild = NULL;
    
    pC->data = 'C';
    pC->leftChild = pD;
    pC->rightChild = pE;
    
    pD->data = 'D';
    pD->leftChild = pD->rightChild = NULL;
    
    pE->data = 'E';
    pE->leftChild = NULL;
    pE->rightChild = pF;
    
    pF->data = 'F';
    pF->rightChild = pF->leftChild = NULL;

    return pTree;
}


void preTraversal(struct BinaryTree *pTree) {
    
    if (pTree != NULL) {
        // 首先操作跟节点。这里的操作就是打印一下
        printf("%c",pTree->data);
        
        //再先序遍历根节点的左子树
        //而左子树又是一颗子树，所以 递归遍历
        if (pTree->leftChild != NULL) {
            preTraversal(pTree->leftChild);
        }
        
        //然后先序遍历根节点的右子树
        //而右子树又是一颗子树，所以 递归遍历
        if (pTree->rightChild != NULL) {
            preTraversal(pTree->rightChild);
        }
    }
}

void midTraversal(struct BinaryTree *pTree) {
    if (pTree != NULL) {
        //首先中序遍历根节点的左子树
        //而左子树又是一颗子树，所以 递归遍历
        if (pTree->leftChild != NULL) {
            midTraversal(pTree->leftChild);
        }
        
        // 然后操作根节点。这里的操作就是打印一下
        printf("%c",pTree->data);
        
        //然后zhong序遍历根节点的右子树
        //而右子树又是一颗子树，所以 递归遍历
        if (pTree->rightChild != NULL) {
            midTraversal(pTree->rightChild);
        }
    }
}

void lastTraversal(struct BinaryTree *pTree) {
    if (pTree != NULL) {
        //首先后序遍历根节点的左子树
        //而左子树又是一颗子树，所以 递归遍历
        if (pTree->leftChild != NULL) {
            midTraversal(pTree->leftChild);
        }
        //然后后序遍历根节点的右子树
        //而右子树又是一颗子树，所以 递归遍历
        if (pTree->rightChild != NULL) {
            midTraversal(pTree->rightChild);
        }
        
        // 然后操作根节点。这里的操作就是打印一下
        printf("%c",pTree->data);
    }
}
