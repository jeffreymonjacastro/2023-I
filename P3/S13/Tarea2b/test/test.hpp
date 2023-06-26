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

bool is_sorted(vector<double> v){
    for(int i=1; i<v.size(); i++)
        if(v[i-1] > v[i])
            return false;
    return true;
}