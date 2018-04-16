#include "Temperature.h"
#include <iostream>
#include <sstream>
#include <cassert>
#include <vector>
using namespace std;
char Scale[] = "CKF";

void test_temperature_input() {
	Temperature Temp;
	string inp = "10C";
	istringstream iss(inp);
	iss >> Temp;
	assert(Temp.temp == 10);
	assert(Temp.scale == 'C');

	istringstream iss1("0K");
	iss1 >> Temp;
	assert(Temp.temp == 0);
	assert(Temp.scale == 'K');

	istringstream iss2("-400F");
	iss2 >> Temp;
	assert(Temp.temp == -400);
	assert(Temp.scale == 'F');
};

int    main() {

	test_temperature_input();



	size_t count;
	string otvet;
	cerr << "\n chislo el";
	cin >> count;
	vector<Temperature> el(count);
	cerr << "\n vvedite " << count << " elementov";
	for (size_t i = 0; i < count; i++) {
		cin >> el[i];
		if (!cin) {
			cerr << "Necorrectniyi vvod";
			return 1;
		}

	}
	size_t col_count;
	do
	{
		cerr << "\n chislo stolbtsov";
		cin >> col_count;
		cerr << "\n";
		Temperature min = el[0], max = el[0];
		for (Temperature x : el)  {
			if (x < min) {
				min = x;
			}
			if (x > max) {
				max = x;
			}
		}
		max = convert(max, min.scale);
		vector<size_t> bins(col_count, 0);
		for (Temperature x : el) {
			size_t index = (size_t)((x - min) / (max - min) * col_count);
			if (x == max) {
				index--;
			}
			bins[index]++;
		}
		float maxb;
		double kf;
		maxb = bins[0];
		for (float x : bins)
		{
			if (maxb<x)
				maxb = x;
		}
		kf = 1;
		if (maxb>76)
			kf = (double)(1 - (maxb - 76) / (maxb));
		float value = 0;
		int l = 0;
		for (int i = 0; i < col_count; i++) {
			value += bins[i];
		}
		int sred = value / col_count;
		cout << "sred=" << sred;


		for (int i = 0; i < col_count; i++) {
			if (bins[i] > sred) {
				if (bins[i]<10) {
					cout << "  " << bins[i] << '|';
				}
				if (bins[i]<100 && bins[i]>10) {
					cout << " " << bins[i] << '|';
				}
				if (bins[i]<1000 && bins[i] >= 100) {
					cout << " " << bins[i] << '|';
				}



				for (int j = 0; j < bins[i]*kf; j++) {
					if (j < sred) {
						cout << "*";
					}
					if (j >= sred) {
						cout << "+";
					}
					l++;
					if (j == (bins[i] - 1)) {
						cout << "\n";
					}
				}
			}

			if (bins[i] < sred) {
				if (bins[i]<10) {
					cout << "  " << bins[i] << '|';
				}
				if (bins[i]<100 && bins[i]>10) {
					cout << " " << bins[i] << '|';
				}
				if (bins[i]<1000 && bins[i] >= 100) {
					cout << "   " << bins[i] << '|';
				}
				for (int j = 0; j < sred; j++) {
					if (j <= bins[i]) {
						cout << "*";
					}
					if (j > bins[i]) {
						cout << "-";
					} l++;if (l>80) { break; }
					if (j == (sred - 1)) {
						cout << "\n";
					}
				}
			}
		}
		cerr << "\n dovolni li vi resultatom\n";
		cin >> otvet;
	} while (otvet == "net");

	return 0;
}