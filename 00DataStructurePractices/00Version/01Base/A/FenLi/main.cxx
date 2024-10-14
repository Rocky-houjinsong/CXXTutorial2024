#include <iostream>
#include <ostream>
#include "IntCell.hxx"

using namespace std;

int main()
{
    IntCell m;  // or, IntCell m(0);  but not IntCell m ();
    
    m.write(5);

    cout << "Cell contents : " << m.read() << std::endl;

    return 0;
}