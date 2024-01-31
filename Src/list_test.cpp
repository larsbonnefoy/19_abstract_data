#include "../Includes/list.hpp"
#include <iostream>
#include <iterator>
#include <list>

int main() {

    std::list< int > test1;
    for ( int i = 0; i < 10; i++ ) { test1.push_back( i ); }
    // std::list<int>::const_iterator cstIt1 = test1.begin();
    std::list<int>::const_iterator constIt = test1.begin();
    std::cout << *constIt << std::endl;
    constIt++;
    std::cout << *constIt << std::endl;
    std::list<int>::iterator inserted = test1.insert(constIt, 10, -1);
    std::cout << *(--inserted) << std::endl;




    /********************************************************/
    ft::list< int > test;

    test.insert( test.begin(), -1 );
    for ( int i = 0; i < 10; i++ ) { test.push_back( i ); }

    test.begin();
    ft::list< int >::iterator it = test.begin();
    for (; it != test.end(); it++) {
        std::cout << *it << " ";
    }
    test.insert(++test.begin(), 10, -1);


    ft::list< int >::const_iterator cst_it = test.begin();
    ft::list< int >::reverse_iterator rev_it = test.rbegin();
    ft::list< int >::const_reverse_iterator const_rev_it = test.rbegin();

    // std::cout << *(it++) << std::endl;
    // std::cout << *(++it) << std::endl;
    // std::cout << *(it--) << std::endl;
    // std::cout << *(--it) << std::endl;
}
