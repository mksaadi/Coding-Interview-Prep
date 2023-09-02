#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

// if we had to keep all the elements in the array
// int removeElement(vector<int> &nums, int val)
// {
//     int n = nums.size();
//     int k = 0;
//     sort(nums.begin(), nums.end());
//     for (int i = 0; i < n; i++)
//     {
//         cout << nums[i] << " ";
//     }
//     cout<<"\n";
//     int start = -1;
//     int end = -1;
//     for (int i = 0; i < n; i++)
//     {
//         if (start == -1 && nums[i] == val)
//         {
//             start = i;
//         }
//         if (start != -1 && nums[i] != val)
//         {
//             end = i - 1;
//             break;
//         }
//     }

//     if(end==-1 && start!=-1)
//     {
//         end = n-1;
//     }
//     if(start==end)
//     {
//         if(start==n-1)
//         {
//             return n-1;
//         }
//         else
//         {
//             swap(nums[start],nums[n-1]);
//             return n-1;
//         }
//     }

//     cout<<"Start = "<<start<<"\n";
//     cout<<"End = "<<end<<"\n";

//     k = n-((end - start) + 1);
//     if (start == -1)
//     {
//         k = n;
//         return k;
//     }
//     int idx = n-1;
//     while (end >= start)
//     {
//         swap(nums[idx], nums[start]);
//         start++;
//         idx--;
//     }

//     return k;
// }

//
//   int removeElement(vector<int>& nums, int val) {
//         int n = nums.size();
//         if(n==0)return 0;
//         vector <bool> match(n);
//         int k = 0;
//         for(int i=0;i<n;i++)
//         {
//             if(nums[i]==val)
//             {
//                 match[i] = 1;
//             }
//         }
//         for(int i=0;i<n;i++)
//         {
//             if(match[i])
//             {
//                 nums.erase(nums.begin()+(i-k));
//                 k++;
//             }
//         }
//         return nums.size();
//     }

// best and concise solution
int removeElement(vector<int> &nums, int val)
{
    int k = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != val)
        {
            nums[k++] = nums[i];
        }
    }
    return k;
}

int main()
{
    FastIO;
    int n;
    cin >> n;
    int val;
    cin >> val;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << removeElement(nums, val) << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << "\n";

    return 0;
}