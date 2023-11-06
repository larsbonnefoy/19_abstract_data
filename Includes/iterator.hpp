#pragma once
#include <iterator>

namespace ft {

template<class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&> 
struct iterator  
{
    typedef Category    iterator_category;
    typedef T           value_type;
    typedef Distance    difference_type;
    typedef Pointer     pointer;
    typedef Reference   reference;
};

/**
 * Random Access Iterator Class
 */
template<typename T>
class random_access_iterator : public iterator<std::random_access_iterator_tag, T> {

    typedef typename iterator<std::random_access_iterator_tag, T>::iterator_category    iterator_category;;
    typedef typename iterator<std::random_access_iterator_tag, T>::value_type           value_type;
    typedef typename iterator<std::random_access_iterator_tag, T>::difference_type      difference_type;
    typedef typename iterator<std::random_access_iterator_tag, T>::pointer              pointer;
    typedef typename iterator<std::random_access_iterator_tag, T>::reference            reference;

    private:
        pointer _ptr;

    public: 

        /**
         * Default Constuctor 
         *
         * @return Null ptr
         */
        random_access_iterator() : _ptr(0x0) {};

        /**
         * Pointer Constuctor 
         *
         * @param ptr - Underlying pointer address
         *
         * @return Null ptr
         */
        random_access_iterator(pointer ptr) : _ptr(ptr) {};


        /**
         * Copy Constuctor 
         *
         * @param other - other Iterator
         *
         * @return Null ptr
         */
        random_access_iterator(const random_access_iterator &other) : _ptr(other._ptr) {};

};

}
