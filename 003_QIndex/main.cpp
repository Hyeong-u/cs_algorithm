/*************************************************************************
*
* Problem:
* ACM 2016 Asia Reginal Daejeon Nationwide Internet Competition
*	Problem I Q-Index
*************************************************************************/
/*************************************************************************
*
* Kookmin Univ Computer Science junior
* 20153168 Kim Hyeongwoo
*
*************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
//#include <fstream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
//    ifstream cin;
//    cin.open("input.txt");
//    if (cin.fail()) {
//        cout << "input.txt opening is failed.\n";
//        exit(1);
//    }
    int num_testcases;
    cin >> num_testcases;
    for (int i = 0; i < num_testcases; i++) {
        int num_papers;
        cin >> num_papers;
        vector<int> papers;
        papers.reserve(num_papers + 1);
        for (int j = 0; j < num_papers; j++) {
            cin >> papers[j];
        }
        sort(papers.begin(), papers.begin() + num_papers);
        int ans = 0;
        for (int j = 0; j < num_papers; j ++) {
            if (papers[j] >= num_papers - j) {
                ans = num_papers - j;
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
