/*************************************************************************
*
* Problem:
* ACM 2014 Asia Reginal Daejeon Nationwide Internet Competition
*   Problem C Eureka Theorem
*************************************************************************/
/*************************************************************************
*
* Kookmin Univ Computer Science junior
* 20153168 Kim Hyeongwoo
*
*************************************************************************/
#include <iostream>
#include <fstream>

using namespace std;

int triangle_num[45];
int sum_trinum[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    ifstream fin;
    fin.open("input.txt");
    if (fin.fail()) {
        cout << "Input file opening failed.\n";
        return -1;
    }

    int num_testcases;
    fin >> num_testcases;
    for (int i = 1; i < 45; i++) {
        triangle_num[i] = i * (i + 1) / 2;
    }
    for (int i = 1; i < 45; i++) {
        for (int j = 1; j < 45; j++) {
            for (int k = 1; k <45; k++) {
                if(triangle_num[i] + triangle_num[j] + triangle_num[k] < 1001) {
                    sum_trinum[triangle_num[i]
                                + triangle_num[j]
                                + triangle_num[k]] = 1;
                }
            }
        }
    }

    for (int i = 0; i < num_testcases; i++) {
        int ans;
        fin >> ans;
        cout << sum_trinum[ans] << "\n";
    }
    return 0;
}
