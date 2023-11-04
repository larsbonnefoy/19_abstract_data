#include <cstddef>
#include <iostream>
#include <vector>
#include "../Includes/Vector.hpp"

int main ( void )
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

    //front value is still set, we just dont have access anymore
    //Should check with constructed class object
    std::vector<int> v2(100, 2); 
    v2.clear();
    std::cout << "front val: " << v2.front() << std::endl;
    */

    std::vector<int> v2(100, 2); 
    int start_elem = v2.front();
    int *data = v2.data();
    v2.clear();
    std::cout <<  data[0] << std::endl;
    std::cout << "front val: " << v2.front() << std::endl;
    std::cout << start_elem << std::endl;

    /////////////////////////////////
    ft::vector<int> vft2(10, 2);
    std::cout << vft2.capacity() << std::endl;
    std::cout << vft2.size() << std::endl;
    data = vft2.data();
    for (std::size_t i = 0; i < vft2.size(); i++) {
        std::cout << data[i] << std::endl;
    }
    vft2.front() = 1;
    std::cout << vft2.front() << std::endl;
    vft2.clear();
    std::cout << vft2.size() << std::endl;
    std::cout << vft2.front() << std::endl;
    return 0;

}
