#include <iostream>
#include "dclink.hxx"

using namespace std;
int main(void){

    DCLink<int> dc;
    for(int i = 0; i < 10; i++){
        dc.push_back(i);
    }

    dc.push_front(-1);
    dc.show_link();
    dc.insert_val();
    dc.show_link();
    dc.pop_back();
    cout<<"删除最后一个节点时如下:" <<endl;
    dc.show_link();

    return 0;
}