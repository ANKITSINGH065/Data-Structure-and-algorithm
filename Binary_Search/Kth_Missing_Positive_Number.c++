/*
Naive Approach:
There might be many brute-force approaches to solve this problem. But we are going to use the following simple steps to solve the problem.

Algorithm:
We will use a loop to traverse the array.
Inside the loop,
If vec[i] <= k: we will simply increase the value of k by 1.
Otherwise, we will break out of the loop.
Finally, we will return the value of k.

*/

// Brute Force

#include <bits/stdc++.h>
using namespace std;

int missingK(vector<int> vec, int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (vec[i] <= k)
            k++; // shifting k
        else
            break;
    }
    return k;
}

int main()
{
    vector<int> vec = {4, 7, 9, 10};
    int n = 4, k = 4;
    int ans = missingK(vec, n, k);
    cout << "The missing number is: " << ans << "\n";
    return 0;
}

// Optimal approach

/*
Optimal Approach(Using Binary Search):
We are going to use the Binary Search algorithm to optimize the approach.

The primary objective of the Binary Search algorithm is to efficiently determine the appropriate half to eliminate, thereby reducing the search space by half. It does this by determining a specific condition that ensures that the target is not present in that half.

We cannot apply binary search on the answer space here as we cannot assure which missing number has the possibility of being the kth missing number. That is why, we will do something different here. We will try to find the closest neighbors (i.e. Present in the array) for the kth missing number by counting the number of missing numbers for each element in the given array.

Let’s understand it using an example. Assume the given array is {2, 3, 4, 7, 11}. Now, if no numbers were missing the given array would look like {1, 2, 3, 4, 5}. Comparing these 2 arrays, we can conclude the following:


How we will get the answer after all these steps?

After completing the binary search on the indices, the pointer high will point to the closest neighbor(present in the array) that is smaller than the kth missing number.

So, in the given array, the preceding neighbor of the kth missing number is vec[high].
Now, we know, up to index ‘high’,
the number of missing numbers = vec[high] - (high+1).
But we want to go further and find the kth number. To extend our objective, we aim to find the kth number in the sequence. In order to determine the number of additional missing values required to reach the kth position, we can calculate this as
more_missing_numbers = k - (vec[high] - (high+1)).
Now, we will simply add more_missing_numbers to the preceding neighbor i.e. vec[high] to get the kth missing number.
kth missing number = vec[high] + k - (vec[high] - (high+1))
        =  vec[high] + k - vec[high] + high + 1
        = k + high + 1.


*/

#include <bits/stdc++.h>
using namespace std;

int missingK(vector<int> vec, int n, int k)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int missing = vec[mid] - (mid + 1);
        if (missing < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return k + high + 1;
}  

int main()
{
    vector<int> vec = {4, 7, 9, 10};
    int n = 4, k = 4;
    int ans = missingK(vec, n, k);
    cout << "The missing number is: " << ans << "\n";
    return 0;
}
