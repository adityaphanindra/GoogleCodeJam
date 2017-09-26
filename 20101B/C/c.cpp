#include <iostream>
#include <fstream>
#include <vector>

int main()
{
	std::ifstream fin;
	std::ofstream fout;

	fin.open("input");
	fout.open("output");

	int T;
	const int N = 25;
	long output;
	fin >> T;

	long setSizes [N][N];

	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			setSizes[i][j] = -1;

	for(int i = 2; i <= N; i++)
	{
		setSizes[i][1] = 1;
		for(int j = 2; j < i; j++)
		{
			for(int k = 1; setSizes[j][k] != -1; k++)
			{
				long num = setSizes[j][k];
				
			}
		}
	}
	
	for(int num = 1; num <= T; num++)
	{
		int n, output;
		fin >> n;

		fout << "Case #" << num << ": " << output % 100003 << std::endl;
	}
}