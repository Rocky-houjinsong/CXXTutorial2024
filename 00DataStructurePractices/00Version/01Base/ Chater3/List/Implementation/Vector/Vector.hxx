#ifndef _VECTOR_HXX_
#define _VECTOR_HXX_

template <typename Object>
class Vector {
    private:
        int theSize;
        int theCapacity;
        Object *objects;
    public:
        typedef Object * iterator;
        typedef const Object * const_iterator;
        enum {SPARE_CAPACIOTY = 16};  

    public:
        explicit Vector(int initSize = 0);
        Vector(const Vector &rhs);
        ~Vector();

        const Vector & operator= (const Vector &rhs);
        void resize(int newSize);
        void reserve(int newCapacity);
        
        Object & operator[](int index);
        const Object & operator[](int index) const;

        bool empty() const;

        int size() const;

        int capacity() const;

        void push_back(const Object &x);

        void pop_back();

        const Object & back() const;

        iterator begin();
        const_iterator begin() const;

        iterator end();
        const_iterator end() const;


/**
 * 这两天工作安排: 
 * 晚上 9点 务必开始学习 :  11点半前结束  
 * 学习内容安排 
 * 
 * 一天  学习 C++23标准  
 * 一天 学习 C++数据结构 
 * 一天  学习 CMake + GoogleTest框架  
 * 
 * 
 */


};

#endif // _VECTOR_HXX_