#include <cassert>
#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream fin("B-large.in", std::ios::in);
    std::ofstream fout("B.out", std::ios::out);

    int T;
    fin >> T;

    for (int case_number = 0; case_number < T; ++case_number) {
        char previous_pancake = '+';
        int number_of_flips = 0;

        std::string pancake_string = "";
        fin >> pancake_string;

        for (size_t pancake_index = 0; pancake_index < pancake_string.size(); ++pancake_index) {
            const char current_pancake = pancake_string[pancake_index];
            if (pancake_index == 0) {
                previous_pancake = current_pancake;
                continue;
            }
            if (current_pancake != previous_pancake) {
                ++number_of_flips;
            }
            previous_pancake = current_pancake;
        }

        if (previous_pancake == '-') {
            ++number_of_flips;
        }

        fout << "Case #" << case_number + 1 << ": " << number_of_flips << std::endl;
    }
    fin.close();
    fout.close();
}
