/*************************************************************************
*
* Problem:
* ACM 2016 Asia Reginal Daejeon Nationwide Internet Competition
*	Problem A Binary Tree
*************************************************************************/
/*************************************************************************
*
* Kookmin Univ Computer Science junior
* 20153168 Kim Hyeongwoo
*
*************************************************************************/
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    int num_testcases;
    cin >> num_testcases;

   for(int i=0; i < num_testcases; i++)
   {
      int height;
      cin >> height;

      int node = ((2 << height) - 2);
      int *edge;
      int result = 0;

      edge = new int[node+2];

      for(int j = 2; j < node+2; j++)
      {
         cin >> edge[j];
      }

      for(int j = node+1; j > 0; j = j - 2)
      {
         result = max(edge[j], edge[j-1]) + result;
         edge[j/2] = max(edge[j], edge[j-1]) + edge[j/2];
      }

      cout << result << "\n";
   }

   return 0;
}
