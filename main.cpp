#include "Temperature.h"

#include <vector>

#include <cassert>
using namespace std;
char Scale[]="CKF";

int main() {



    size_t count;
    string otvet;
    cerr << "\n chislo el\n";
    cin >> count;
    vector<Temperature> el(count);
    cerr << "\n vvedite " << count << " elementov";
    for (size_t i = 0; i < count; i++) {
        cin >> el[i];
        if (cin.fail()) {return -1;}
        convert(el[i],'K');

    }
    size_t col_count;

    cerr << "\n chislo stolbtsov";
    cin >> col_count;
    cerr << "\n";
    double min = el[0].temp, max = el[0].temp;
    for (Temperature x : el) {

        if (x.temp < min) {
            min = x.temp;
        }
        if (x.temp > max) {
            max = x.temp;
        }
    }

    vector<size_t> bins(col_count, 0);
    for (Temperature x : el) {

        size_t index = (size_t)((x.temp - min) / (max - min) * col_count);
        if (x.temp == max) {
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
    cout << "sred=" << sred<<'\n';


    for (int i = 0; i < col_count; i++) {
        if (bins[i] > sred) {
            if (bins[i] < 10) {
                cout <<" " << bins[i] << '|';
            }
            if (bins[i] < 100 && bins[i] > 10) {
                cout << " " << bins[i] << '|';
            }
            if (bins[i] < 1000 && bins[i] >= 100) {
                cout << " " << bins[i] << '|';
            }

            for (int j = 0; j < bins[i] * kf; j++) {
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

        if (bins[i] <= sred) {
            if (bins[i] < 10) {
                cout << " " << bins[i] << '|';
            }
            if (bins[i] < 100 && bins[i] > 10) {
                cout << " " << bins[i] << '|';
            }
            if (bins[i] < 1000 && bins[i] >= 100) {
                cout << " " << bins[i] << '|';
            }
            for (int j = 0; j < sred; j++) {
                if (j <= bins[i]) {
                    cout << "*";
                }
                if (j > bins[i]) {
                    cout << "-";
                }
                l++;
                if (l > 80) { break; }
                if (j == (sred - 1)) {
                    cout << "\n";
                }
            }
        }
    }

    return 0;
}