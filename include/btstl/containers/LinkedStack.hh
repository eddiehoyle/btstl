//
// Created by Eddie Hoyle on 22/07/17.
//

#ifndef BTSTL_STACK_HH
#define BTSTL_STACK_HH

template< typename T >
class BtLinkedStack {

private:
    class Link;

public:
    BtLinkedStack();

    // Copy
    BtLinkedStack( const BtLinkedStack& stack );
    BtLinkedStack& operator=( const BtLinkedStack& stack );

    // Move
    BtLinkedStack( BtLinkedStack&& stack ) noexcept;
    BtLinkedStack& operator=( BtLinkedStack&& stack ) noexcept;

    ~BtLinkedStack();

    void add( const T& data );
    bool top( T& data ) const;
    bool pop();
    void clear();
    bool empty() const;

private:
    std::size_t size() const;
    void shallow_copy( const BtLinkedStack& stack );
    void swap( BtLinkedStack& stack ) noexcept;
    BtLinkedStack& move( BtLinkedStack& stack ) noexcept;

private:
    Link* m_top;
    std::size_t m_size;

private:
    struct Link {
        Link( const T& data, Link* previous )
                : data( data ),
                  previous( previous ) {}
        T data;
        Link* previous;
    };
};

template< typename T >
BtLinkedStack< T >::BtLinkedStack()
    : m_top( nullptr ),
      m_size( 0 )
{}

template< typename T >
BtLinkedStack< T >::BtLinkedStack( const BtLinkedStack& copy )
    : m_top( nullptr ),
      m_size( 0 ) {
    shallow_copy( copy );
}

template< typename T >
BtLinkedStack< T >& BtLinkedStack< T >::operator=( const BtLinkedStack< T >& copy ) {
    shallow_copy( copy );
    return *this;
}

template< typename T >
BtLinkedStack< T >::BtLinkedStack( BtLinkedStack&& rhs ) noexcept
        : m_top( std::move( rhs.m_top ) ),
          m_size( std::move( rhs.m_size ) ) {
    rhs.m_top = nullptr;
    rhs.clear();
}

template< typename T >
BtLinkedStack< T >& BtLinkedStack< T >::operator=( BtLinkedStack< T >&& rhs ) noexcept {
    return move( rhs );
}

template< typename T >
BtLinkedStack< T >::~BtLinkedStack() {
    clear();
}

template< typename T >
void BtLinkedStack< T >::add( const T& data ) {
    m_top = new Link( data, m_top );
    ++m_size;
}

template< typename T >
bool BtLinkedStack< T >::top( T& data ) const {
    if ( m_top ) {
        data = m_top->data;
        return true;
    }
    return false;
}

template< typename T >
bool BtLinkedStack< T >::pop() {
    if ( m_top ) {
        Link* block( m_top );
        m_top = block->previous;
        delete block;
        --m_size;
        return true;
    }
    return false;
}

template< typename T >
void BtLinkedStack< T >::clear() {
    while ( m_top ) {
        Link* block( m_top );
        m_top = block->previous;
        delete block;
        --m_size;
    }
}

template< typename T >
bool BtLinkedStack< T >::empty() const {
    return m_top == nullptr;
}

template< typename T >
std::size_t BtLinkedStack< T >::size() const {
    return m_size;
}

template< typename T >
void BtLinkedStack< T >::shallow_copy( const BtLinkedStack& stack ) {

    // Create temp array
    std::size_t size( stack.size() );
    T* temp[ size ];

    // Shallow copy data
    Link* link( stack.m_top );
    while( link ) {
        temp[ --size ] = &link->data;
        link = link->previous;
    }

    // Add values to this stack
    for ( std::size_t index = 0; index < stack.size(); ++index ) {
        add( *temp[ index ] );
    }
}

template< typename T >
void BtLinkedStack< T >::swap( BtLinkedStack& rhs ) noexcept {
    using std::swap;
    swap( m_top, rhs.m_top );
    swap( m_size, rhs.m_size );
}

template< typename T >
BtLinkedStack< T >& BtLinkedStack< T >::move( BtLinkedStack< T >& rhs ) noexcept {

    // Clear this stack
    clear();

    // Move contents
    m_top = std::move( rhs.m_top );
    m_size = std::move( rhs.m_size );

    // Clean up moved stack;
    rhs.m_top = nullptr;
    rhs.clear();

    return *this;
}

template< typename T >
void swap( BtLinkedStack< T >& lhs, BtLinkedStack< T >& rhs ) {
    lhs.swap( rhs );
}

#endif // BTSTL_STACK_HH
