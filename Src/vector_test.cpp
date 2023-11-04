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


    //How reserve works
    std::vector<int> v2; 
    std::cout << "capa"<< v2.capacity() << std::endl;
    v2.reserve(100);
    std::cout << "capa" << v2.capacity() << std::endl;
    for (size_t i = 0; i < v2.capacity(); i++) {
        v2[i] = i; //does not modify value of size but does assign value
    }

    for (size_t i = 0; i < v2.capacity(); i++) {
        v2.push_back(i); //changes value of size and assigns
    }
    std::cout << "size" << v2.size() << std::endl;
    v2.push_back(100);
    std::cout << "capa" << v2.capacity() << std::endl;
    v2.reserve(400);
    std::cout << "capa" << v2.capacity() << std::endl;

    */


    /////////////////////////////////
    std::vector<int> v(10, 2);
    std::cout << v.capacity() << std::endl;
    std::cout << v.size() << std::endl;
    v.push_back(1);
    std::cout << "added value " << v.back() << std::endl;
    std::cout << "capa " << v.capacity() << std::endl;
    std::cout <<"size " << v.size() << std::endl;
    v.reserve(20);
    std::cout << "capa " << v.capacity() << std::endl;
    std::cout <<"size " << v.size() << std::endl;
    v.push_back(1);
    std::cout << "added value " << v.back() << std::endl;
    std::cout << "capa " << v.capacity() << std::endl;
    std::cout <<"size " << v.size() << std::endl;
    for (size_t i = v.size(); i < v.capacity(); i++) {
        v.push_back(i);
    }
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << std::endl;
    }
    std::cout << "capa " << v.capacity() << std::endl;
    std::cout <<"size " << v.size() << std::endl;
    v.push_back(30);
    std::cout << "capa " << v.capacity() << std::endl;
    std::cout <<"size " << v.size() << std::endl;
    return 0;

}
