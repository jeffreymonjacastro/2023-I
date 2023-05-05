#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <cmath>
#include <string.h>
#include <sstream> 
#include <string>

using namespace std;

auto random(int x, int y){ return rand() % (y-x+1) + x;}
bool is_equal(float a, float b, float epsilon = 0.001f){
    return fabs(a - b) < epsilon;
}

template< class T, class... Args >
constexpr bool is_constructible_v = is_constructible<T, Args...>::value;

