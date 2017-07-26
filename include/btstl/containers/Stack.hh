//
// Created by Eddie Hoyle on 22/07/17.
//

#ifndef BTSTL_STACK_HH
#define BTSTL_STACK_HH

template< typename T >
class BtStack {

public:
    BtStack();
    ~BtStack();

    void add( T* data );
    T* top();
    void pop();
    void clear();
    bool empty();

private:

    struct BtStackBlock {
        explicit BtStackBlock( T* data, BtStackBlock* prev )
                : m_data( data ),
                  m_prev( prev ) {}
        T* m_data;
        BtStackBlock* m_prev;
    };

    BtStackBlock* m_top;

    BtStack( const BtStack& ) = delete;
    BtStack operator=( const BtStack& ) = delete;
};

template< typename T >
BtStack< T >::BtStack()
    : m_top( nullptr ) {}

template< typename T >
BtStack< T >::~BtStack() {
    clear();
}

template< typename T >
void BtStack< T >::add( T* data ) {
    m_top = new BtStackBlock( data, m_top );
}

template< typename T >
T* BtStack< T >::top() {
    T* data( nullptr );
    if ( m_top ) {
        BtStackBlock* block( m_top );
        data = block->m_data;
    }
    return data;
}

template< typename T >
void BtStack< T >::pop() {
    T* data( nullptr );
    if ( m_top ) {
        BtStackBlock* block( m_top );
        data = block->m_data;
        m_top = block->m_prev;
        delete block;
    }
}

template< typename T >
void BtStack< T >::clear() {
    while ( m_top ) {
        BtStackBlock *block( m_top );
        m_top = block->m_prev;
        delete block;
    }
}

template< typename T >
bool BtStack< T >::empty() {
    return m_top == nullptr;
}

#endif // BTSTL_STACK_HH
