#include <algorithm>
#include <cassert>
#include <cmath>
#include <fstream>
#include <iostream>
#include <stdint.h>
#include <string>
#include <vector>

int main(int argc, char * argv []) {
    assert (argc > 1);

    const std::string input_file = argv[1];
    std::ifstream fin(input_file.c_str(), std::ios::in);
    std::ofstream fout("D.out", std::ios::out);

    int T;
    fin >> T;

    for (int case_number = 0; case_number < T; ++case_number) {
    	int K, C, S;
        fin >> K >> C >> S;

        fout << "Case #" << case_number + 1 << ":";
        if (S == K) {
	        for (int index = 1; index <= K; ++index) {
	        	fout << " " << index;
	        }        	
        } else {
        	fout << " IMPOSSIBLE";
        }

        fout << std::endl;
    }
    fin.close();
    fout.close();
}
