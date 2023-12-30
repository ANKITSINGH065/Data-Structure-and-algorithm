
// Brute Force

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int max_one = INT_MIN;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (auto vec : matrix[i])
        {

            if (vec == 1)
            {
                count++;
            }
        }

        if (count > max_one)
        {
            max_one = count;
            index = i;
        }
    }

    return index;
}

/*


We cannot optimize the row traversal but we can optimize the counting of 1’s for each row.

Instead of counting the number of 1’s, we can use the following formula to calculate the number of 1’s:
Number_of_ones = m(number of columns) – first occurrence of 1(0-based index).

As, each row is sorted, we can find the first occurrence of 1 in each row using any of the following approaches:

lowerBound(1)
upperBound(0)
firstOccurrence(1)

*/

// Optimal Approach T.c = O(N*log(M))

int Binary_search(vector<int> &nums)
{

    int n = nums.size();

    int start = 0;
    int end = n - 1;
    int mid = 0;

    while (start <= end)
    {

        mid = start + (end - start) / 2;

        if (nums[mid] == 1)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return (n - start) + 1;
}

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int max_one = INT_MIN;
    int index = -1;
    for (int i = 0; i < n; i++)
    {

        int count = Binary_search(matrix[i]);

        if (count > max_one)
        {
            max_one = count;
            index = i;
        }
    }

    return index;
}