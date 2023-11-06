#pragma once
#include <functional>
#include <iterator>

namespace ft {

template<class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&> 
struct iterator  
{
    typedef Category    iterator_category;
    typedef T           value_type;
    typedef Distance    difference_type;
    typedef Pointer     pointer;            //pointer and references to the underlying data type
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


        /**
         * Destructor
         */
        ~random_access_iterator() {};

        /**
         * Copy Assignation 
         *
         * @param other - other Iterator
         *
         * @return reference to copied Iterator
         */
        random_access_iterator &operator=(const reference other) {
            if (&other != this)
                _ptr = other._ptr;
            return *this;
        }

        //TODO
        //base();
        //*a = t

        /**
         * Iterator can be dereferenced as an rvalue;
         *
         * @return reference to Underlying pointer;
         *
         * @remark void because unary operator
         */
        reference operator*(void) {return *_ptr;}

        /**
         * Iterator can be dereferenced as an rvalue;
         *
         * @return underlying pointer;
         */
        pointer operator->(void) {return _ptr;}


        /**
         * Pre increment operator
         *
         * @return Reference to incremented iterator
         */
        random_access_iterator &operator++() {
            _ptr++;
            return *this;
        }

        /**
         * Post increment operator
         *
         * @return copy of non-incremented iterator
         */
        random_access_iterator operator++(int) {
            random_access_iterator ret = _ptr; 
            _ptr++;
            return ret;
        }

        /**
         * Pre decrement operator
         *
         * @return Reference to decremented iterator
         */
        random_access_iterator &operator--() {
            _ptr--;
            return *this;
        }

        /**
         * Post decrement operator
         *
         * @return copy of non-decremented iterator
         */
        random_access_iterator operator--(int) {
            random_access_iterator ret = _ptr; 
            _ptr--;
            return ret;
        }

        /**
         * Addition operator
         *
         * @param n - value to add to _ptr 
         *
         * @return copy of incremented iterator 
         */
        random_access_iterator operator+(difference_type n) const {
            return random_access_iterator(_ptr + n);
        }

        /**
         * Substraction operator
         *
         * @param n - value to substract to _ptr 
         *
         * @return copy of decremented iterator 
         */
        random_access_iterator operator-(difference_type n) const {
            return random_access_iterator(_ptr - n);
        }

        /**
         * Integer Addition operator
         *
         * @param n - value to add to _ptr 
         *
         * @return copy of incremented iterator 
         */
        random_access_iterator operator+(int n) const {
            return random_access_iterator(_ptr + n);
        }

        /**
         * Intefer Substraction operator
         *
         * @param n - integer value to substract to _ptr 
         *
         * @return copy of decremented iterator 
         */
        random_access_iterator operator-(int n) const {
            return random_access_iterator(_ptr - n);
        }

        /**
         * Compound decrement operations
         *
         * @return Reference to decremented iterator
         */
        random_access_iterator &operator-=(difference_type n) {
            _ptr -= n;
            return *this;
        }

        /**
         * Compound increment operations
         *
         * @return Reference to incremented iterator
         */
        random_access_iterator &operator+=(difference_type n) {
            _ptr += n;
            return *this;
        }

        reference operator[] (difference_type n) const {
            return _ptr[n];
        }
};

}
