#include <iostream>
#include <sstream>
#include <vector>
#include "../Includes/Vector.hpp"

#define IS_TRUE(x) ((x) ? (std::cout << "\e[1;32m[OK] \e[0m", true) : (std::cout << "\e[1;31m[KO] \e[0m", false))

#define F_CAP vf.capacity()
#define S_CAP vs.capacity()
#define DIFF_CAP "Vectors have different capacities"

#define F_SIZE vf.size()
#define S_SIZE vs.size()
#define DIFF_SIZE "Vectors have different capacities"

#define NOT_EMPTY "Vector is not empty"
#define DIFF_VAL "Vectors don't have the same value"
#define DIFF_MAX_SIZE "Vectors dont have the same max size"

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

std::string create_log_message(const char *str,  size_t vf = 0, size_t vstl = 0) {
    std::string message = str;
    std::stringstream stream;
    if (!(vf == vstl)) { 
        stream <<"\t-> "<< message << " | vf: " << vf << " vstl: " << vstl << std::endl;
    }
    else {
        stream << message << std::endl;

    }
    return stream.str();
}

/**
 * Comapres value by value each vector
 */
template<typename U, typename T>
bool value_compare(ft::vector<U> &v1, std::vector<T> &v2) {
    if (v1.size() != v2.size()) {return false;}
    for (size_t i = 0; i < v1.size(); i++) {
        if (v1[i] != v2[i]) {return false;}
    }
    return true;
}

/**
 * Global test
 * Tests for size, capacity and values inside vector
 */
template<typename U, typename T>
void g_test(ft::vector<U> &vf, std::vector<T> &vs, std::string &log) {
    IS_TRUE(F_CAP == S_CAP) ? log.append("") : log.append(create_log_message(DIFF_CAP, F_CAP, S_CAP));
    IS_TRUE(F_SIZE == S_SIZE) ? log.append("") : log.append(create_log_message(DIFF_SIZE, F_SIZE, S_SIZE)) ;
    IS_TRUE(value_compare(vf, vs)) ? log.append("") : log.append(create_log_message(DIFF_VAL));
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
    g_test(vf, vs, log); 
    std::cout << log << std::endl;
}

/**
 * Tests assign function.
 */
void assign() {
    std::cout << __FUNCTION__<< ": ";
    std::string log;
    ft::vector<int> vf;
    std::vector<int> vs;
    vf.assign(0, 2);
    vs.assign(0, 2);
    IS_TRUE(vf.empty() == vs.empty()) ? log.append(""): log.append(NOT_EMPTY);
    g_test(vf, vs, log); 
    vf.assign(10, 1);
    vs.assign(10, 1);
    g_test(vf, vs, log); 
    vf.assign(5, 2);
    vs.assign(5, 2);
    g_test(vf, vs, log); 
    std::cout << log << std::endl;
}

void resize() {
    std::cout << __FUNCTION__ << ": ";
    std::string log;
    ft::vector<int> vf;
    std::vector<int> vs;
    /*TEST 0*/
    vf.resize(1);
    vs.resize(1);
    g_test(vf, vs, log); 
    /*TEST 1*/
    vf.reserve(5);
    vs.reserve(5);
    g_test(vf, vs, log); 
    /*TEST 2*/
    vf.assign(10, 2);
    vs.assign(10, 2);
    vf.resize(5);
    vs.resize(5);
    g_test(vf, vs, log); 
    /*TEST 3*/
    vf.resize(11);
    vs.resize(11);
    g_test(vf, vs, log); 
    /*TEST 4*/
    vf.resize(20);
    vs.resize(20);
    g_test(vf, vs, log); 
    /*TEST 5*/
    vf.resize(25, 3);
    vs.resize(25, 3);
    g_test(vf, vs, log); 
    /*TEST 6*/
    vf.resize(20, 3);
    vs.resize(20, 3);
    g_test(vf, vs, log); 
    std::cout << log << std::endl;
}

void max_size() {
    std::cout << __FUNCTION__ << ": ";
    std::string log;
    ft::vector<int> vf;
    std::vector<int> vs;
    /*TEST 1*/
    IS_TRUE(vf.size() == vs.size()) ? log.append(""): log.append(NOT_EMPTY);
    /*TEST 2*/
    ft::vector<std::string> vfs;
    std::vector<std::string> vss;
    IS_TRUE(vfs.size() == vss.size()) ? log.append(""): log.append(NOT_EMPTY);
    std::cout << log << std::endl;
}

void at() {
    std::cout << __FUNCTION__ << ": ";
    std::string log;
    ft::vector<int> vf(10, 3);
    std::vector<int> vs(10, 3);
    IS_TRUE(vf.at(0) == vs.at(0)) ? log.append(""): log.append(DIFF_VAL, vf.at(0), vs.at(0));
    IS_TRUE(vf.at(9) == vs.at(9)) ? log.append(""): log.append(DIFF_VAL, vf.at(9), vs.at(9));
    std::cout << log << std::endl;
}

void front() {
    std::cout << __FUNCTION__ << ": ";
    std::string log;
    ft::vector<int> vf(10, 3);
    std::vector<int> vs(10, 3);
    vf.front() = 4; 
    vs.front() = 4; 
    IS_TRUE(vf[0] == vf[0]) ? log.append(""): log.append(DIFF_VAL, vf[0], vs[0]);
    std::cout << log << std::endl;
}

void back() {
    std::cout << __FUNCTION__ << ": ";
    std::string log;
    ft::vector<int> vf(10, 3);
    std::vector<int> vs(10, 3);
    vf.back() = 4; 
    vs.back() = 4; 
    IS_TRUE(vf[9] == vf[9]) ? log.append(""): log.append(DIFF_VAL, vf[9], vs[9]);
    std::cout << log << std::endl;
}

void push_back() {
    std::cout << __FUNCTION__ << ": ";
    std::string log;
    ft::vector<int> vf;
    std::vector<int> vs;
    vf.push_back(1);
    vs.push_back(1);
    g_test(vf, vs, log); 
    ft::vector<int> vfs(2000, 3);
    std::vector<int> vss(2000, 3);
    vfs.push_back(1);
    vss.push_back(1);
    g_test(vf, vs, log); 
    std::cout << log << std::endl;
}

void pop_back() {
    std::cout << __FUNCTION__ << ": ";
    std::string log;
    ft::vector<int> vf(200, 3);
    std::vector<int> vs(200, 3);
    vf.pop_back();
    vs.pop_back();
    g_test(vf, vs, log); 
    IS_TRUE(vf[vf.size() - 1] == vs[vs.size() - 1]) ? log.append(""): log.append(DIFF_VAL, vf[ vf.size() - 1], vs[vs.size() - 1]);
    std::cout << log << std::endl;
}

int main ( void )
{
    is_empty();
    assign();
    resize();
    max_size();
    front();
    back();
    push_back();
    pop_back();
    /*
    int *v1 = &(v.front());
    *v1 = 2;
    std::cout << *v1 << std::endl;
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
