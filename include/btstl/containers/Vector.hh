#ifndef BTSTL_VECTOR_HH
#define BTSTL_VECTOR_HH

#include <cstddef>
#include <memory>
#include <algorithm>
#include <vector>

template< typename T >
class BtVector {

public:
    BtVector();
    explicit BtVector( std::size_t capacity );

    BtVector( const BtVector& vector );
    BtVector& operator=( const BtVector& vector );
    ~BtVector();

    void append( const T& value );
    void insert( std::size_t index, const T& value );
    void remove( std::size_t index );
    void resize( std::size_t capacity );
    std::size_t length() const;
    bool empty() const;
    void clear();
    void pop();

private:
    void expand();
    void allocate( std::size_t capacity );

private:
    std::size_t m_capacity;
    std::size_t m_length;
    T *m_buffer;
};

template< typename T >
BtVector< T >::BtVector()
        : m_capacity( 0 ),
          m_length( 0 ),
          m_buffer( nullptr ) {
    m_buffer = new T[ m_capacity ];
}

template< typename T >
BtVector< T >::BtVector( std::size_t capacity )
        : m_capacity( capacity ),
          m_length( 0 ),
          m_buffer( nullptr ) {
    m_buffer = new T[ m_capacity ];
}

template< typename T >
BtVector< T >::~BtVector() {
    clear();
}

template< typename T >
void BtVector< T >::append( const T& value ) {
    expand();
    m_buffer[ m_length ] = value;
    ++m_length;
}

template< typename T >
void BtVector< T >::resize( std::size_t capacity ) {
    if ( capacity > m_capacity ) {
        allocate( capacity );
    }
}

template< typename T >
std::size_t BtVector< T >::length() const {
    return m_length;
}

template< typename T >
bool BtVector< T >::empty() const {
    return m_length == 0;
}

template< typename T >
void BtVector< T >::clear() {
    for( std::size_t index = 0; index < m_length; ++index ) {
        m_buffer[ m_length - 1 - index ].~T();
    }
    m_length = 0;
}

template< typename T >
void BtVector< T >::pop() {
    m_buffer[ --m_length ].~T();
}

template< typename T >
void BtVector< T >::expand() {
    if ( m_length == m_capacity ) {
        std::size_t newCapacity = static_cast< std::size_t >( std::max( 2.0, m_capacity * 1.5 ) );
        allocate( newCapacity );
    }
}

template< typename T >
void BtVector< T >::allocate( std::size_t capacity ) {
    T* tmp = new T[ capacity ];
    std::copy( m_buffer, m_buffer + m_length, tmp );
    delete[] m_buffer;
    m_buffer = tmp;
}

#endif //BTSTL_VECTOR_HH
