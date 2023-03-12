#include <bits/stdc++.h>
 
#define long long long
#define Integer_MAX_VALUE 0x7fffffff
#define Integer_MIN_VALUE 0x80000000
#define LONG_MAX_VALUE 0x7fffffffffffffffL
#define LONG_MIN_VALUE 0x8000000000000000L
 
using namespace std;
 
struct Solution
{
    void run()
    {
        int n;
        cin >> n;
        int a[n], b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
 
        vector<int> ans;
 
        bool diff = true;
        do
        {
            int big = -1;
            int small = -1;
            for (int i = 0; i < n; i++)
            {
                if (a[i] > b[i])
                {
                    big = i;
                }
                else if (a[i] < b[i])
                {
                    small = i;
                }
            }
 
            if (big == -1 && small == -1)
            {
                diff = false;
            }
            else if (big != -1 && small != -1)
            {
                a[big]--;
                a[small]++;
                ans.push_back(big + 1);
                ans.push_back(small + 1);
            }
            else
            {
                cout << -1 << endl;
                return;
            }
        } while (diff);
        int len = ans.size() / 2;
        cout << len << endl;
        for (int i = 0; i < len; i++)
        {
            cout << ans[i * 2] << " " << ans[i * 2 + 1] << endl;
        }
    }
};
 
int main()
{
    ios_base::sync_with_stdio(false);
 
    Solution solution = Solution();
 
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solution.run();
    }
    return 0;
}