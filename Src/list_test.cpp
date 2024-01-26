#include "../Includes/list.hpp"
#include <iostream>
#include <iterator>
#include <list>


int main(){

    std::list<int> test1;
    //
    // auto it = test1.end();

    
    ft::list<int> test;

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
    // ft::list<int>::iterator it2(it);
}

