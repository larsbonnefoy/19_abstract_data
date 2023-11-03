#include <cstddef>
#include <iostream>
#include <vector>
#include "../Includes/Vector.hpp"

int main (int argc, char *argv[])
{
    /*
    int *v1 = &(v.front());
    *v1 = 2;
    std::cout << *v1 << std::endl;
    v.front() = 4; //peut assigner directment vu que v.front return un reference
    std::cout << v.front() << std::endl;
    */
    /*
    for (size_t i = 0; i < 256;  i++) {
        v.push_back(i);
    }
    std::cout << v.size() << std::endl;
    std::cout << v.capacity() << std::endl;
    int *ptr = &v[0]; // The elements are stored contiguously, which means that elements can be accessed using offsets to regular pointers to elements.
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << *(ptr + i) << std::endl;
    }
    */

    std::vector<int> v2(1000, 2); 
    std::cout << v2.capacity() << std::endl;
    std::cout << v2.size() << std::endl;
    v2.push_back(1);
    std::cout << v2.capacity() << std::endl;
    std::cout << v2.size() << std::endl;

    /////////////////////////////////
    ft::vector<int> vft2(1000, 2);
    std::cout << vft2.capacity() << std::endl;
    std::cout << vft2.size() << std::endl;
    ft::vector<int> v3(2, 2);
    ft::vector<int> v5(4, 2);
    int *data = v2.data();
    /*
    for (std::size_t i = 0; i < ownv2.size(); i++) {
        std::cout << data[i] << std::endl;
    }
    */
    return 0;
}
