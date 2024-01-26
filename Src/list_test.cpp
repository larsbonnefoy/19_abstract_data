#include "../Includes/list.hpp"
#include <iostream>
#include <iterator>
#include <list>


int main(){

    std::list<int> test1;
    for (int i = 0; i < 10; i++) {
        test1.push_back(i);
    }
    // std::list<int>::const_iterator cstIt1 = test1.begin();
    std::list<int>::reverse_iterator revIt= test1.rbegin();
    std::cout << *(++revIt) << std::endl;
    auto ittest1 = test1.end();
    std::cout << "here" <<*(--ittest1) << std::endl;
    //
    // auto it = test1.end();

    
    ft::list<int> test;

    ft::list<int>::iterator cstIt = test.begin();
    test.insert(cstIt, -1);
    for (int i = 0; i < 10; i++) {
        test.push_back(i);
    }
    test.display_list();

    test.begin();
    ft::list<int>::iterator it = test.begin();
    std::cout << *(it++) << std::endl;
    std::cout << *(++it) << std::endl;
    std::cout << *(it--) << std::endl;
    std::cout << *(--it) << std::endl;
    // std::cout << *(--test.end());
}

