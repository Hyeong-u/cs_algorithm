/*************************************************************************
*
* Problem:
* ACM 2016 Asia Reginal Daejeon Nationwide Internet Competition
*   Problem H Palindromic Numbers
*************************************************************************/
/*************************************************************************
*
* Kookmin Univ Computer Science junior
* 20153168 Kim Hyeongwoo
*
*************************************************************************/
#include <iostream>
#include <vector>
//#include <fstream>

using namespace std;

int is_palindrome(vector<int> numbers, int left, int right) {
    if (left >= right) {
        return 1;
    } else if (numbers[left] != numbers[right]) {
        return 0;
    } else {
        return is_palindrome(numbers, left+1, right-1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
//    ifstream cin;
//    cin.open("input.txt");
//    if (cin.fail()) {
//        cout << "Input file opening failed.\n";
//        exit(1);
//    }
    int num_testcases;
    cin >> num_testcases;

    for (int i = 0; i < num_testcases; i++) {
        int ans = 0;
        int number;
        int temp_num;
        int remain;
        cin >> number;
        for (int j = 2; j < 65; j++) {
            temp_num = number;
            vector<int> numbers;
            for (int k = 0; k < 20; k++) {
                if (temp_num < j) {
                    numbers.push_back(temp_num);
                    break;
                } else {
                    remain = temp_num % j;
                    numbers.push_back(remain);
                    temp_num = temp_num / j;
                }

            }
            ans = is_palindrome(numbers, 0, numbers.size() - 1);
            if (ans == 1) {
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
