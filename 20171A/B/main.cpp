#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

typedef unsigned long long ull;

int main(int, char **) {
    int T = 0;
    std::cin >> T;

    for (int case_number = 0; case_number < T; ++case_number) {
        int N, P;
        int kits = 0;

        std::cin >> N >> P;

        ull R[N];
        ull Q[N][P];

        for (int ing_index = 0; ing_index < N; ++ing_index) {
            std::cin >> R[ing_index];
        }

        for (int ing_index = 0; ing_index < N; ++ing_index) {
            for (int pack_index = 0; pack_index < P; ++pack_index) {
                std::cin >> Q[ing_index][pack_index];
            }
        }

        std::map<int, std::vector<int>> portions[N];

        for (int ing_index = 0; ing_index < N; ++ing_index) {
            for (int pack_index = 0; pack_index < P; ++pack_index) {
                int min_portions = static_cast<double>(Q[ing_index][pack_index]) / (static_cast<double>(R[ing_index]) * 1.1);
                int max_portions = static_cast<double>(Q[ing_index][pack_index]) / (static_cast<double>(R[ing_index]) * 0.9);

                assert (min_portions <= max_portions);

                std::cout << ing_index << ":" << pack_index << " " << Q[ing_index][pack_index] << " " << R[ing_index]
                             << " " << min_portions << " to " << max_portions << std::endl;

                for (int portion = min_portions; portion <= max_portions; ++portion) {
                    portions[ing_index][portion].push_back(pack_index);
                }
            }
        }

        for (int ing_index = 0; ing_index < N; ++ing_index) {
            for (auto portion_packet : portions[ing_index]) {
                std::cout << ing_index << ":" << portion_packet.first << " (";
                for (size_t packet_index = 0; packet_index < portion_packet.second.size(); ++packet_index) {
                    std::cout << portion_packet.second[packet_index] << " ";
                }
                std::cout << ") ";
            }
            std::cout << std::endl;
        }

        std::cout << "Case #" << case_number + 1 << ": " << kits << std::endl;
    }
    exit (0);
}
