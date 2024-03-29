#pragma once

#include <cstddef>
#include <cstring>
#include <exception>
#include <iostream>
#include <memory>
#include "iterator.hpp"

namespace ft {

template<class T,class Allocator = std::allocator<T> > class vector {

    public:

        typedef T                                                       value_type;
        typedef Allocator                                               allocator_type;
        typedef std::size_t                                             size_type;
        typedef std::ptrdiff_t                                          difference_type;
        typedef typename allocator_type::reference                      reference;
        typedef typename allocator_type::const_reference                const_reference;
        typedef typename allocator_type::pointer                        pointer;
        typedef typename allocator_type::const_pointer                  const_pointer;
        typedef typename ft::random_access_iterator<value_type>         iterator;   
        typedef typename ft::random_access_iterator<const value_type>   const_iterator;   

        /**
         * Constructs an empty container\n
         * Complexity: Constant 
         *
         * @param none
         * @return empty vector
         */
        vector( void ) 
            : _data(0x0), _allocator(allocator_type()), _size(0), _capacity(0) {
        }

        /**
         * Constructs an empty container with the given allocator alloc\n
         * Complexity: Constant 
         *
         * @param alloc - allocator used for memory allocation of this container
         * @return empty vector
         */
        explicit vector( const Allocator& alloc ) 
            : _data(0x0), _allocator(alloc), _size(0), _capacity(0) {
        }
        
        /**
         * Constructs the container with count copies of elements with value value\n
         * Complexity: Linear in count 
         *
         * @param count - size of the container
         * @param value - value to initialize elements of the container with 
         * @param alloc - allocator used for memory allocation of this container
         *
         * @return initialized vector
         *
         */
        explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator() ) 
            :  _allocator(alloc), _size(count), _capacity(count) {
                _data = _allocator.allocate(_capacity);
                assign(count, value);
        }

        /**
         * Copy constructor. 
         * Constructs the container with the copy if the contents of other.\n
         * Complexity: Linear in size of other 
         *
         * @param other another container to be used as source to initialize elements of the container
         *
         * @return initialized vector
         */
        vector( const vector& other ) {
            (void) other;
        }

        /**
         * Destroys all container elements and deallocates capacity
         */
        ~vector( void ) {
            for (size_type i = 0; i < _size; i++) {
                _allocator.destroy(&_data[i]);
            }
            _allocator.deallocate(_data, _capacity);
        }
        
        /*
        //TODO: finish
        template< class InputIt >
        vector( InputIt first, InputIt last, const Allocator& alloc = Allocator()) 
            : _allocator(alloc), _size(last - first), _capacity(last - first) {
                _data = _allocator.allocate(_capacity);
        }
        */

        /**
         * Copies all the elements from x into the container, replacing current 
         * contents and modifying size accordinly.
         *
         * @param other - another container used as source
         *
         * @remark Complexity: linear in the size of `*this` and `other`
         */
        
        /*
        vector& operator=(const vector& other) {
            (void) other;
            return *this;
        }
        */


    /****************************Modifiers*************************************/

        /**
         * Replaces the contents with count copies of value.\n
         * Complexity: Linear in count
         *
         * @param count - new size of the container
         * @param value - value to initialize the container with
         *
         * @return none
         *
         * @remark If count > capacity, reallocation takes place but values are 
         * overridden.
         * @remark All iterators, pointers and references are invalidated.
         *
         */
        void assign( size_type count, const T& value ) {
            reserve(count);
            for (size_type i = 0; i < count; i++) {
                _allocator.construct(&_data[i], value);
            }
            _size = count;
        }

        /**
         * Replaces contents with copies in the range [first, last(
         *
         * @remark Behaviour undefined if one of the arguments is an iterator into *this
         */

        template< class InputIt >
        void assign( InputIt first, InputIt last) {
            reserve(last - first);
            for (size_type i = 0; first + i != last; i++) {
                std::cout << *(first + i) << std::endl;
                _allocator.construct(&_data[i], *(first + i));
            }
            _size = last - first;
        }

        /**
         * Returns allocator associated with container 
         *
         * @param none
         *
         * @return associated allocator
         */
        allocator_type get_allocator() const {return _allocator;}

    /****************************Element access********************************/
    //TODO write correct exception
    /**
     * Returns a reference to the element at specified location pos, with bound
     * checking.\n
     *
     * @param pos -  Index of wanted element
     *
     * @returns reference to specified element
     *
     * @throws ft::out_of_range if pos is not within the range of the container 
     */
    reference at(size_type pos) {
        if (pos + 1 > _size) {
            throw std::exception();
        }
        return (_data[pos]);
    }

    //TODO write correct exception
    /**
     * Returns a const reference to the element at specified location pos, with 
     * bound checking.\n
     *
     * @param pos -  Index of wanted element
     *
     * @returns const reference to specified element
     *
     * @throws ft::out_of_range if pos is not within the range of the container 
     */
    const_reference at(size_type pos) const {
        if (pos + 1 > _size) {
            throw std::exception();
        }
        return (_data[pos]);
    }

    /**
     * Returns a const reference to the element at specified index pos, without
     * bound checking.\n
     *
     * @param pos -  Index of wanted element
     *
     * @returns const reference to specified element
     *
     * @remark Access out of bond element results in undefined behaviour
     */
    reference operator[](size_type pos) {
        return (_data[pos]);
    }

    /**
     * Returns reference to first element of container
     *
     * @returns reference to first element
     */
    reference front(void) {
        return _data[0];
    }

    /**
     * Returns const reference to first element of container
     *
     * @returns const reference to first element
     */
    const_reference front(void) const {
        return _data[0];
    }

    /**
     * Returns reference to last element of container
     *
     * @returns reference to last element
     */
    reference back(void) {
        return _data[_size - 1];
    }

    /**
     * Returns reference to last element of container
     *
     * @returns reference to last element
     */
    const_reference back(void) const {
        return _data[_size - 1];
    }

    /**
     * Returns a pointer to the underlying array serving as storage
     *
     * @param none
     *
     * @returns pointer to underlying element storage
     */
    pointer data( void ) {
        return _data;
    }

    /**
     * Returns a const pointer to the underlying array serving as storage
     *
     * @param none
     *
     * @returns const pointer to underlying element storage
     */
    const pointer data( void ) const {
        return _data;
    }

    /***************************Iterators**************************************/

    /**
     * Returns random access iterator to the first element 
     *
     * @param none
     *
     * @return random access iterator to the first element
     *
     * @remark if container is empty, iterator should not be dereferenced as 
     * underlying pointer = 0
     */
    iterator begin(void) {return _data;}

    /**
     * Returns random access iterator to the const first element 
     *
     * @param none
     *
     * @return random access iterator to the const first element
     *
     * @remark if container is empty, iterator should not be dereferenced as 
     * underlying pointer = 0
     */
    const_iterator begin(void) const {return _data;}

    /**
     * Returns random access iterator to *past-the-end* element.\n
     * It is the theoretical element after the last element.\n
     *
     * It does not point to anything so it should not be dereferenced.
     *
     * @param none
     *
     * @return random access iterator to last + 1
     *
     * @remark if container is empty, iterator should not be dereferenced as 
     * underlying pointer = 0, returns the same as begin
     */
    iterator end(void) {return _data + _size;}

    /**
     * Returns random access iterator to const *past-the-end* element.\n
     * It is the theoretical element after the last element.\n
     * It does not point to anything so it should not be dereferenced.
     * 
     *
     * @param none
     *
     * @return random access iterator to const last + 1
     *
     * @remark if container is empty, iterator should not be dereferenced as 
     * underlying pointer = 0, returns the same as begin
     */
    const_iterator end(void) const {return _data + _size;}
    
    //rbegin
    //rend
    /***************************Capacity***************************************/


    /**
     * Checks if container is empty, ie if begin() == end()
     */
    bool empty( void ) {
        return (!_size);
    }

    /**
     * Returns number of elements in the container
     *
     * @param  none
     *
     * @returns number of elements in the container
     */
    size_type size( void ) const {
        return (_size);
    }

    /**
     * Returns the maximum number of elements that the vector is able to hold 
     * due to system or library implementation limits.\n
     * Theoretical limit given by std::numeric_limits<difference_type>::max(),
     * at runtime the real value might be smaller given available RAM space.
     * 
     * @param none
     *
     * @returns Maximum number of elements 
     */
    size_type max_size(void) const {
        return (_allocator.max_size());
    }

    //TODO: write correct exception
    //TODO: probably better way to copy data over
    /**
     * Requests that _capacity should at least contain new_cap elements.\n
     * If new_cap is greater than current vector _capacity, function causes 
     * container to reallocate  increasing capacity to new_cap.\n
     * Complexity: if realloc happens, linear in vector_size at most.\n
     *
     * @param new_cap - new capacity of the vector, in number of elements
     *
     * @return none
     *
     * @throws length_error - exception is size requested is greater than vector::max_size
     * @throws bad_allocator -  if reallocation fails due to lack of space (when default alloc is used) 
     *
     * @remark Usefull if number of elements is known in advance. Can allocate 
     * without instanciation right amount of data, eliminates need to reallocate when vector grows
     * @remark If an error is thrown by allocation or max_size, leaves vector in his previous state
     */
    void reserve(size_type new_cap) {
        if (new_cap > this->max_size()) {
            throw std::exception();
        }
        if (new_cap > _capacity) {
            pointer newData = _allocator.allocate(new_cap); 
            if (_data) {
                copy_data(newData);
            }
            _data = newData;
            _capacity = new_cap;
        }
    }

    /**
     * Returns capacity of the container
     *
     * @param  none
     *
     * @returns capacity of the container
     */
    size_type capacity() const {
        return (_capacity);
    }
    /***************************Modifiers**************************************/
    /**
     * Erases all the elements of the container, each element is destroyed.\n
     * Leaves container with a size of 0.\n
     * Leaves capacity unchanged.\n
     *
     * @param none
     *
     * @return none
     * 
     * @remark Complexity linear in size of container
     * @remark Invalidates any reference, pointer or iterator reffering to the 
     * contained elements
     */
    void clear( void ) {
        for (size_type i = 0; i < _size; i++) {
            _allocator.destroy(&_data[i]);
        }
        _size = 0;
    }

    /**
     * Insert value before pos;
     *
     * @param pos - iterator before which content will be inserted
     *
     * @param value - element value to insert
     *
     * @return Iterator pointing to the inserted value
     */
    iterator insert( const_iterator pos, const T& value ) {
        (void) pos;
        (void) value;

    }

    /**
     * Insert count values before pos;
     *
     */
    iterator insert( const_iterator pos, size_type count, const T& value );

    /**
     * Insert elements from [first ; last) before pos.\n
     *
     *
     * @param first start of elements to insert
     *
     * @param last  last element to insert, not included
     *
     * @remark Undefined behaviour is first and last are iterators into *this
     */
    template< class InputIt >
    iterator insert( const_iterator pos, InputIt first, InputIt last );
    //erase 

    //https://stackoverflow.com/questions/13822880/linked-list-vs-dynamic-array-for-implementing-a-stack-using-vector-class
    /**
     * Adds new element at the end of vector.\n
     * New element is initialized as a copy of value.\n
     * If new size is bigger than previous capacity, reallocation takes place.\n
     * Reallocates by a factor of 2. (In more modern implementation this factor is 1.5).\n
     *
     * @param value - the value of the element to append
     *
     * @return none
     *
     * @throws exception related to allocator or element copy/move constructor/assignment.
     *
     * @remark Complexity: Amortized constant //TODO: check why Amortized
     * @remark If reallocation happens, all references, pointers or iterators 
     * related to the underlying data are invalidated
     * @remark If an error is thrown this function has no effect (= strong exception
     * guarantee) 
     */
    void push_back(const_reference value) {
        if (_size  == _capacity) {
            reserve(_capacity * 2 | !_capacity);
        }
        _allocator.construct(&_data[_size], value);
        _size += 1;
    }

    /**
     * Removes last element of container
     *
     * @param none
     *
     * @return none
     *
     * @remark Calling pop_back on empty container is undefined.
     * @remark Iterators, pointers and references to the last element are unvalidated.
     */
    void pop_back(void) {
        _allocator.destroy(_data + _size - 1);
        _size--;
    }
    
    //TODO: use insert and erase
    /**
     * Resizes the container to count elements, does nothing if count == size.\n
     *
     * If size > count, container is reduced to its first count elements.\n
     *
     * If size < count, additional value elements are appended.\n 
     *
     * @param count - New size of the container
     * @param value - Value to append if size < count
     *
     * @return none
     *
     * @remark Complexity: Linear in the difference between current size and count.
     * Additional Complexity is possible due to reallocation.
     * @remark Vector capacity is not reduced to avoid invalidating all iterators.
     * Only those affected by pop_back() call are invalidated.
     * 
     */
    void resize(size_type count, value_type val = value_type()) {
        if (_size > count) {
            while (_size != count) {
                pop_back(); //pop back already decreases size by 1
            }
        }
        else if (_size < count) {
            if (count > _capacity) {
                reserve(_capacity * 2 | !_capacity);
            }
            while (_size < count) { 
                _allocator.construct(&_data[_size], val);
                _size++;
            }
        }
    }
    
    //swap

    private:
        pointer         _data;
        allocator_type  _allocator;
        size_type       _size;
        size_type       _capacity;

        /**
         * Copies data from _data to newData.\n
         * Destroys and deallocate previous _data.\n
         */
        void copy_data(pointer newData) {
            for (size_type i = 0; i < _size; i++) {
                _allocator.construct(&newData[i], _data[i]);
            }
            for (size_type i = 0; i < _size; i++) {
                _allocator.destroy(&_data[i]);
            }
            _allocator.deallocate(_data, _capacity);
        }


};
}
