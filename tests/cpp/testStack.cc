#include <gtest/gtest.h>
#include <btstl/containers/Stack.hh>

TEST( TestBtStack, add ) {

    BtStack< int > stack;

    int valueA = 1;
    int valueB = 2;
    int valueC = 3;

    stack.add( &valueA );
    stack.add( &valueB );
    stack.add( &valueC );
}

TEST( TestBtStack, top ) {

    BtStack< int > stack;

    int valueA = 1;
    int valueB = 2;
    int valueC = 3;

    stack.add( &valueA );
    stack.add( &valueB );
    stack.add( &valueC );

    int resultC = *stack.top();
    stack.pop();

    int resultB = *stack.top();
    stack.pop();

    int resultA = *stack.top();
    stack.pop();

    EXPECT_EQ( valueA, resultA );
    EXPECT_EQ( valueB, resultB );
    EXPECT_EQ( valueC, resultC );
}

TEST( TestBtStack, pop ) {

    BtStack< int > stack;

    int valueA = 1;
    int valueB = 2;
    int valueC = 3;

    stack.add( &valueA );
    stack.add( &valueB );
    stack.add( &valueC );

    int resultC = *stack.top();
    stack.pop();

    int resultB = *stack.top();
    stack.pop();

    int resultA = *stack.top();
    stack.pop();

    EXPECT_EQ( valueA, resultA );
    EXPECT_EQ( valueB, resultB );
    EXPECT_EQ( valueC, resultC );
}

TEST( TestBtStack, clear ) {

    BtStack< int > stack;
    EXPECT_TRUE( stack.empty() );

    stack.clear();
    EXPECT_TRUE( stack.empty() );

    int valueA = 1;
    stack.add( &valueA );
    stack.clear();
    EXPECT_TRUE( stack.empty() );

    stack.pop();
    EXPECT_TRUE( stack.empty() );
}

TEST( TestBtStack, empty ) {

    BtStack< int > stack;
    EXPECT_TRUE( stack.empty() );

    int valueA = 1;
    stack.add( &valueA );
    EXPECT_FALSE( stack.empty() );

    stack.pop();
    EXPECT_TRUE( stack.empty() );
}