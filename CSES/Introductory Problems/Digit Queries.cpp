#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

ll power = 1LL;
vector<pair<ll, ll>> block_range;
vector<pair<ll, ll>> digit_range;
vector<ll> block_digits;

void generateData()
{

    block_range.emplace_back(0, 0);
    digit_range.emplace_back(0, 0);
    int block_idx = 1;
    while (true)
    {
        ll start_range = power;
        power *= 10LL;
        ll end_range = power - 1;
        block_range.emplace_back(start_range, end_range);

        ll number_of_numbers = (end_range + 1) - start_range;

        ll number_of_digits = number_of_numbers * block_idx;
        block_digits.push_back(number_of_digits);
        ll starting_idx_of_block = digit_range[block_idx - 1].second + 1;
        ll ending_idx_of_block = digit_range[block_idx - 1].second + number_of_digits;
        digit_range.emplace_back(starting_idx_of_block, ending_idx_of_block);
        block_idx++;
        if (block_idx == 18)
        {
            break;
        }
    }
}

int find_block(ll k)
{
    int block_no = 0;
    for (int i = 1; i < digit_range.size(); i++)
    {
        if (k <= digit_range[i].second)
        {
            block_no = i;
            break;
        }
    }
    // cout << "Block No = " << block_no << "\n";
    return block_no;
}

int main()
{
    FastIO;
    generateData();
    int q;
    cin >> q;

    while (q--)
    {
        ll k;
        cin >> k;
        int block_no = find_block(k);

        ll lo = block_range[block_no].first;
        ll hi = block_range[block_no].second;

        ll ans = 0;
        ll idx = 0;
        while (lo <= hi)
        {
            ll mid = (lo + hi) / 2LL;
            // cout << "Before \n";
            // cout << "Lo = " << lo << "\n";
            // cout << "Hi = " << hi << "\n";
            // cout << "Mid = " << mid << "\n";
            // cout << "Ans = " << ans << "\n";
            // cout << "Idx = " << idx << "\n";

            ll startingofmid = digit_range[block_no].first + ((mid - block_range[block_no].first) * block_no);
            // cout<<"Starting of Mid = "<<startingofmid<<"\n";
            if (startingofmid <= k)
            {
                if (mid > ans)
                {
                    ans = mid;
                    idx = startingofmid;
                }
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
            // cout << "After \n";
            // cout << "Lo = " << lo << "\n";
            // cout << "Hi = " << hi << "\n";
            // cout << "Ans = " << ans << "\n";
            // cout << "Idx = " << idx << "\n";
        }

        string num = to_string(ans);

        cout << num[k - idx] << "\n";
    }

    return 0;
}