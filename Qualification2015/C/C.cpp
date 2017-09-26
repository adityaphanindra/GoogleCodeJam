#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#define i 2
#define j 3
#define k 4

int multiply(const int a, const int b) {
    int sign = 1;
    if (a * b < 0) {
        sign = -1;
    }
    const int x = std::abs(a);
    const int y = std::abs(b);
    if (x == 1) {
        if (y == 1) {
            return 1 * sign;
        }
        if (y == i) {
            return i * sign;
        }
        if (y == j) {
            return j * sign;
        }
        if (y == k) {
            return k * sign;
        }
    }
    if (x == i) {
        if (y == 1) {
            return i * sign;
        }
        if (y == i) {
            return -1 * sign;
        }
        if (y == j) {
            return k * sign;
        }
        if (y == k) {
            return -j * sign;
        }
    }
    if (x == j) {
        if (y == 1) {
            return j * sign;
        }
        if (y == i) {
            return -k * sign;
        }
        if (y == j) {
            return -1 * sign;
        }
        if (y == k) {
            return i * sign;
        }
    }
    if (x == k) {
        if (y == 1) {
            return k * sign;
        }
        if (y == i) {
            return j * sign;
        }
        if (y == j) {
            return -i * sign;
        }
        if (y == k) {
            return -1 * sign;
        }
    }
    return 0;
}

int Evaluate(const std::string & input, const int from, const int to) {
    assert (from >= 0 && to >= 0 && to < input.size() && from <= to);

    int current = 1;
    for (int index = from; index < to; ++index) {

    }
}

int main() {
    std::ifstream fin("C.in");
    std::ofstream fout("C.out");

    assert (fin.is_open());

    int T;
    fin >> T;

    for (int case_number = 1; case_number <= T; ++case_number) {
        std::cout << "Case #" << case_number << ": " << case_number << std::endl;
    }
    fin.close();
    fout.close();
}


