#include "IntCell.hxx"
 
 IntCell::IntCell(int initialValue) : storedValue(initialValue) 
 { 

 }

 int IntCell::read() const 
 {
    return storedValue;
 }

 void IntCell::write(int x)
 {
    storedValue = x;
 }