#include <iostream>

using namespace std;

struct ListNode{
    int val; // 节点存储的元素
    ListNode *next; //指向下一个节点的指针;
    ListNode(int x) : val(x),next(NULL) {} // 节点的构造函数
    // 建议显示构造函数, 默认构造函数 不会初始化任何成员变量
};

class Solution{
    public:
        ListNode* removeElements(ListNode* head, int val){
            // 删除头结点 
            while(head != NULL && head->val == val){
                ListNode* tmp = head;
                head = head->next;
                delete tmp;
            }
            //删除 非头节点
            ListNode* cur = head; 
            while(cur != NULL && cur->next != NULL){
                if (cur->next->val == val)
                {
                    /* code */
                }
                
            }
        }
};