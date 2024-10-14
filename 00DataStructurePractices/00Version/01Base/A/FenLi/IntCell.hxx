#ifndef _INTCELL_H_
#define _INTCELL_H_

class IntCell
{
    private:
        int storedValue;
    
    public:
        /** 禁止隐式转换的单参数构造函数*/
        explicit IntCell(int initialValue = 0) ; 
        /** 访问函数 读取 storedValue值 */
        int read() const;
        /**  修改函数 , 修改 storedValue值 */
        void write(int x);
};

#endif