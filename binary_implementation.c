#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data;
    int number;
    int depth;
    struct node *right, *left, *parent, *change;
} TREE ;

//Delete Operation
void Delete(TREE* node){
    if(node->left != NULL){
        if(node->left->data == '#')
            node->left = NULL;
        else
            Delete(node->left);
    }

    if(node->right != NULL){
        if (node->right->data == '#')
            node->right = NULL;
        else
            Delete(node->right);
    }
    return;
}

int call_leafNum(TREE* node){
    int call = 0;
    if (node->left != NULL)
        call += call_leafNum(node->left);
    if (node->right != NULL)
        call += call_leafNum(node->right);
    if (node->left == NULL && node->right == NULL)
        call = 1;
    return call;
}

//Output Function
void output(TREE* node){
    for (int i = 0; i < node->depth; i++)
        printf("    ");
    printf("%c\n", node->data);
    if (node->left != NULL)
        output(node->left);
    if (node->right != NULL)
        output(node->right);
    return;
}

void pre_sequence(TREE* node){
    printf("%c", node->data);
    if(node->left != NULL)
        pre_sequence(node->left);
    if(node->right != NULL)
        pre_sequence(node->right);
    return;
}

void in_sequence(TREE* node){
    if(node->left != NULL)
        in_sequence(node->left);
    printf("%c", node->data);
    if(node->right != NULL)
        in_sequence(node->right);
    return;
}

void post_sequence(TREE* node){
    if(node->left != NULL)
        post_sequence(node->left);
    if(node->right != NULL)
        post_sequence(node->right);
    printf("%c",node->data);
    return;
}

//Main Function
int main(){
    TREE *New, *tag[1000];
    int i, add, len, nowNum, leafNum = 0;
    char read[1000];
    for(i = 0; i < 1000; i++)
        tag[i] = NULL;
    gets(read);
    len = strlen(read);

    New = (TREE*)malloc(sizeof(TREE));
    New->parent = NULL;
    New->right = NULL;
    New->left = NULL;
    New->data = read[0];
    New->depth = 0;
    New->number = 1;
    tag[1] = New;
    add = 2;
    nowNum = 1;

    for(i = 1; i < len; i++){
        if (tag[nowNum] == NULL)
            break;
        New = (TREE*)malloc(sizeof(TREE));
        New->parent = tag[nowNum];
        tag[nowNum]->left = New;
        New->right = NULL;
        New->left = NULL;
        New->data = read[i];
        New->depth = New->parent->depth + 1;
        New->number = i + 1;
        tag[add] = New;
        add++;

        if (i < len - 1) {
            i++;
            New = (TREE*)malloc(sizeof(TREE));
            New->parent = tag[nowNum];
            tag[nowNum]->right = New;
            New->right = NULL;
            New->left = NULL;
            New->data = read[i];
            New->depth = New->parent->depth + 1;
            New->number = i + 1;
            tag[add] = New;
            add++;
        }
        nowNum++;
    }

    Delete(tag[1]);
    leafNum = call_leafNum(tag[1]);
    printf("BiTree\n");
    output(tag[1]);
    printf("pre_sequence  : ");
    pre_sequence(tag[1]);
    printf("\n");
    printf("in_sequence   : ");
    in_sequence(tag[1]);
    printf("\n");
    printf("post_sequence : ");
    post_sequence(tag[1]);
    printf("\n");
    printf("Number of leaf: %d\n", leafNum);
    printf("BiTree swapped\n");

    for (i = 1; i < add; i++){
        tag[i]->change = tag[i]->left;
        tag[i]->left = tag[i]->right;
        tag[i]->right = tag[i]->change;
    }

    output(tag[1]);
    printf("pre_sequence  : ");
    pre_sequence(tag[1]);
    printf("\n");
    printf("in_sequence   : ");
    in_sequence(tag[1]);
    printf("\n");
    printf("post_sequence : ");
    post_sequence(tag[1]);
    printf("\n");
    return 0;
}

/*
 编写程序实现二叉树的如下操作：
1) 建立二叉链表
2) 二叉树的先序、中序、后序遍历
3) 求二叉树的叶子结点个数
4) 将二叉树中所有结点的左、右子树相互交换

输入：
　　按完全二叉树的层次关系给出二叉树的遍历序列（#表示虚结点，数据结点为单一字符）。

输出：
　　二叉树的凹入表示
　　二叉树的先序序列、中序序列、后序序列
　　二叉树叶子结点个数
　　左、右子树相互交换后的二叉树的凹入表示
　　左、右子树相互交换后的二叉树的先序序列、中序序列、后序序列。

说明：
　　在输出凹入表示的二叉树时，先输出根结点，然后依次输出左右子树，上下层结点之间相隔 3 个空格。

 输入1：
 abc#de↵

 输出1：
 BiTree
a
    b
        d
    c
        e
pre_sequence  : abdce
in_sequence   : bdaec
post_sequence : dbeca
Number of leaf: 2
BiTree swapped
a
    c
        e
    b
        d
pre_sequence  : acebd
in_sequence   : ceadb
post_sequence : ecdba
 ——————————————————————————————————————————
 输入2：
 abcdefg↵

 输出2：
 BiTree
a
    b
        d
        e
    c
        f
        g
pre_sequence  : abdecfg
in_sequence   : dbeafcg
post_sequence : debfgca
Number of leaf: 4
BiTree swapped
a
    c
        g
        f
    b
        e
        d
pre_sequence  : acgfbed
in_sequence   : gcfaebd
post_sequence : gfcedba
 */
