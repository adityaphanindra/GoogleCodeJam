#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    ifstream fin("A-large.in");
    ofstream fout("A-large.out");

    int T;
    fin >> T;

    for(int caseNumber = 1; caseNumber <= T; caseNumber++)
    {
        long long p, q;
        char slash;
        fin >> p >> slash >> q;
        std::cout << (log(q)/log(2)) << " " << ceil((log(q)/log(2))) << std::endl;
        if((log(q)/log(2)) != ceil(log(q)/log(2)))
        {
            fout << "Case #" << caseNumber << ": " << "impossible" << endl;
            continue;
        }
        else
        {
            double div = (double)q / (double)p;
            long long output = ceil(log(div) / log(2));

            fout << "Case #" << caseNumber << ": " << output << endl;
            continue;
        }
    }

    fin.close();
    fout.close();
}
