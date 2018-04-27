#include <catch.hpp>
#include <sstream>
#include <fstream>
#include "queue.hpp"
using namespace std;

TEST_CASE("queue ini with other queue data")
{
    Queue <int> a1;
    Queue <int> a2 = {1, 2, 3, 4};
    Queue <int> a3{a2};
    REQUIRE( a2 == a3);
}

TEST_CASE("swap")
{
    Queue <int> a1;
    Queue <int> a2 = {1, 2, 3, 4};
    Queue <int> a3{a2};
    Queue <int> temp = a3;
    a1.swap(a3);
    REQUIRE( a1 == temp);
    REQUIRE( a3.empty() == true);
    REQUIRE( a1.size() == 4);
}

TEST_CASE("push")
{
    Queue <int> a1;
    Queue <int> a2 = {1, 2, 3, 4};
    Queue <int> a3{a2};
    a3.push(5);
    REQUIRE( a3.size() == 5);
}
TEST_CASE("pop#1")
{
    Queue<int> a4;
    //if the queue is empty
    a4.pop();
    REQUIRE( a4.size() == 0);
}
TEST_CASE("pop#2")
{
    Queue<int> a4 = {1};
    a4.pop();
    REQUIRE( a4.size() == 0);
}
TEST_CASE("pop#3")
{
    Queue<int> a4 = {1, 2, 3, 4, 5};
    a4.pop();
    REQUIRE( a4.size() == 4);
}

TEST_CASE("eq")
{
    Queue <int>  a1;
    Queue <int>  a2 = {1, 2, 3, 4};
    Queue <int>  a3{q2};
    a3.push(5);
    ofstream output{ "queue.bin" };
    output << a3;
    Queue <int> a4;
    ifstream input{ "queue.bin" };
    input >> a4;
    REQUIRE(! a4.empty() );
}
