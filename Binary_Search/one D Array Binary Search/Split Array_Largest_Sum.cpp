/*

Algorithm:
First, we will find the maximum element and the summation of the given array.
We will use a loop(say maxSum) to check all possible answers from max(arr[]) to sum(arr[]).
Next, inside the loop, we will send ‘maxSum’, to the function countPartitions() function to get the number of partitions.
The first value of ‘maxSum’, for which the number of partitions will be equal to ‘k’, will be our answer. So, we will return that particular value of ‘maxSum’.
Finally, if we are out of the loop, we will return max(arr[]) as there cannot exist any answer smaller than that.

*/

// Brute force

#include <bits/stdc++.h>
using namespace std;

int countPartitions(vector<int> &a, int maxSum)
{
    int n = a.size(); // size of array.
    int partitions = 1;
    long long subarraySum = 0;
    for (int i = 0; i < n; i++)
    {
        if (subarraySum + a[i] <= maxSum)
        {
            // insert element to current subarray
            subarraySum += a[i];
        }
        else
        {
            // insert element to next subarray
            partitions++;
            subarraySum = a[i];
        }
    }
    return partitions;
}

int largestSubarraySumMinimized(vector<int> &a, int k)
{
    int low = *max_element(a.begin(), a.end());
    int high = accumulate(a.begin(), a.end(), 0);

    for (int maxSum = low; maxSum <= high; maxSum++)
    {
        if (countPartitions(a, maxSum) == k)
            return maxSum;
    }
    return low;
}

int main()
{
    vector<int> a = {10, 20, 30, 40};
    int k = 2;
    int ans = largestSubarraySumMinimized(a, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}

// Optimal Approach

/*
Optimal Approach(Using Binary Search):
We are going to use the Binary Search algorithm to optimize the approach.

The primary objective of the Binary Search algorithm is to efficiently determine the appropriate half to eliminate, thereby reducing the search space by half. It does this by determining a specific condition that ensures that the target is not present in that half.

Upon closer observation, we can recognize that our answer space, represented as [max(arr[]), sum(arr[])], is actually sorted. Additionally, we can identify a pattern that allows us to divide this space into two halves: one consisting of potential answers and the other of non-viable options. So, we will apply binary search on the answer space.

*/

#include <bits/stdc++.h>
using namespace std;

int countPartitions(vector<int> &a, int maxSum)
{
    int n = a.size(); // size of array.
    int partitions = 1;
    long long subarraySum = 0;
    for (int i = 0; i < n; i++)
    {
        if (subarraySum + a[i] <= maxSum)
        {
            // insert element to current subarray
            subarraySum += a[i];
        }
        else
        {
            // insert element to next subarray
            partitions++;
            subarraySum = a[i];
        }
    }
    return partitions;
}

int largestSubarraySumMinimized(vector<int> &a, int k)
{
    int low = *max_element(a.begin(), a.end());
    int high = accumulate(a.begin(), a.end(), 0);
    // Apply binary search:
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int partitions = countPartitions(a, mid);
        if (partitions > k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    vector<int> a = {10, 20, 30, 40};
    int k = 2;
    int ans = largestSubarraySumMinimized(a, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
