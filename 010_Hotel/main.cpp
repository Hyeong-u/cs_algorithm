/*************************************************************************
*
* Problem:
* ACM 2014 Asia Reginal Daejeon Nationwide Internet Competition
*   Problem A Hotel
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

int main()
{
    ios_base::sync_with_stdio(false);
    ifstream fin;
    fin.open("input.txt");
    if (fin.fail()) {
        cout << "Input file opening failed.\n";
//        exit(1);
    }
    int num_testcases;
    fin >> num_testcases;

    for (int i = 0; i < num_testcases; i++) {
        int height, width, customer;
        int floor, room_number;
        fin >> height >> width >> customer;
        if (customer % height == 0) {
            floor = height;
            room_number = customer / height;
        } else {
            floor = customer % height;
            room_number = (customer / height) + 1;
        }
        if (room_number < 10) {
            cout << floor << 0 <<room_number << "\n";
        } else {
            cout << floor <<room_number << "\n";
        }
    }
    return 0;
}
