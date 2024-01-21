#pragma once

#include <iostream>
#include <memory>
#include <ostream>
namespace ft {
    

template < class T, class Allocator = std::allocator< T > > class list {

    /*------------------------------ Member Types -----------------------------*/
public:
    typedef T                                        value_type;
    typedef Allocator                                allocator_type;
    typedef std::size_t                              size_type;
    typedef std::ptrdiff_t                           difference_type;
    typedef typename allocator_type::reference       reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::pointer         pointer;
    typedef typename allocator_type::const_pointer   const_pointer;

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

        _Node() : _prev( nullptr ), _next( nullptr ){};

        _Node( const_reference value,
               node_pointer    prev,
               node_pointer    next,
               allocator_type &alloc )
            : _prev( prev ),
              _next( next ) {

            // _data = alloc.allocate(1);
            alloc.construct( &_data, value );
            if ( prev != nullptr ) { _prev->_next = this; }
            if ( _next != nullptr ) { _next->_prev = this; }
            std::cout << "Element " << _data << " created in List" << std::endl;
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
            std::cout << "Node destructor Called" << std::endl;
            alloc.destroy(&_data);

        }

        node_pointer get_next() {
            return _next;
        }

        node_pointer get_prev() {
            return _prev;
        }

    private:
        value_type   _data;
        node_pointer _prev;
        node_pointer _next;
    };

    /*---------------------------Public list member function--------------------*/
public:
    list()
        : _head( 0x0 ),
          _tail( 0x0 ),
          _node_allocator( node_allocator() ),
          _allocator( allocator_type() ),
          _count( 0 ){};

    explicit list( const Allocator &alloc )
        : _head( 0x0 ),
          _tail( 0x0 ),
          _node_allocator( node_allocator() ),
          _allocator( alloc ),
          _count( 0 ){};

    /**
     * list destructor
     * Goes through the whole list and deletes node one by one
     */
    ~list() {
        std::cout << "Detructor called" << std::endl;
        node_pointer next = _head; 
        while (next != nullptr) {
            node_pointer toDel = next;
            next = toDel->get_next();
            delete_node(toDel);
        }
    }

    /**
     * Adds value in front of list
     * @param value - value to add to the list
     */
    void push_front( const T &value ) {
        _Node *to_insert = _node_allocator.allocate( 1 );
        _node_allocator.construct( to_insert, _Node( value, nullptr, _head, _allocator ) );
        _head = to_insert;
        //on first insertion tail = head = to_insert elem
        if (_tail == nullptr) {
            _tail = to_insert;
        }
        _count++; 
    }


    /*--------------list private member attributes and functions---------------*/
private:
    typedef typename allocator_type::template rebind< _Node >::other    node_allocator;
    typedef typename node_allocator::reference                          node_reference;
    typedef typename node_allocator::const_reference                    node_const_reference;
    typedef typename node_allocator::pointer                            node_pointer;
    typedef typename node_allocator::const_pointer                      node_const_pointer;

    node_pointer    _head;
    node_pointer    _tail;
    node_allocator  _node_allocator;
    allocator_type  _allocator;
    size_type       _count;

    /**
    * Deletes contents of a node with help of _allocator (allocator on type T)
    * Then deletes and frees memory of the node itself
    *
    * @param toDelete - Node to delete
    *
    */
    void delete_node(node_pointer toDelete) {
        (void) toDelete;
        toDelete->destroy(_allocator);
        _node_allocator.destroy(toDelete);
        _node_allocator.deallocate(toDelete, 1);
    } 
};
}
