/*************************************************************************
*
* Problem:
* ACM 2011 Asia Reginal Daejeon Nationwide Internet Competition
*   Problem E Goldbach¡¯s Conjecture
*************************************************************************/
/*************************************************************************
*
* Kookmin Univ Computer Science junior
* 20153168 Kim Hyeongwoo
*
*************************************************************************/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
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
    int flag, length, sum;
    int ans[2002] = {0, };
    vector<int> primenum;
    primenum.reserve(500);
    primenum.push_back(2);
    for (int i = 3; i < 1002; i++) {
        flag = 1;
        for (int j = 2; j < int(sqrt(i))+1; j++) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            primenum.push_back(i);
        }
    }
    length = primenum.size();
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            sum = primenum[i] + primenum[j];
            if(sum > 1000) {
                continue;
            }
            if (ans[sum*2] == 0) {
                ans[sum*2] = primenum[i];
                ans[sum*2 + 1] = primenum[j];
            } else {
                if(abs(ans[sum*2] - ans[sum*2 + 1]) > abs(primenum[i] - primenum[j])) {
                    ans[sum*2] = primenum[i];
                    ans[sum*2 + 1] = primenum[j];
                }
            }
        }
    }

    int num_testcases;
    int target;
    cin >> num_testcases;


    for (int i = 0; i < num_testcases; i++) {
        cin >> target;
        if (ans[target*2] < ans[target*2 + 1]) {
            cout << ans[target*2] << " " << ans[target*2 + 1] << "\n";
        } else {
            cout << ans[target*2 + 1] << " " << ans[target*2] << "\n";
        }
    }
    return 0;
}
