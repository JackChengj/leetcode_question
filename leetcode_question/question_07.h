#pragma once
#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

class question_07
{
public:
	int reverse(int x) {
        stack<int> s;
        long long temp_t = 1;
        long long re_x = 0;
        while (x != 0) {
            temp_t = temp_t * 10;
            s.push(x % temp_t / (temp_t / 10));
            x = x - x % temp_t;
        }
        temp_t = 1;
        while (!s.empty()) {
            re_x = re_x + s.top() * temp_t;
            s.pop();
            temp_t = temp_t * 10;
        }
        if (re_x > pow(2, 31) - 1 || re_x < -pow(2, 31)) {
            return 0;
        }
        return (int)re_x;
	}
};

