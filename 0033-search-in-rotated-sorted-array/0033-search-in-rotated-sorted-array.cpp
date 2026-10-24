class Solution {
public:
    int search(vector<int>& a, int x) {
        int n = a.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (a[mid] == x) return mid;

            if (x > a[high]) {
                if (a[low] <= a[mid]) {
                    if (x >= a[low] && x < a[mid])
                        high = mid - 1;
                    else
                        low = mid + 1;
                } else {
                    high = mid - 1;
                }
            } else {
                if (a[mid] <= a[high]) {
                    if (x > a[mid] && x <= a[high])
                        low = mid + 1;
                    else
                        high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }

        return -1;
    }
};