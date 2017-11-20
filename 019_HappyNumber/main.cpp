/*************************************************************************
*
* Problem:
* 2017 ACM ICPC ASIA Regional - Daejeon
*   Problem D Happy Number
*************************************************************************/
/*************************************************************************
*
* Kookmin Univ Computer Science junior
* 20153168 Kim Hyeongwoo
*
*************************************************************************/
#include <iostream>
#include <set>
#include <fstream>

using namespace std;

int solution(int number, set<int> &int_set)
{
    int result = 0;
    while(number != 0) {
        result += (number % 10) * (number % 10);
        number /= 10;
    }
    if (result == 1) {
        return result;
    } else if (int_set.find(result) != int_set.end()) {
        return 0;
    } else {
        int_set.insert(result);
        solution(result, int_set);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int answer = 0;
//    ifstream cin;
//    cin.open("input.txt");
//    if (cin.fail()) {
//        cout << "Input file opening failed.\n";
//        return -1;
//    }

    int num_testcases;
    cin >> num_testcases;

    for (int i = 0; i < num_testcases; i++) {
        int number;
        cin >> number;
        set<int> int_set;
        if (solution(number, int_set) == 1) {
            cout << "HAPPY" << '\n';
        } else {
            cout << "UNHAPPY" << '\n';
        }
    }
    return 0;
}
