#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool find_possible(vector<int> &book, int n,
                       long long limit, int stu)
    {
        long long page = 0;
        int k = 1;

        for (int i = 0; i < n; i++)
        {
            if (page + book[i] <= limit)
            {
                page += book[i];
            }
            else
            {
                k++;
                page = book[i];

                if (k > stu)
                {
                    return false;
                }
            }
        }
        return true;
    }

    int findPages(vector<int> &arr, int k)
    {
        int n = arr.size();

        if (n < k)
        {
            return -1;
        }

        long long low = 0, high = 0;

        for (int i = 0; i < n; i++)
        {
            low = max(low, (long long)arr[i]);
            high += arr[i];
        }

        long long res = -1;

        while (low <= high)
        {
            long long mid = low + (high - low) / 2;

            if (find_possible(arr, n, mid, k))
            {
                res = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return (int)res;
    }
};
