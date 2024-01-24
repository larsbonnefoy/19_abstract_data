#include "../Includes/list.hpp"
#include <list>

int main(){

    std::list<int> test1;

    auto it = test1.end();

    
    ft::list<int> test;
    for (int i = 0; i < 10; i++) {
        test.push_back(i);
    }
    for (int i = 10; i < 20; i++) {
        test.push_front(i);
    }
    test.display_list();
}

