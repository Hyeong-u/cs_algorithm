/*************************************************************************
*
* Problem:
* ACM 2015 Asia Reginal Daejeon Nationwide Internet Competition
*   Problem J Pythagorean Expectation
*************************************************************************/
/*************************************************************************
*
* Kookmin Univ Computer Science junior
* 20153168 Kim Hyeongwoo
*
*************************************************************************/
#include <iostream>
#include <algorithm>
//#include <fstream>

using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
//    ifstream cin;
//    cin.open("input.txt");
//    if (cin.fail()) {
//        cout << "Input file opening failed.\n";
//        return -1;
//    }

    int num_testcases;
    cin >> num_testcases;


    for (int i = 0; i < num_testcases; i++) {
        int scores[2000] = {0, };
        double expectation[1000] = {0, };
        int num_teams, num_games;
        int ateam, bteam, ascore, bscore;
        double ssqure, asqure;
        cin >> num_teams >> num_games;
        for (int j = 0; j < num_games; j++) {
            cin >> ateam >> bteam >> ascore >> bscore;
            scores[(ateam -1) * 2] += ascore;
            scores[(ateam -1) * 2 + 1] += bscore;
            scores[(bteam -1) * 2] += bscore;
            scores[(bteam -1) * 2 + 1] += ascore;

        }
        for (int j = 0; j < num_teams; j++) {
            if (scores[j*2] == 0 && scores[j*2 +1] == 0) {
                expectation[j] = 0;
            } else {
                ssqure = scores[j*2] * scores[j*2];
                asqure = scores[j*2 + 1] * scores[j*2 +1];
                expectation[j] = ssqure / (ssqure + asqure);
            }
        }
        sort(expectation, expectation + num_teams);
        cout << int(expectation[num_teams - 1] * 1000) << "\n" << int(expectation[0]*1000) << "\n";
    }
    return 0;
}
