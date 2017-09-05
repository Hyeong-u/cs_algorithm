/*************************************************************************
*
* Problem:
* ACM 2016 Asia Reginal Daejeon Nationwide Internet Competition
*	Problem L Truck
*************************************************************************/
/*************************************************************************
*
* Kookmin Univ Computer Science junior
* 20153168 Kim Hyeongwoo
*
*************************************************************************/
#include <iostream>
#include <queue>

using namespace std;


int CalculateTime(int width, int max_load, queue<int> trucks)
{
    int load = 0;
    int second = 0;
    queue<int> bridge;
    for (int i = 0; i < width; i++)
    {
        bridge.push(0);
    }
    while (!trucks.empty())
    {
        load -= bridge.front();
        bridge.pop();
        if (load + trucks.front() <= max_load)
        {
            load += trucks.front();
            bridge.push(trucks.front());
            trucks.pop();
        }
        else
        {
            bridge.push(0);
        }
        second++;
    }
    return second + width;
}

int main()
{
    int num_testcases;
    cin >> num_testcases;
    int num_trucks, width, max_load, weight;

    for (int i = 0; i < num_testcases; i++)
    {
        queue<int> trucks;
        cin >> num_trucks >> width >> max_load;
        for (int j = 0; j < num_trucks; j++)
        {
            cin >> weight;
            trucks.push(weight);
        }
        cout << CalculateTime(width, max_load, trucks) << endl;
    }
    return 0;
}
