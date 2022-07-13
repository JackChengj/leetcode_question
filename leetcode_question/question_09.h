#pragma once
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int new_x = 0;
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        while (x > new_x)
        {
            new_x = new_x * 10 + x % 10;
            x = x / 10;
        }
        return new_x == x || x == new_x / 10;
    }
};