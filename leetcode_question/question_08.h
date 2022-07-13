#pragma once
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
		long long change_s = 0;
		int start_point = 0;
		int end_point = 0;
		int symbol = 0;
		bool start_read = false;
		while (end_point < s.length())
		{
			if (!start_read && s.at(end_point) == ' ')
			{
				start_point++;
				end_point++;
			}
			else if (!symbol && !start_read && s.at(end_point) == '-')
			{
				start_point++;
				end_point++;
				symbol = -1;
				start_read = true;
			}
			else if (!symbol && !start_read && s.at(end_point) == '+')
			{
				start_point++;
				end_point++;
				symbol = 1;
				start_read = true;
			}
			else if (start_point==end_point && s.at(end_point) == '0')
			{
				start_point++;
				end_point++;
				start_read = true;
			}
			else if (isdigit(s.at(end_point)))
			{
				end_point++;
				start_read = true;
			}
			else
			{
				break;
			}
		}
		int number = end_point - start_point;
		if (number == 0)
		{
			return 0;
		}
		else if(number > 10)
		{
			if (symbol == -1)
			{
				return -pow(2, 31);
			}
			else 
			{
				return pow(2, 31) - 1;
			}
		}
		else
		{
			for (int i = 0; i < number; i++)
			{
				change_s += (s.at(start_point + i)-'0')*pow(10,number-i-1);
			}
			if (!symbol)
			{
				symbol = 1;
			}
			change_s *= symbol;
			if (change_s > pow(2, 31) - 1) {
				return pow(2, 31)-1;
			}
			if (change_s < -pow(2, 31))
			{
				return -pow(2, 31);
			}
			return (int)change_s;
		}
    }
};