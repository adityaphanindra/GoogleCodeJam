#include <algorithm>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>

int main(int, char **) {
    int T = 0;
    std::cin >> T;

    for (int case_number = 0; case_number < T; ++case_number) {
        int N;
        double D;
        std::cin >> D >> N;

        double max_time = 0;

        for (int index = 0; index < N; ++index) {
            double K, S;
            std::cin >> K >> S;
            max_time = std::max(max_time, (D - K) / S);
        }

        std::cout << "Case #" << case_number + 1 << ": " << std::fixed << std::setprecision(6) << D/max_time << std::endl;
    }
    exit (0);
}

