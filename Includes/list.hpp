#pragma once

#include <cstddef>
#include <iostream>
#include <memory>
#include <ostream>
#include "iterator.hpp"
namespace ft {
    

template < class T, class Allocator = std::allocator< T > > class list {

    template<typename U>
    class Iterator;


    class _Node;


    /*------------------------------ Member Types -----------------------------*/
public:

    typedef T                                           value_type;
    typedef Allocator                                   allocator_type;
    typedef std::size_t                                 size_type;
    typedef std::ptrdiff_t                              difference_type;
    typedef typename allocator_type::reference          reference;
    typedef typename allocator_type::const_reference    const_reference;
    typedef typename allocator_type::pointer            pointer;
    typedef typename allocator_type::const_pointer      const_pointer;
    typedef Iterator< value_type >                      iterator;
    typedef Iterator< const value_type >                const_iterator;
    typedef reverse_iterator<Iterator<value_type> >     reverse_iterator;

private :

    typedef typename allocator_type::template rebind< _Node >::other    node_allocator;
    typedef typename node_allocator::reference                          node_reference;
    typedef typename node_allocator::const_reference                    node_const_reference;
    typedef typename node_allocator::pointer                            node_pointer;
    typedef typename node_allocator::const_pointer                      node_const_pointer;

    /*---------------------------Iterator Implementation--------------------*/
    /**
     * Requirements for typedefs ?
     * normally already in struct iterator
     */
    template<typename U>
    class Iterator : public ft::iterator<ft::bidirectional_iterator_tag, U> {


        public:

        friend class list<T, Allocator>;

        Iterator() : _node(nullptr) {}
        Iterator(node_pointer node) : _node(node) {}
        Iterator(const Iterator &other) : _node(other._node){} 
        ~Iterator(){}

        iterator &operator=(const iterator &other) {
            if (&other != this)
                _node = other._node;
            return *this;
        }

        //reference and pointer are of the underlying type U
        reference operator*(void) {return _node->get_data();}
        pointer operator->(void) {return &(operator*());}

        /**
         * Pre increment iterator
         * Returns incremented object directly
         */
        iterator &operator++() {
            _node = _node->get_next();
            return *this;
        }

        /**
         * Post increment iterator
         * Returns copy of item before increment
         */
        iterator operator++(int) {
            iterator old = iterator(*this);
            _node = _node->get_next();
            return old;
        } 

        /**
         * Pre decr iterator
         * Returns decr object directly
         */
        iterator &operator--() {
            _node = _node->get_prev();
            return *this;
        }

        /**
         * Post decr iterator
         * Returns copy of item before decr
         */
        iterator operator--(int) {
            iterator old = iterator(*this);
            _node = _node->get_prev();
            return old;
        } 

        /**
         * Equal operator
         * @returns true if equal
         */
        bool operator==(const iterator& rhs) const {
            return (_node == rhs._node);
        }

        /**
         * Difference operator
         * @returns false if different
         */
        bool operator!=(const iterator& rhs) const {
            return (_node != rhs._node);
        }

        private:

            node_pointer _node;

        
    };



    /*-----------------------Inner ListElement class--------------------------*/

private:
    /**
     * Class representing an internal node of the linked list, holds data T
     * as well as reference to previous and next element of list
    */
    class _Node {
    public:
        typedef typename allocator_type::template rebind< _Node >::other
                                                         node_allocator;
        typedef typename node_allocator::reference       node_reference;
        typedef typename node_allocator::const_reference node_const_reference;
        typedef typename node_allocator::pointer         node_pointer;
        typedef typename node_allocator::const_pointer   node_const_pointer;

        //Used to init _past_end node
        _Node() : _prev( nullptr ), _next( nullptr ){};

        _Node( const_reference value,
               node_pointer    prev,
               node_pointer    next,
              node_pointer current)
            : _data(value), 
              _prev( prev ),
              _next( next ) {
            
            if ( prev != nullptr ) { _prev->_next = current; }
            if ( next != nullptr ) { _next->_prev = current; }
        }

        /**
         * Copy Constructor
         * Sets prev and next pointer to null but copies content of node other to
         * this node
         * @param other - Node to copy
         */
        _Node( const _Node &other, allocator_type &alloc )
            : _prev( nullptr ),
              _next( nullptr ) {
            alloc.construct( &_data, other.value );
        }


        /**
         * Calls destructor on value held by element
         * @param   alloc - element  allocator that allocated value
         *          required to delete same value
         */
        void destroy(allocator_type &alloc) {
            alloc.destroy(&_data);
        }

        node_pointer get_next() {
            return _next;
        }

        node_pointer get_prev() {
            return _prev;
        }

        reference get_data() {
            return _data;
        }

        void set_prev(node_pointer node) {
            _prev = node;
        }

    private:
        value_type      _data;
        node_pointer    _prev;
        node_pointer    _next;
    };



    /*---------------------------Public list member function--------------------*/
public:
    /******************************Member function**********************/
    /**
     * Default constructor. Constructs empty container with default-constructed
     * allocator
     */
    list()
        : _head( 0x0 ),
        _node_allocator( node_allocator() ),
        _allocator( allocator_type() ),
        _count( 0 ) {
            _past_end = _node_allocator.allocate(1);
            _node_allocator.construct(_past_end, _Node());
        };

   /**
     * Constructs empty container with given allocator alloc
     */
    explicit list( const Allocator &alloc )
        : _head( 0x0 ),
        _node_allocator( node_allocator() ),
        _allocator( alloc ),
        _count( 0 ){
            _past_end = _node_allocator.allocate(1);
            _node_allocator.construct(_past_end, _Node());
        };

    /**
     * list destructor
     * Goes through the whole list and deletes node one by one
     * Special treatment for past_end node as it does not hold
     * value_type;
     */
    ~list() {
        node_pointer next = _head; 
        while (next != _past_end) {
            node_pointer toDel = next;
            next = toDel->get_next();
            delete_node(toDel);
        }
        _node_allocator.destroy(_past_end);
        _node_allocator.deallocate(_past_end, 1);
    }


    /******************************Element access***********************/
    /**
     * Returns reference to first element in container
     * @returns reference to first element in container
     */
    reference front() {
        return (_head->get_data());
    }
    
    /**
     * Returns const reference to first element in container
     * @returns const reference to first element in container
     */
    const_reference front() const {
        return (_head->get_data());
    }

    /**
     * Returns reference to last element in container
     * @returns reference to last element in container
     */
    reference back() {
        return (_past_end->get_prev());
    }
    
    /**
     * Returns const reference to last element in container
     * @returns const reference to last element in container
     */
    const_reference back() const {
        return (_past_end->get_prev());
    }

    /*--------------Iterator Functions---------------*/
    /**
     * Returns iterator to start of container
     */
    iterator begin() {
        return iterator(_head); 
    }

    /**
     * Returns const iterator to start of container
     */
    const_iterator begin() const {
        return iterator(_head);
    }
    
    /**
     * Returns iterator one past the end to start of container
     */
    iterator end() {
        return iterator(_past_end);
    }

    /**
     * Returns const iterator one past the end to start of container
     */
    const_iterator end() const {
        return iterator(_past_end);
    }


    reverse_iterator rbegin() {
        return reverse_iterator(_past_end);
    }

    reverse_iterator rend() {
        return reverse_iterator(_head);
    }

    /*-----------------------Capacity------------------------*/
    /**
     * //TODO: check with std::distance(begin(), end())
     * Returns the number of elements in the container 
     *
     * @return Number of elements in the container
     */
    size_type size() const {
        return _count;
    }

    /**
     * 
     * Verifies if container is empty
     *
     * @return bool - True if empty false else
     */
    bool empty() const {
        return (size() == 0);
    }

    /*
     * Returns the maximum number of elements that the list is able to hold 
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

    /*-----------------------Modifiers-----------------------*/
    /**
     * //TODO: add const iterator and check validity of insertion
     * Inserts value before pos;
     * @param value - value to add to the list
     */
    iterator insert( iterator pos, const T& value ) {
        node_pointer to_insert = _node_allocator.allocate(1);
        if (pos._node) {
            _node_allocator.construct( to_insert, _Node( value, pos._node->get_prev(), pos._node, to_insert) );
        }
        //if _node == nullptr: we insert first element with begin();
        //=> set next element as past_end
        else {
            _node_allocator.construct( to_insert, _Node( value, nullptr, _past_end, to_insert) );
        }
        if (pos._node == _head) {
            _head = to_insert;
        }
        if (pos._node == _past_end) {
            _past_end->set_prev(to_insert);
        }
        _count++; 
        return iterator(to_insert);
    }

    /**
     * Adds value in front of list
     * @param value - value to add to the list
     */
    void push_front( const T &value ) {
        insert(begin(), value);
    }

    /**
     * Adds value at end of list
     * @param value - value to add to the list
     */
    void push_back( const T &value ) {
        insert(end(), value);
    }


    void display_list() {
        node_pointer current = _head;
        std::cout << "(";
        while (current != _past_end) {
            std::cout << current->get_data() << " ";
            current = current->get_next();
        }
        std::cout << ")" << std::endl;
    }


    /*--------------list private member attributes and functions---------------*/
private:

    node_pointer    _head;
    node_allocator  _node_allocator;
    allocator_type  _allocator;
    size_type       _count;
    
    //sentinel node used to store past the end element 
    //=> _tail->next = _past_end and _past_end->prev = _end;
    node_pointer    _past_end;

    /**
    * Deletes contents of a node with help of _allocator (allocator on type T)
    * Then deletes and frees memory of the node itself
    *
    * @param toDelete - Node to delete
    *
    */
    void delete_node(node_pointer toDelete) {
        toDelete->destroy(_allocator);
        _node_allocator.destroy(toDelete);
        _node_allocator.deallocate(toDelete, 1);
    } 
};
}
