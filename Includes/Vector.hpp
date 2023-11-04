#include <cstddef>
#include <cstring>
#include <exception>
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
    typedef typename allocator_type::pointer            pointer;
    

    private:
        pointer         _data;
        allocator_type  _allocator;
        size_type       _size;
        size_type       _capacity;

    public:

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
         * Destructs the vector
         */
        ~vector( void ) {
            for (size_type i = 0; i < _size; i++) {
                _allocator.destroy(&_data[i]);
            }
            _allocator.deallocate(_data, _capacity);
        }
        
        //TODO
        /* Iterator Constructor do to
         template< class InputIt >
            vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() );
        */


        //TODO check if use Iterator to fill in the container
        //reallocation if to many values are copied
        /**
         * Replaces the contents with count copies of value.\n
         * Complexity: Linear in count
         *
         * @param count - new size of the container
         * @param value - value to initialize the container with
         *
         * @return none
         *
         */
        void assign( size_type count, const T& value ) {
            for (size_type i = 0; i < count; i++) {
                _allocator.construct(&_data[i], value);
            }
        }

        /*//TODO 
        template< class InputIt >
        void assign( InputIt first, InputIt last ) {

        }
         */

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
    //begin
    //end
    //rbegin
    //rend
    /***************************Capacity***************************************/


    /**
     * Checks if container is empty, ie if begin() == end()
     */
    bool empty( void ) {
        if (_size == 0) {
            return true;
        }
        return false;
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
     * withouth instanciation right amount of data, eleminates need to reallocate when vector grows
     * @remark If an error is thrown, leaves vector in his previous state
     */
    void reserve(size_type new_cap) {
        if (new_cap > this->max_size()) {
            throw std::exception();
        }
        if (new_cap > _capacity) {
            size_type oldCapacity = _capacity;
            pointer newData = _allocator.allocate(new_cap); 
            for (size_type i = 0; i < _size; i++) {
                _allocator.construct(&newData[i], _data[i]);
            }
            for (size_type i = 0; i < _size; i++) {
                _allocator.destroy(&_data[i]);
            }
            _allocator.deallocate(_data, oldCapacity);
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

    //insert
    //erase 

    /**
     * Adds new element at the end of vector.\n
     * New element is initialized as a copy of value.\n
     * If new size is bigger than previous capacity, reallocation takes place.\n
     * Reallocates by a factor of 2. (In more modern implementation this factor is 1.5).\n
     *
     * @param value - the value of the element to append
     *
     * @returns none
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
        if (_size + 1 > _capacity) {
            reserve(_capacity * 2);
        }
        _allocator.construct(&_data[_size], value);
        _size += 1;
    }
    //pop_back 
    //rezise 
    //swap

};
}
