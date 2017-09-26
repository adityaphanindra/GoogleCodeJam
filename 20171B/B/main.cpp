#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

std::vector<char> GetPermittedColours(char colour) {
    switch (colour) {
    case 'R' : return {'Y', 'G', 'B'}; break;
    case 'O' : return {'B'}; break;
    case 'Y' : return {'R', 'B', 'V'}; break;
    case 'G' : return {'V'}; break;
    case 'B' : return {'R', 'O', 'Y'}; break;
    case 'V' : return {'Y'}; break;
    default : return {'R', 'O', 'Y', 'G', 'B', 'V'}; break;
    }
}

int GetValidPosition(std::string current_string, char next_colour, bool is_last_character) {
    std::vector<char> permitted_colours = GetPermittedColours(next_colour);
    int current_size = static_cast<int>(current_string.size());
    for (int index = 0; index <= current_size; ++index) {
        bool is_permitted = true;
        if (index - 1 >= 0) {
            char previous_colour = current_string.at(index - 1);
            if (std::find(permitted_colours.begin(), permitted_colours.end(), previous_colour) == permitted_colours.end()) {
                is_permitted = false;
            }
        }

        if (index < current_size) {
            char next_colour = current_string.at(index);
            if (std::find(permitted_colours.begin(), permitted_colours.end(), next_colour) == permitted_colours.end()) {
                is_permitted = false;
            }
        }

        if (index == 0 && !current_string.empty() && is_last_character) {
            char last_colour = current_string.at(current_string.size() - 1);
            if (std::find(permitted_colours.begin(), permitted_colours.end(), last_colour) == permitted_colours.end()) {
                is_permitted = false;
            }
        }

        if (index == current_size && !current_string.empty() && is_last_character) {
            char first_colour = current_string.at(0);
            if (std::find(permitted_colours.begin(), permitted_colours.end(), first_colour) == permitted_colours.end()) {
                is_permitted = false;
            }
        }

        if (is_permitted) {
            return index;
        }
    }
    return -1;
}

int main(int, char **) {
    int T = 0;
    std::cin >> T;

    for (int case_number = 0; case_number < T; ++case_number) {
        int N, R, O, Y, G, B, V;
        std::cin >> N >> R >> O >> Y >> G >> B >> V;

        std::string output = "";
        std::map<char, int> num_left;
        num_left['O'] = O;
        num_left['G'] = G;
        num_left['V'] = V;
        num_left['R'] = R;
        num_left['Y'] = Y;
        num_left['B'] = B;

        std::vector<char> colours = {'O', 'G', 'V', 'R', 'Y', 'B'};

        for (int ring_index = 0; ring_index < N; ++ring_index) {
            for (char next_colour : colours) {
                if (num_left[next_colour] <= 0) {
                    continue;
                }
                int valid_position = GetValidPosition(output, next_colour, ring_index == N - 1);
                if (valid_position < 0) {
                    continue;
                }
                output.insert(output.begin() + valid_position, next_colour);
                --num_left[next_colour];
                break;
            }
            if (static_cast<int>(output.size()) != ring_index + 1) {
                output = "IMPOSSIBLE";
                break;
            }
        }

        std::cout << "Case #" << case_number + 1 << ": " << output << std::endl;
    }
    exit (0);
}

