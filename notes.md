# List
## TO CHECK
- Template specialization and templated subnesting
-> Should iterator be define outside and using friend
keyword?

- Allocator, allocate and construct, how to avoid passing
addr to constructor

-Iterator invalidation

-> Delete tail operator and use past_end instead, tail = past_end->prev;

## Functions to add:
### Member functions
[ ] explicit list( size_type count, const T& value = T(), const Allocator& alloc = Allocator() );

[ ] template< class InputIt > 
list( InputIt first, InputIt last, const Allocator& alloc = Allocator() );

[ ] list& operator=( const list& other );

[ ] void assign( size_type count, const T& value );

[ ] template< class InputIt >
void assign( InputIt first, InputIt last );

[ ] allocator_type get_allocator() const;

### Element access
[x] reference front();

[x] const_reference front() const;

[x] reference back();

[x] const_reference back() const;

### IT 
[x] iterator begin();;

[x] iterator end();;

[ ] const_iterator begin() const;

[ ] const_iterator end() const;

[ ] reverse_iterator rbegin();

[ ] reverse_iterator rend();

[ ] const_reverse_iterator rbegin() const;

[ ] const_reverse_iterator rend() const;

### Capacity

[X] bool empty() const;

[X] size_type size() const;

[X] size_type max_size() const;

### Modifiers
[ ] void clear();

[ ] iterator insert( const_iterator pos, const T& value );

[ ] iterator insert( const_iterator pos, size_type count, const T& value );

[ ] template< class InputIt >
iterator insert( const_iterator pos, InputIt first, InputIt last );

[ ] iterator erase( iterator pos );

[ ] iterator erase( iterator first, iterator last );

[ ] void pop_back();

[ ] void pop_front();

[ ] void resize( size_type count );

[ ] void resize( size_type count, const value_type& value );

[ ] void swap( list& other );

### Operations
[ ] void merge( list& other );

[ ] template< class Compare >
void merge( list& other, Compare comp );

[ ] void splice( const_iterator pos, list& other );

[ ] void splice( const_iterator pos, list& other, const_iterator it );

[ ] void splice( const_iterator pos, list& other, const_iterator first, const_iterator last);

[ ] void remove( const T& value );

[ ] template< class UnaryPredicate >
void remove_if( UnaryPredicate p );

[ ] void reverse();

[ ] void unique();

[ ] template< class BinaryPredicate >
void unique( BinaryPredicate p );

[ ] void sort();

[ ] template< class Compare >
void sort( Compare comp );

### Non Member functions
[ ] template< class T, class Alloc >
bool operator==( const std::list<T, Alloc>& lhs,
                 const std::list<T, Alloc>& rhs );

[ ] template< class T, class Alloc >
bool operator!=( const std::list<T, Alloc>& lhs,
                 const std::list<T, Alloc>& rhs );

[ ] template< class T, class Alloc >
bool operator<( const std::list<T, Alloc>& lhs,
                const std::list<T, Alloc>& rhs );

[ ] template< class T, class Alloc >
bool operator<=( const std::list<T, Alloc>& lhs,
                 const std::list<T, Alloc>& rhs );

[ ] template< class T, class Alloc >
bool operator>( const std::list<T, Alloc>& lhs,
                const std::list<T, Alloc>& rhs );

[ ] template< class T, class Alloc >
bool operator>=( const std::list<T, Alloc>& lhs,
                 const std::list<T, Alloc>& rhs );
