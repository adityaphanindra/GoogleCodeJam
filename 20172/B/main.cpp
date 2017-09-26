#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

int main(int, char **) {
    int T = 0;
    std::cin >> T;

    for (int case_number = 0; case_number < T; ++case_number) {
        int N, C, M;
        std::cin >> N >> C >> M;

        std::vector<std::vector<int>> tickets (N);
        std::vector<std::vector<int>> repeats (N, std::vector<int>(C, 0));
        std::vector<int> tickets_per_person (C, 0);
        int max_repeats = 0, max_tickets_per_person = 0, max_tickets_per_position = 0;
        for (int ticket_number = 0; ticket_number < M; ++ticket_number) {
            int p, b;
            std::cin >> p >> b;
            tickets[p - 1].push_back(b - 1);
            if (std::find(tickets[p - 1].begin(), tickets[p - 1].end(), b - 1) != tickets[p - 1].end()) {
                ++repeats[p - 1][b - 1];
                if (max_repeats < repeats[p - 1][b - 1]) {
                    max_repeats = repeats[p - 1][b - 1];
                }
            }
            ++tickets_per_person[b - 1];
            if (max_tickets_per_person < tickets_per_person[b - 1]) {
                max_tickets_per_person = tickets_per_person[b - 1];
            }
            if (max_tickets_per_position < static_cast<int>(tickets[p - 1].size())) {
                max_tickets_per_position = tickets[p - 1].size();
            }
        }

        int max_rides = std::max(std::max(static_cast<int>(tickets[0].size()), max_repeats), max_tickets_per_person);
        int max_promotions = std::max(0, max_tickets_per_position - max_rides);

        std::cout << "Case #" << case_number + 1 << ": " << max_rides << " " << max_promotions << std::endl;
    }
    exit (0);
}

