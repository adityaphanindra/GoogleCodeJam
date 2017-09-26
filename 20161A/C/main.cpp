#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

std::vector<int> BFF;
std::vector<int> BFF_of;
std::vector<int> cycle;

int visit (int node_id, int previous_node_id, int starter_id, int cycle_length) {
    std::cout << "Visiting " << node_id + 1 << " Starter id = " << starter_id + 1 << std::endl;
    if (node_id == starter_id) {
        return cycle_length;
    } else if (cycle.at(node_id) == -1) {
        cycle[node_id] = starter_id;
//        if (previous_node_id == BFF.at(node_id)) {
            return visit (BFF.at(node_id), node_id, starter_id, cycle_length + 1);
//        } else {
//            return cycle_length + 1;// + visit (BFF_of.at(node_id), node_id, starter_id, 0);
//        }
    } else {
        return 0;
    }
}

int main(int, char **) {
    int T = 0;
    std::cin >> T;

    for (int case_number = 0; case_number < T; ++case_number) {
        std::cout << std::endl;
        std::cout << "Case #" << case_number + 1 << ":";
        int N;
        std::cin >> N;

        BFF.clear();
        BFF_of.clear();
        cycle.clear();
        BFF.resize(N);
        BFF_of.resize(N);
        cycle.resize(N);
        for (int id = 0; id < N; ++id) {
            int bff;
            std::cin >> bff;
            std::cout << " " << bff;
            --bff;
            BFF.at(id) = bff;
            BFF_of.at(bff) = id;
            cycle.at(id) = -1;
        }

        std::cout << std::endl;

        int max_cycle_size = 0;

        for (int starter_id = 0; starter_id < N; ++starter_id) {
            if (cycle[starter_id] > -1) {
                continue;
            } else {
                cycle[starter_id] = starter_id;
                int cycle_size = visit(BFF[starter_id], starter_id, starter_id, 1);

                max_cycle_size = std::max(max_cycle_size, cycle_size);
            }
        }

        assert (N < 2 || max_cycle_size >= 2);
        std::cout << "Case #" << case_number + 1 << ":" << max_cycle_size << std::endl;
    }
    exit (0);
}
