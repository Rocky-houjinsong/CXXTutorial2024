
class IntCell
{
    private:
        int storedValue;
    
    public:
        /**
         * explicit  单参数构造函数 禁止创建隐式临时对象 
         */
        explicit IntCell (int initialValue = 0) 
            : storedValue(initialValue) { }    

        int read() const
            { return storedValue;}

        void write(int x)
            { storedValue = x; }      
};