/*************************************************************************
*
* Problem:
* ACM 2016 Asia Reginal Daejeon Nationwide Internet Competition
*	Problem J Railway
*************************************************************************/
/*************************************************************************
*
* Kookmin Univ Computer Science junior
* 20153168 Kim Hyeongwoo
*
*************************************************************************/
#include <iostream>
#include <algorithm>
#include <queue>
//#include <fstream>

using namespace std;

struct Person {
    int left;
    int right;
};

bool Compare(Person p1, Person p2) {
    return p1.left < p2.left;
}

Person arr[100001];

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
        int num_people, rail_len;
        cin >> num_people;

        for (int j = 0; j < num_people; j++) {
            cin >> arr[j].left >> arr[j].right;
            if (arr[j].left > arr[j].right) {
                swap(arr[j].left, arr[j].right);
            }
        }

        cin >> rail_len;
        sort(arr, arr + num_people, Compare);
        priority_queue<int> max_heap;
        unsigned int ans = 0;
        for (int j = num_people-1; j > -1; j--) {
            max_heap.push(arr[j].right);
            while(!max_heap.empty()) {
                if (max_heap.top() - arr[j].left <= rail_len) {
                    break;
                }
                max_heap.pop();
            }
            if (ans < max_heap.size()) {
                ans = max_heap.size();
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
