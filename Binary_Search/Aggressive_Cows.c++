/*

Algorithm:
First, we will sort the given stalls[] array.
We will use a loop(say i) to check all possible distances.
Next, inside the loop, we will send each distance, i, to the function canWePlace() function to check if it is possible to place the cows.
We will return (i-1), where i is the minimum distance for which the function canWePlace() returns false. Because (i-1) is the maximum distance for which we can place all the cows and for the distances >= i, it becomes impossible.
Finally, if we are outside the loop, we can conclude the minimum possible distance should be max(stalls[])-min(stalls[]). And we will return this value.
*/

// Brute Force

#include <bits/stdc++.h>
using namespace std;

bool canWePlace(vector<int> &stalls, int dist, int cows)
{
    int n = stalls.size(); // size of array
    int cntCows = 1;       // no. of cows placed
    int last = stalls[0];  // position of last placed cow.
    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - last >= dist)
        {
            cntCows++;        // place next cow.
            last = stalls[i]; // update the last location.
        }
        if (cntCows >= cows)
            return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size(); // size of array
    // sort the stalls[]:
    sort(stalls.begin(), stalls.end());

    int limit = stalls[n - 1] - stalls[0];
    for (int i = 1; i <= limit; i++)
    {
        if (canWePlace(stalls, i, k) == false)
        {
            return (i - 1);
        }
    }
    return limit;
}

int main()
{
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;
    int ans = aggressiveCows(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << "\n";
    return 0;
}

// Optimal

#include <bits/stdc++.h>
using namespace std;

bool canWePlace(vector<int> &stalls, int dist, int cows)
{
    int n = stalls.size(); // size of array
    int cntCows = 1;       // no. of cows placed
    int last = stalls[0];  // position of last placed cow.
    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - last >= dist)
        {
            cntCows++;        // place next cow.
            last = stalls[i]; // update the last location.
        }
        if (cntCows >= cows)
            return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size(); // size of array
    // sort the stalls[]:
    sort(stalls.begin(), stalls.end());

    int low = 1, high = stalls[n - 1] - stalls[0];
    // apply binary search:
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (canWePlace(stalls, mid, k) == true)
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return high;
}

int main()
{
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;
    int ans = aggressiveCows(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << "\n";
    return 0;
}
