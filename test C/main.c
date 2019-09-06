#include <stdio.h>
#include <stdlib.h>//malloc函数

struct Node {    //链表结点
    int data;    //数据
    struct Node* link;    //指向下一个结点的指针
};
/* 尾插法建立单链表：返回单链表的头指针 */
struct Node* buildLinkedList(int* arr, int n); /* 尾插法建立单链表 */
void printLinkedList(struct Node* head);       /* 打印链表 */

int main(int argc, char const *argv[]) {
    int n, i;
    int* a;
    scanf("%d", &n);
    a = (int*)malloc(n * sizeof(int));    //动态内存分配申请数组空间
    for (i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    
    struct Node* head = NULL;    //声明一个指针变量head
    
    //创建链表，把返回的头指针赋值给head指针变量
    head = buildLinkedList(a, n);
    
    //打印链表：整个链表用head来代表。
    printLinkedList(head);
    
    free(a);    //释放存储空间
    
    return 0;
}
void printLinkedList(struct Node* head){
    while(head != NULL)
    {
        printf("%d",head->data);
        head=head->link;
    }
}
struct Node* buildLinkedList(int* arr, int n){
   struct Node *head = (struct Node *)malloc(sizeof(struct Node*)); //  为头指针开辟内空间
    struct Node* node = NULL;           //  定义结点
    struct Node* end = NULL;            //  定义尾结点
    head->link = NULL;              //  初始化头结点指向的下一个地址为 NULL
    end = head;   //  未创建其余结点之前，只有一个头结点                //  结点个数
    for (int i = 0; i < n; i++) {
        node = (struct Node *)malloc(sizeof(struct Node *)); //  为新结点开辟新内
        node->data = *(arr + i);                                  //  新结点的数据域赋值
        end->link = node;
        end = node;
    }
    end->link = NULL;
    
    return  head;
}
