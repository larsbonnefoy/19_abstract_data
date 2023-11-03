#include <cstddef>
#include <iostream>
#include <vector>
#include "../Includes/Vector.hpp"

int main (int argc, char *argv[])
{
    std::vector<int> v;
    std::cout << "size "<< v.size() << std::endl;
    std::cout << "capa " << v.capacity() << std::endl;
    v.push_back(3);
    std::cout << "size "<< v.size() << std::endl;
    std::cout << "capa " << v.capacity() << std::endl;
    v.push_back(4);
    std::cout << "size "<< v.size() << std::endl;
    std::cout << "capa " << v.capacity() << std::endl;
    v.push_back(5);
    std::cout << "size "<< v.size() << std::endl;
    std::cout << "capa " << v.capacity() << std::endl;
    std::cout << *(v.data()) << std::endl;
    std::cout << v.front()<< std::endl;
    std::cout << v.back()<< std::endl;
    
    int *v1 = &(v.front());
    *v1 = 2;
    std::cout << *v1 << std::endl;
    v.front() = 4; //peut assigner directment vu que v.front return un reference
    std::cout << v.front() << std::endl;
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

    std::vector<int> v2; 
    std::cout << v2.max_size() << std::endl;

    /////////////////////////////////
    ft::vector<int> ownv2;
    std::cout << ownv2.max_size() << std::endl;
    return 0;
}
