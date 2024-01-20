#pragma once

#include <iostream>
#include <memory>
#include <ostream>
namespace ft {
    
template<class T,class Allocator = std::allocator<T> > class list {

    /*------------------------------ Member Types -----------------------------*/
    public:

        typedef T                                                       value_type;
        typedef Allocator                                               allocator_type;
        typedef std::size_t                                             size_type;
        typedef std::ptrdiff_t                                          difference_type;
        typedef typename allocator_type::reference                      reference;
        typedef typename allocator_type::const_reference                const_reference;
        typedef typename allocator_type::pointer                        pointer;
        typedef typename allocator_type::const_pointer                  const_pointer;



    /*-----------------------Inner ListElement class--------------------------*/

    private:
    /**
     * Class representing an internal node of the linked list, holds data T 
     * as well as reference to previous and next element of list
    */
    class _ListElement {
        public:

            typedef T                                                           value_type;
            typedef typename Allocator::template rebind<_ListElement>::other    elem_allocator;
            typedef typename elem_allocator::pointer                            elem_pointer;

            _ListElement() : _data(nullptr), _prev(nullptr), _next(nullptr) {};
            
            _ListElement(const_reference value, elem_pointer prev, elem_pointer next, allocator_type &alloc) 
                : _data(0x0), _prev(prev), _next(next) {

                _data = alloc.allocate(1);
                alloc.construct(_data, value);
                if (prev != nullptr) {
                    _prev->_next = this;
                }
                if (_next != nullptr) {
                    _next->_prev = this;
                }
                std::cout << "Element " << *_data << " created in List" << std::endl;
            }


        private:


            pointer         _data;
            elem_pointer    _prev;
            elem_pointer    _next;



    };

    /*---------------------------Public list member function--------------------*/
    public:

    list() 
        : _head(0x0), 
        _tail(0x0),
        _elem_allocator(allocator_type()), 
        _allocator(allocator_type()),
        _count(0){};

    explicit list( const Allocator& alloc )
        : _head(0x0), 
        _tail(0x0), 
        _elem_allocator(alloc),
        _allocator(alloc),
        _count(0){
    };


    //TODO: set tail in first call
    void push_front(const T& value) {
        _ListElement *to_insert = _elem_allocator.allocate(1); 
        _elem_allocator.construct(to_insert, _ListElement(value, nullptr, _head, _allocator));
        _head = to_insert;
        _count++;
    }

    /*------------------------------ list attributes----------------------------*/
    private:
        _ListElement*                           _head;
        _ListElement*                           _tail;
        typename _ListElement::elem_allocator   _elem_allocator;
        allocator_type                          _allocator;
        size_type                               _count;

};
}
