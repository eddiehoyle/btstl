#include <gtest/gtest.h>
#include <btstl/containers/LinkedStack.hh>
#include <utility>

TEST( TestBtLinkedStack, move_constructor ) {

    BtLinkedStack< int > stackD;

    int valueA = 1;
    int valueB = 2;
    int valueC = 3;

    stackD.add( valueA );
    stackD.add( valueB );
    stackD.add( valueC );

    BtLinkedStack< int > stackC( std::move( stackD ) );

    int resultC;
    bool topStateC = stackC.top( resultC );
    bool popStateC = stackC.pop();
    EXPECT_EQ( valueC, resultC );
    EXPECT_TRUE( topStateC );
    EXPECT_TRUE( popStateC );

    BtLinkedStack< int > stackB( std::move( stackC ) );

    int resultB;
    bool topStateB = stackB.top( resultB );
    bool popStateB = stackB.pop();
    EXPECT_EQ( valueB, resultB );
    EXPECT_TRUE( topStateB );
    EXPECT_TRUE( popStateB );

    BtLinkedStack< int > stackA( std::move( stackB ) );

    int resultA;
    bool topStateA = stackA.top( resultA );
    bool popStateA = stackA.pop();
    EXPECT_EQ( valueA, resultA );
    EXPECT_TRUE( topStateA );
    EXPECT_TRUE( popStateA );
}

TEST( TestBtLinkedStack, move_assignment ) {

    BtLinkedStack< int > stackA, stackB, stackC;

    int valueA = 1;
    int valueB = 2;
    int valueC = 3;

    stackA.add( valueA );
    stackA.add( valueB );
    stackA.add( valueC );

    stackC = std::move( stackA );

    int resultC;
    bool topStateC = stackC.top( resultC );
    bool popStateC = stackC.pop();
    EXPECT_EQ( valueC, resultC );
    EXPECT_TRUE( topStateC );
    EXPECT_TRUE( popStateC );

    stackB = std::move( stackC );

    int resultB;
    bool topStateB = stackB.top( resultB );
    bool popStateB = stackB.pop();
    EXPECT_EQ( valueB, resultB );
    EXPECT_TRUE( topStateB );
    EXPECT_TRUE( popStateB );

    stackA = std::move( stackB );

    int resultA;
    bool topStateA = stackA.top( resultA );
    bool popStateA = stackA.pop();
    EXPECT_EQ( valueA, resultA );
    EXPECT_TRUE( topStateA );
    EXPECT_TRUE( popStateA );
}

TEST( TestBtLinkedStack, copy_constructor ) {

    BtLinkedStack< int > stackA;

    int valueA = 1;
    int valueB = 2;
    int valueC = 3;

    stackA.add( valueA );
    stackA.add( valueB );
    stackA.add( valueC );

    // Copy
    BtLinkedStack< int > stackB( stackA );
    EXPECT_FALSE( stackB.empty() );

    int resultC;
    bool topStateC = stackB.top( resultC );
    bool popStateC = stackB.pop();
    EXPECT_EQ( valueC, resultC );
    EXPECT_TRUE( topStateC );
    EXPECT_TRUE( popStateC );

    int resultB;
    bool topStateB = stackB.top( resultB );
    bool popStateB = stackB.pop();
    EXPECT_EQ( valueB, resultB );
    EXPECT_TRUE( topStateB );
    EXPECT_TRUE( popStateB );

    int resultA;
    bool topStateA = stackB.top( resultA );
    bool popStateA = stackB.pop();
    EXPECT_EQ( valueA, resultA );
    EXPECT_TRUE( topStateA );
    EXPECT_TRUE( popStateA );
}

TEST( TestBtLinkedStack, add ) {

    BtLinkedStack< int > stack;

    int valueA = 1;
    int valueB = 2;
    int valueC = 3;

    stack.add( valueA );
    stack.add( valueB );
    stack.add( valueC );
}

TEST( TestBtLinkedStack, top ) {

    BtLinkedStack< int > stack;

    int badValueA;
    bool topBadStateA = stack.top( badValueA );
    EXPECT_FALSE( topBadStateA );

    int valueA = 1;

    stack.add( valueA );
    int resultA;
    bool topStateA = stack.top( resultA );
    EXPECT_EQ( valueA, resultA );
    EXPECT_TRUE( topStateA );

    stack.pop();

    int badValueB;
    bool topBadStateB = stack.top( badValueB );
    EXPECT_FALSE( topBadStateB );
}

TEST( TestBtLinkedStack, pop ) {

    BtLinkedStack< int > stack;

    bool popBadStateA = stack.pop();
    EXPECT_FALSE( popBadStateA );

    int valueA = 1;
    stack.add( valueA );
    bool popStateA = stack.pop();
    EXPECT_TRUE( popStateA );

    bool popBadStateB = stack.pop();
    EXPECT_FALSE( popBadStateB );
}

TEST( TestBtLinkedStack, clear ) {

    BtLinkedStack< int > stack;
    EXPECT_TRUE( stack.empty() );

    stack.clear();
    EXPECT_TRUE( stack.empty() );

    int valueA = 1;
    stack.add( valueA );
    stack.clear();
    EXPECT_TRUE( stack.empty() );

    stack.pop();
    EXPECT_TRUE( stack.empty() );
}

TEST( TestBtLinkedStack, empty ) {

    BtLinkedStack< int > stack;
    EXPECT_TRUE( stack.empty() );

    int valueA = 1;
    stack.add( valueA );
    EXPECT_FALSE( stack.empty() );

    stack.pop();
    EXPECT_TRUE( stack.empty() );
}