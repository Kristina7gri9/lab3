#include<iostream>
#include "Temperature.h"
using namespace std;
istream& operator >> (istream& in, Temperature& Temp) {
	in >> Temp.temp;
	in >> Temp.scale;
}


double convert (const Temperature& Temp, char scale_to) {
	double T_Kel;
	if ((scale_to) == (Temp.scale)) {
		return Temp.temp;
	}
	switch (Temp.scale) {
	case 'C':
		T_Kel = Temp.temp - 273.15;
		break;

	case 'F':
		T_Kel = ((9.0 / 5) * (Temp.temp - 273.15) + 32);
		break;

	case 'K':
		T_Kel = Temp.temp;
		break;

	}
	switch (scale_to) {
	case 'C':
	case 'c':
		return T_Kel - 273.15;

	case 'K':
	case 'k':
		return T_Kel;

	case 'F':
	case 'f':
		return ((9.0 / 5) * (T_Kel - 273.15) + 32);

	}

}
bool operator<(const Temperature& lhs, const Temperature& rhs) {
	return convert(lhs, 'K') < convert(rhs, 'K');
}

Temperature operator-(const Temperature& lhs, const Temperature& rhs) {
	Temperature ret_temp;
	ret_temp.temp = convert(lhs, 'K') - convert(rhs, 'K');
	ret_temp.scale = 'K';
	return ret_temp;
}

Temperature operator/(const Temperature& lhs, const Temperature& rhs) {
	Temperature ret_temp;
	ret_temp.temp = convert(lhs, 'K') / convert(rhs, 'K');
	ret_temp.scale = 'K';
	return ret_temp;
}
Temperature operator*(const Temperature& lhs, const Temperature& rhs) {
	Temperature ret_temp;
	ret_temp.temp = convert(lhs, 'K') * convert(rhs, 'K');
	ret_temp.scale = 'K';
	return ret_temp;
}