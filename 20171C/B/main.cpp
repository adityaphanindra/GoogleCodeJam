#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

struct Slot {
    int start;
    int end;
    int duration;
    char assignment;
    char previous;
    char next;
};

struct by_start {
    bool operator()(Slot & left, Slot & right) {
        return left.start < right.start;
    }
};

struct by_duration {
    bool operator()(Slot & left, Slot & right) {
        return left.duration < right.duration;
    }
};

int main(int, char **) {
    int T = 0;
    std::cin >> T;

    for (int case_number = 0; case_number < T; ++case_number) {
        int C, J;
        std::cin >> C >> J;


        std::cout << "Case #" << case_number + 1 << ": " << exchanges << std::endl;
    }
    exit (0);
}

