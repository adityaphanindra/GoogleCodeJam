#include <algorithm>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>

double GetProbability(std::vector<double> p, int N) {
    double probability = 1.0;
    for (int i = 0; i < N; ++i) {
        probability *= p[i];
    }
    return probability;
}

int main(int, char **) {
    int T = 0;
    std::cin >> T;

    for (int case_number = 0; case_number < T; ++case_number) {
        int N, K;
        double U;

        std::cin >> N >> K;
        std::cin >> U;

        std::vector<double> p(N), weight(N);
        double max_weight = 0.0;
        std::vector<int> max_weight_indices;
        for (int i = 0; i < N; ++i) {
            std::cin >> p[i];
        }
        std::sort(p.begin(), p.end());

        for (int i = 0; i < N; ++i) {
            if (p[i] > 0.0) {
                weight[i] = 1.0 / p[i];
            } else {
                weight[i] = std::numeric_limits<double>::infinity();
            }
            max_weight = std::max(max_weight, weight[i]);
        }

        for (int i = 0; i < N; ++i) {
            if (weight[i] == max_weight) {
                max_weight_indices.push_back(i);
            }
        }

        double boost = U / static_cast<double>(max_weight_indices.size());
        for (size_t i = 0; i < max_weight_indices.size(); ++i) {
            int index = max_weight_indices[i];
            double new_p = std::min(p[index] + boost, 1.0);
            U -= new_p - p[index];
            p[index] = new_p;
        }

        for (int probability : p) {
            std::cout << probability << " ";
        }
        std::cout << std::endl;
        std::cout << "Case #" << case_number + 1 << ":" << std::fixed << std::setprecision(4) << GetProbability(p, N) << std::endl;
    }
    exit (0);
}

