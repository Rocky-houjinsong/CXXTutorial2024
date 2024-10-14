/**
 * A  Class for simulating an integer memory cell;
 */
class IntCell
{
    public:
        /**
         * Construct the IntCell
         * Initial value is 0;
         */
        IntCell()
            { storedValue = 0; }
        /**
         * Construct the IntCell
         * Initial value is initialValue
         */
        IntCell(int initialValue)
            { storedValue = initialValue; }
        /**
         * Return the stored value.
         */
        int read()
            { return storedValue; }
        /**
         */
        void write(int x)   
            { storedValue = x; } 
    private:
        int storedValue;
};