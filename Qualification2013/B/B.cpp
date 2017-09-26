#include <iostream>
#include <fstream>

typedef unsigned int uint;

int main() {

	uint T;
	std::ifstream fin("B-small-practice.in");
	std::ofstream fout("B.out");

	fin >> T;

	for(uint caseNumber = 1; caseNumber <= T; caseNumber++) {
		uint M, N;
		fin >> M >> N;
		uint input[M][N];
		uint block[M][N];

		for(uint i = 0; i < M; i++) {
			for(uint j = 0; j < N; j++) {
				fin >> input[i][j];
				block[i][j] = 0;
			}
		}

		bool output = true;

		for(uint i = 0; i < M; i++) {
			uint max = input[i][0];
			for(uint j = 1; j < N; j++) {
				if(input[i][j] > max) {
					max = input[i][j];
				}
			}
				for(uint j = 0; j < N; j++) {
					if(input[i][j] < max) {
						block[i][j] += 1;
					}
				}
		}

		for(uint j = 0; j < N && output; j++) {
			uint max = input[0][j];
			for(uint i = 1; i < M; i++) {
				if(input[i][j] > max) {
					max = input[i][j];
				}
			}
				for(uint i = 0; i < M && output; i++) {
					if(input[i][j] < max) {
						block[i][j] += 1;

						if(block[i][j] == 2) 
							output = false;
					}
				}
		}

		fout << "Case #" << caseNumber << ": " << (output ? "YES" : "NO") << std::endl;
	}

	fin.close();
	fout.close();
}