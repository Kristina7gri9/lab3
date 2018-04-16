#pragma once

#ifndef Project1_TEMPERATURE_H
#define Project1_TEMPERATURE_H
#include <sstream>
#include <iostream>

struct Temperature {
	double temp;
	char scale;
};
istream& operator >> (istream& in, Temperature& Temp);
bool operator<(const Temperature& lhs, const Temperature& rhs);
Temperature operator-(const Temperature& lhs, const Temperature& rhs);
Temperature operator/(const Temperature& lhs, const Temperature& rhs);
Temperature operator*(const Temperature& lhs, const Temperature& rhs);
double convert(const Temperature& Temp, char scale_to);
#endif //Project1_TEMPERATURE_H