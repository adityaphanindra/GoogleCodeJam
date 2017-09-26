#include <algorithm>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <string>

#define P_MAX 3
#define LEFT_MAX 4
#define N_MAX 100
#define DEPTH_MAX N_MAX * N_MAX * N_MAX

int precomp[P_MAX][LEFT_MAX][DEPTH_MAX];

static int FindMaximal(std::vector<int> candidates, int leftover, const int P) {
    int maximum = 0;

    for (int index = 1; index < P; ++index) {
        if (candidates[index] > 0) {
            std::vector<int> candidates_previous = candidates;
            candidates[index]--;
            int current_leftover = (leftover + index) % P;
            int depth = 0;
            for (int i = 1; i < P; ++i) {
                depth = depth * N_MAX + candidates[i];
            }
            assert (depth < DEPTH_MAX);
            assert (current_leftover < LEFT_MAX);
            if (precomp[P - 2][current_leftover][depth] == -1) {
                precomp[P - 2][current_leftover][depth] =
                        FindMaximal(candidates, current_leftover, P);
            }
            int current_maximum = (leftover == 0 ? 1 : 0) + precomp[P - 2][current_leftover][depth];
            if (current_maximum > maximum) {
                maximum = current_maximum;
            }
            candidates = candidates_previous;
        }
    }
    return maximum;
}

int main(int, char **) {
    int T = 0;
    std::cin >> T;

    for (int i = 0; i < P_MAX; ++i) {
        for (int j = 0; j < LEFT_MAX; ++j) {
            for (int k = 0; k < DEPTH_MAX; ++k) {
                precomp[i][j][k] = -1;
            }
        }
    }

    for (int case_number = 0; case_number < T; ++case_number) {
        int N, P;
        std::cin >> N >> P;

        std::vector<int> candidates(P, 0);
        int num_fresh = 0;
        for (int index = 0; index < N; ++index) {
            int g;
            std::cin >> g;
            int remainder = P - (g % P);
            if (remainder == P) {
                remainder = 0;
            }
            ++candidates[remainder];
        }

//        for (int index = 0; index < P; ++index) {
//            std::cout << candidates[index] << " ";
//        }
//        std::cout << std::endl;

        num_fresh = candidates[0];
        candidates[0] = 0;
        num_fresh += FindMaximal(candidates, 0, P);

        std::cout << "Case #" << case_number + 1 << ": " << num_fresh << std::endl;
    }
    exit (0);
}
