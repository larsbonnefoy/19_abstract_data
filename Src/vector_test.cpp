#include <iostream>
#include <vector>
#include "../Includes/Vector.hpp"

#define IS_TRUE(x) ((x) ? (std::cout << "\e[1;32m[OK] \e[0m", true) : (std::cout << "\e[1;31m[KO] \e[0m", false))

#define NOT_EMPTY "Vectors are not empty\n"
#define DIFFERENT_CAPA "Vectors have different capacities\n"

/*
#define IS_TRUE(x) do { \
    std::string msg = (x) ? "\e[1;31m [OK] \e[0m" : "\e[1;31m [KO] \e[0m"; \
    std::cout << msg << std::endl; \
} while (false)

void is_true(bool x) {
    std::string msg = x ? "\e[1;31m [OK] \e[0m" : "\e[1;31m [KO] \e[0m";
    std::cout << msg << std::endl;
}
*/


/**
 * Comapres value by value each vector
 */
bool value_compare(ft::vector<int> &v1, std::vector<int> &v2) {
    if (v1.size() != v2.size()) {return false;}
    for (size_t i = 0; i < v1.size(); i++) {
        if (v1[i] != v2[i]) {return false;}
    }
    return true;
}

/**
 * Tests behaviour in case of empty vector
 */
void is_empty() {
    std::cout << __FUNCTION__<< ": ";
    std::string log;
    ft::vector<int> vf;
    std::vector<int> vs;
    IS_TRUE(vf.empty() == vs.empty()) ? log.append(""): log.append(NOT_EMPTY);
    IS_TRUE(vf.capacity() == vs.capacity());
    IS_TRUE(vf.size() == vs.size());
    IS_TRUE(vf.data() == vs.data());
    std::cout << log << std::endl;
}

/**
 * Tests assign function.
 */
void assign() {
    std::cout << __FUNCTION__<< ": ";
    ft::vector<int> vf;
    std::vector<int> vs;
    vf.assign(0, 2);
    vs.assign(0, 2);
    IS_TRUE(vf.empty() == vs.empty());
    IS_TRUE(vf.capacity() == vs.capacity());
    IS_TRUE(vf.size() == vs.size());
    IS_TRUE(value_compare(vf, vs));
    vf.assign(10, 1);
    vs.assign(10, 1);
    IS_TRUE(vf.capacity() == vs.capacity());
    IS_TRUE(vf.size() == vs.size());
    IS_TRUE(value_compare(vf, vs));
    vf.assign(5, 2);
    vs.assign(5, 2);
    IS_TRUE(vf.capacity() == vs.capacity());
    IS_TRUE(vf.size() == vs.size());
    IS_TRUE(value_compare(vf, vs));
    std::cout << std::endl;
}

void resize() {
    std::cout << __FUNCTION__ << ": ";
    std::string log;
    ft::vector<int> vf;
    std::vector<int> vs;
    vf.reserve(5);
    vs.reserve(5);
    IS_TRUE(vf.capacity() == vs.capacity());
    IS_TRUE(vf.size() == vs.size());
    IS_TRUE(value_compare(vf, vs));
    vf.assign(10, 2);
    vs.assign(10, 2);
    vf.resize(5);
    vs.resize(5);
    IS_TRUE(vf.capacity() == vs.capacity());
    IS_TRUE(vf.size() == vs.size());
    IS_TRUE(value_compare(vf, vs));
    vf.resize(11);
    vs.resize(11);
    IS_TRUE(vf.capacity() == vs.capacity());
    IS_TRUE(vf.size() == vs.size());
    IS_TRUE(value_compare(vf, vs));
    vf.resize(20);
    vs.resize(20);
    IS_TRUE(vf.capacity() == vs.capacity());
    IS_TRUE(vf.size() == vs.size());
    IS_TRUE(value_compare(vf, vs));
    vf.resize(25, 3);
    vs.resize(25, 3);
    IS_TRUE(vf.capacity() == vs.capacity());
    IS_TRUE(vf.size() == vs.size());
    IS_TRUE(value_compare(vf, vs));
    vf.resize(20, 3);
    vs.resize(20, 3);
    IS_TRUE(vf.capacity() == vs.capacity()) ? log.append(""): log.append(DIFFERENT_CAPA);
    IS_TRUE(vf.size() == vs.size());
    IS_TRUE(value_compare(vf, vs));
    std::cout << log << std::endl;
}


int main ( void )
{
    is_empty();
    assign();
    resize();
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
    
    /*
    */
    return 0;

}
