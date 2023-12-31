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
    //pointer and references to the underlying data type, not iterator itself
};

/**
 * Random Access Iterator Class
 */
template<typename T>
class random_access_iterator : public iterator<std::random_access_iterator_tag, T> {

    public: 

        typedef typename iterator<std::random_access_iterator_tag, T>::iterator_category    iterator_category;;
        typedef typename iterator<std::random_access_iterator_tag, T>::value_type           value_type;
        typedef typename iterator<std::random_access_iterator_tag, T>::difference_type      difference_type;
        typedef typename iterator<std::random_access_iterator_tag, T>::pointer              pointer;
        typedef typename iterator<std::random_access_iterator_tag, T>::reference            reference;

        /**
         * Default Constuctor 
         *
         */
        random_access_iterator() : _ptr(0x0) {};

        /**
         * Pointer Constuctor 
         *
         * @param ptr - Underlying pointer address
         *
         */
        random_access_iterator(pointer ptr) : _ptr(ptr) {};


        /**
         * Copy Constuctor 
         *
         * @param other - other Iterator
         *
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

        /**
         * Returns underlying pointer
         */
        pointer base() const {return _ptr;}

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

        /**
         * Accesses the element located n positions away from the element currently pointed to by the iterator.
         *
         * @param n - Position of element to access
         *
         * @return reference to _ptr + n element
         */
        reference operator[] (difference_type n) const {return _ptr[n];}

    private:
        pointer _ptr;

};

/**
 * Function template.\n
 * Compares if underlying pointer x is smaller or equal to y 
 *
 * @param x - First iterator to compare
 * @param y - Second iterator to compare
 *
 * @return boolean
 */
template<class Iter1, class Iter2>
bool operator<=(const random_access_iterator<Iter1>& x, const random_access_iterator<Iter2>& y){
    return x.base() <= y.base();
}

/**
 * Function template.\n
 * Compares if underlying pointer x is strictly smaller than y 
 *
 * @param x - First iterator to compare
 * @param y - Second iterator to compare
 *
 * @return boolean
 */
template<class Iter1, class Iter2>
bool operator<(const random_access_iterator<Iter1>& x, const random_access_iterator<Iter2>& y){
    return x.base() < y.base();
}

/**
 * Function template.\n
 * Compares if underlying pointer x is equal to y 
 *
 * @param x - First iterator to compare
 * @param y - Second iterator to compare
 *
 * @return boolean
 */
template<class Iter1, class Iter2>
bool operator==(const random_access_iterator<Iter1>& x, const random_access_iterator<Iter2>& y){
    return x.base() == y.base();
}

/**
 * Function template.\n
 * Compares if underlying pointer x if different than y 
 *
 * @param x - First iterator to compare
 * @param y - Second iterator to compare
 *
 * @return boolean
 */
template<class Iter1, class Iter2>
bool operator!=(const random_access_iterator<Iter1>& x, const random_access_iterator<Iter2>& y){
    return x.base() != y.base();
}

/**
 * Function template.\n
 * Compares if underlying pointer x is strictly greater than y 
 *
 * @param x - First iterator to compare
 * @param y - Second iterator to compare
 *
 * @return boolean
 */
template<class Iter1, class Iter2>
bool operator>(const random_access_iterator<Iter1>& x, const random_access_iterator<Iter2>& y){
    return x.base() > y.base();
}

/**
 * Function template.\n
 * Compares if underlying pointer x is greater or equal to y 
 *
 * @param x - First iterator to compare
 * @param y - Second iterator to compare
 *
 * @return boolean
 */
template<class Iter1, class Iter2>
bool operator>=(const random_access_iterator<Iter1>& x, const random_access_iterator<Iter2>& y){
    return x.base() >= y.base();
}

/**
 * Function template.\n
 * Returns distance between lhs and rhs
 *
 * @param n - value to add to
 * @param it - iterator to add to
 *
 * @return boolean
 *
 * @remark, need this function to make it possible to write addition bewteen 
 * integer and iterator where integer is on the lhs of operation
 * https://stackoverflow.com/questions/4622330/operator-overloading-member-function-vs-non-member-function
 *
 */
template<class Iterator>
typename ft::random_access_iterator<Iterator> operator+(typename ft::random_access_iterator<Iterator>::difference_type n, const random_access_iterator<Iterator>& it) {
    return (random_access_iterator<Iterator>(it + n));
}

/**
 * Function template.\n
 * Returns distance between lhs and rhs
 *
 * @param x - First iterator to compare
 * @param y - Second iterator to compare
 *
 * @return boolean
 */
template<class Iterator>
typename ft::random_access_iterator<Iterator>::difference_type operator-(const random_access_iterator<Iterator>& lhs, const random_access_iterator<Iterator>& rhs) {
    return lhs.base() - rhs.base();
}
}
