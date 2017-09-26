#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int GetNextMax(const std::vector<int> & p) {
    assert (!p.empty());
    int current_max = p.at(0);
    int next_max = static_cast<double>(current_max) / 2.0 + 0.5;
    for (size_t index = 1; index < p.size(); ++index) {
        if (p.at(index) < current_max) {
            next_max = std::max(next_max, p.at(index));
            break;
        }
    }
    return next_max;
}

int CountMax(const std::vector<int> & p) {
    assert (!p.empty());
    int current_max = p.at(0);
    int count_max = 1;
    for (size_t index = 1; index < p.size(); ++index) {
        if (p.at(index) < current_max) {
            break;
        }
        ++count_max;
    }
    return count_max;
}

void Split(std::vector<int> & p) {
    const int current_max = p.at(0);
    const double half = static_cast<double>(current_max) / 2.0;
    int split_max = half + 0.5;
    int split_min = half;

    int max_count = CountMax(p);
    while (!p.empty()) {
        if (p.at(0) == current_max) {
            p.erase(p.begin());
        } else {
            break;
        }
    }
    for (int index = 0; index < max_count; ++index) {
        p.push_back(split_max);
        p.push_back(split_min);
    }

    std::sort(p.begin(), p.end(), std::greater<int>());
}

int main() {
    std::ifstream fin("B.in");
    std::ofstream fout("B.out");

    assert (fin.is_open());

    int T;
    fin >> T;

    for (int case_number = 1; case_number <= T; ++case_number) {
        int d;
        fin >> d;

        std::vector<int> p;

        for (int index = 0; index < d; ++index) {
            int p_i;
            fin >> p_i;
            p.push_back(p_i);
        }
        assert (!p.empty());
        std::sort(p.begin(), p.end(), std::greater<int>());

        int max_minutes = p.at(0);
        int split_minutes = 0;
        int best_max = max_minutes;
        while (true) {
            int time_to_split = CountMax(p);
            int next_max = GetNextMax(p);
            int max_minutes_split = next_max + time_to_split + split_minutes;
//            if (max_minutes_split > max_minutes) {
////                break;
//            } else {
                max_minutes = max_minutes_split;
                Split(p);
                split_minutes += time_to_split;
//            }
                best_max = std::min(best_max, max_minutes);

            if (next_max == 1) {
                break;
            }
        }

        fout << "Case #" << case_number << ": " << best_max << std::endl;
    }
    fin.close();
    fout.close();
}


