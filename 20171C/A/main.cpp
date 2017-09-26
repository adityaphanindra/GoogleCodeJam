#include <algorithm>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>

#define PI 3.1415926535897932384626433

struct Pancake {
    int index;
    double R;
    double H;
    double RH;
};

struct by_r {
    bool operator()(Pancake const & left, Pancake const & right) {
        return left.R > right.R;
    }
};

struct by_rh {
    bool operator()(Pancake const & left, Pancake const & right) {
        return left.RH > right.RH;
    }
};

int main(int, char **) {
    int T = 0;
    std::cin >> T;

    for (int case_number = 0; case_number < T; ++case_number) {
        int N, K;
        std::cin >> N >> K;
        std::vector<Pancake> pancakes(N), pancakes_byr(N), pancakes_byrh(N);

        for (int p = 0; p < N; ++p) {
            pancakes[p].index = p;
            std::cin >> pancakes[p].R >> pancakes[p].H;
            pancakes[p].RH = pancakes[p].R * pancakes[p].H;
        }
        pancakes_byr = pancakes_byrh = pancakes;

        std::sort(pancakes_byr.begin(), pancakes_byr.end(), by_r());
        std::sort(pancakes_byrh.begin(), pancakes_byrh.end(), by_rh());

        double max_area = 0, current_area = 0;

        for (int p_start = 0; p_start < N; ++p_start) {
            double top_area = pancakes_byr[p_start].R * pancakes_byr[p_start].R;
            int top_index = pancakes_byr[p_start].index;
            current_area = top_area + 2.0 * pancakes_byr[p_start].RH;
            int selected = 1;
            for (Pancake pancake : pancakes_byrh) {
                if (selected == K) {
                    break;
                }
                if (pancake.index == top_index) {
                    continue;
                }
                current_area += 2.0 * pancake.RH;
                ++selected;
            }
            assert (selected == K);

            max_area = std::max(max_area, current_area);
        }

        std::cout << "Case #" << case_number + 1 << ": " << std::fixed << std::setprecision(9) << max_area * PI << std::endl;
    }
    exit (0);
}

