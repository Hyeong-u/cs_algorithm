/*************************************************************************
*
* Problem:
* The 40th ACM ASIA Regional - Daejeon Nationwide Internet Competition
*   Problem F Merging Files
*************************************************************************/
/*************************************************************************
*
* Kookmin Univ Computer Science junior
* 20153168 Kim Hyeongwoo
*
*************************************************************************/
#include <iostream>
#include <limits>
//#include <fstream>

using namespace std;

int minmerge(int n, const int size[])
{
    int merge[501][501] ={0,};
    int cost[501][501] = {0,};
    int minval;
    for (int i = 1; i <= n ; ++i) {
        cost[i][i] = size[i];
    }
    for (int i = 1; i < n ; ++i) {
        for (int j = 1; j <= n - i; ++j) {
            cost[j][j+i] = cost[j][j] + cost[j+1][j+i];
        }
    }

    for (int diagonal = 1; diagonal <= n -1 ; ++diagonal) {
        for (int i = 1; i <= n - diagonal; ++i) {
            int j = i + diagonal;
            minval = numeric_limits<int>::max();
            for (int k = i; k <= j-1 ; ++k) {
                if (minval > merge[i][k] + merge[k+1][j] + cost[i][j]) {
                    minval = merge[i][k] + merge[k+1][j] + cost[i][j];
                }
            }
            merge[i][j] = minval;
        }
    }
    return merge[1][n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    int answer;
//    ifstream cin;
//    cin.open("input.txt");
//    if (cin.fail()) {
//        cout << "Input file opening failed.\n";
//        return -1;
//    }

    int num_testcases;
    cin >> num_testcases;

    for (int i = 0; i < num_testcases; ++i) {
        int n;
        int size[501] = {0, };
        cin >> n;
        for (int j = 1; j <= n; ++j) {
            cin >> size[j];
        }
        answer = minmerge(n, size);
        cout << answer << '\n';
    }

    return 0;
}
