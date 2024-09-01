#ifndef _DCLINK_H_
#define _DCLINK_H_

#include <iostream>
#include <new>
#include <stdlib.h>
using namespace std;

template<typename Type>
class DCLink; 

template<typename Type>
class DCLinkNode{
    // 双向循环链表的结点类型
    friend class DCLink<Type>;
public:
    DCLinkNode(Type x = 0){
        prev = next = NULL;
        data = x;
    }
    ~DCLinkNode(){

    }

private:
    Type data;          //数据域
    DCLinkNode *prev;   //前驱结点指针
    DCLinkNode *next;   //后驱节点指针
};


template<typename Type>
class DCLink{
public:
    DCLink(){
        //初始化对象的构造函数
        DCLinkNode<Type> *s = new DCLinkNode<Type>;
        first = last = s;
        s->next = first;
        s->prev = last;
        size = 0;
    }
    ~DCLink(){

    }

public:
    bool push_back(const Type &);    //尾随函数
    void show_link() const;          //显示链表
    bool push_front(const Type &);   //前插函数
    bool insert_val();               // 根据值插入
    bool pop_back();                 // 删除最后一个节点
private:
    bool insert_pos();               // 根据位置 插入
private:    
    DCLinkNode<Type> *first;         //指向链表的第一个节点
    DCLinkNode<Type> *last;          //指向链表的最后一个节点
    size_t size;                     // 统计结点个数, 不算没有数据的第一个;
};


template<typename Type>
bool DCLink<Type>::push_back(const Type &x){
    DCLinkNode<Type> *s = new DCLinkNode<Type>(x);
    if (s == NULL){
      return false;
    }
    
    s->next = first;
    s->prev = last;
    last->next = s;
    first->prev = s;
    last = s;
    return true;
}

template<typename Type>
void DCLink<Type>::show_link() const{
    DCLinkNode<Type> *p = first->next;

    while(p != first){
        cout << p->data << "-->";
        p = p->next;
    }
    cout << "NULL" << endl;
}

template<typename Type>
bool DCLink<Type>::push_front(const Type &x){
    DCLinkNode<Type> *s = new DCLinkNode<Type>(x);
    
    if(s == NULL){
        return false;
    }

    s->next = first->next;
    first->next->prev = s;
    s->prev = first;
    first->next = s;
    size++;

    return true;
}

template<typename Type>
bool DCLink<Type>::insert_val(){
    int number1;
    int number2;

    cout<<"请输入要插入位置的值 :";
    cin >> number1;
    cout<<"请输入要插入的数据";
    cin >> number2;

    DCLinkNode<Type> *p = first->next;
    DCLinkNode<Type> *s = new DCLinkNode<Type>(number2);
    while(p != first){
        if (p->data == number1){
            s->prev = p->prev;
            s->next = p;
            p->prev->next =s;
            p->prev = s;
            size++;
        }
        p = p->next;
    }
    return true;
}

template<typename Type>
bool DCLink<Type>::pop_back(){
    DCLinkNode<Type> *tmp = last->prev;
    DCLinkNode<Type> *tmp1 = last;

    tmp->next = first;
    first->next = tmp;
    last = tmp;
    size--;
    
    delete tmp1;
    tmp1 = NULL;

    return true;
}



#endif
