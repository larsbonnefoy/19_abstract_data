#include <cstddef>
#include <iostream>
#include <limits>
#include <memory>

namespace ft {

template<class T,class Allocator = std::allocator<T> > class vector {

    typedef T                                           value_type;
    typedef Allocator                                   allocator_type;
    typedef std::size_t                                 size_type;
    typedef std::ptrdiff_t                              difference_type;
    typedef typename allocator_type::reference          reference;
    typedef typename allocator_type::const_reference    const_reference;
    

    private:
        T*              _data;
        allocator_type  _alloc;
        size_type       _size;
        size_type       _capacity;

    public:

        /**
         * Constructs an empty container
         * Complexity: Constant 
         *
         * @param none
         * @return empty vector
         */
        vector( void ) 
            : _data(0x0), _alloc(allocator_type()), _size(0), _capacity(0) {
        }

        /**
         * Constructs an empty container with the given alloctor alloc
         * Complexity: Constant 
         *
         * @param alloc - allocator used for memory allocation of this container
         * @return empty vector
         */
        explicit vector( const Allocator& alloc ) 
            : _data(0x0), _alloc(alloc), _size(0), _capacity(0) {
        }
        
        /**
         * Constructs the container with count copies of elements with value value
         * Complexity: Linear in count 
         *
         * @param count - size of the container
         * @param value - value to initialize elements of the container with 
         * @param alloc - allocator used for memory allocation of this container
         *
         * @return initialized vector
         */
        explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator() ) 
            : _alloc(alloc), _size(count) {

        }

        /**
         * Copy constructor. 
         * Constructs the container with the copy if the contents of other.
         * Complexity: Linear in size of other 
         *
         * @param other another container to be used as source to initialize elements of the container
         *
         * @return initialized vector
         */
        vector( const vector& other ) {
        }

        /* Iterator Constructor do to
         template< class InputIt >
            vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() );
        */

        /* ##Exceptions: std::allocator may throw
         *
         */

    /****************************Element access********************************/

    reference front(void) {
        return _data[0];
    }

    const_reference front(void) const {
        return _data[0];
    }

    reference back(void) {
        return _data[_size - 1];
    }

    const_reference back(void) const {
        return _data[_size - 1];
    }
    /***************************Iterators**************************************/
    //begin
    //end
    //rbegin
    //rend
    /***************************Capacity***************************************/
    //empty
    //size 
    //max_size 

    /**
     * Returns the maximum number of elements that the vector is able to hold 
     * due to system or library implementation limits.\n
     * Theoretical limit given by std::numeric_limits<difference_type>::max(),
     * at runtime the real value might be smaller given available RAM space.
     * 
     * @param none
     * @returns Maximum number of elements 
     */
    size_type max_size(void) const {
        return (_alloc.max_size());
    }

    /**
     * Requests that _capacity should at least contain new_cap elements.\n
     * If new_cap is greater than current vector _capacity, function causes 
     * container to reallocate, increasing capacity to n.\n
     * Complexity: if realloc happens, linear in vector_size at most\n
     *
     * @param new_cap - new capacity of the vector, in number of elements
     * @return none
     * @throws length_error - exception is size requested is greater than vector::max_size
     * @throws bad_alloc -  if reallocation fails due to lack of space (when default alloc is used) 
     */
    void reserve(size_type new_cap) {


    }

    //capacity
    /***************************Modifiers**************************************/
    //clear 
    //insert
    //erase 
    //push_back
    //pop_back 
    //rezise 
    //swap

};
}
