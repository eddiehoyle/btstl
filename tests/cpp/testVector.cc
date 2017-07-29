#include <gtest/gtest.h>
#include <btstl/containers/Vector.hh>

TEST( TestBtVector, append ) {
    BtVector< int > vec;
    vec.append( 1 );
}

TEST( TestBtVector, insert ) {
    BtVector< int > vec;
}

TEST( TestBtVector, remove ) {
    BtVector< int > vec;
}

TEST( TestBtVector, resize ) {
    BtVector< int > vec;
}

TEST( TestBtVector, length ) {

    BtVector< int > vec;
    EXPECT_EQ( vec.length(), 0 );

    vec.append( 1 );
    EXPECT_EQ( vec.length(), 1 );

    vec.append( 2 );
    vec.append( 3 );
    vec.append( 4 );
    EXPECT_EQ( vec.length(), 4 );
}

TEST( TestBtVector, empty ) {

    BtVector< int > vec;
    EXPECT_TRUE( vec.empty() );

    vec.append( 1 );
    EXPECT_FALSE( vec.empty() );

    vec.clear();
    EXPECT_TRUE( vec.empty() );

    vec.append( 1 );
    EXPECT_FALSE( vec.empty() );

    vec.pop();
    EXPECT_TRUE( vec.empty() );
}
TEST( TestBtVector, clear ) {

    BtVector< int > vec;
    EXPECT_TRUE( vec.empty() );

    vec.append( 1 );
    EXPECT_FALSE( vec.empty() );

    vec.clear();
    EXPECT_TRUE( vec.empty() );
}
TEST( TestBtVector, pop ) {

    BtVector< int > vec;
    EXPECT_TRUE( vec.empty() );

    vec.append( 1 );
    EXPECT_FALSE( vec.empty() );

    vec.pop();
    EXPECT_TRUE( vec.empty() );
}