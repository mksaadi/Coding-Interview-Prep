#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned  long long;
using pi=pair<int,int>;
using pl=pair<ll,ll>;
using vi=vector<int>;
using vl=vector<ll>;
using vpi=vector<pi>;
using vpl=vector<pl>;
using ld = long double;
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define print(v) for(auto x:v){cout<<x<<" ";cout<<endl;}cout<<endl; //print the vector
const long long INF = 1e18;      
const long double EPS = 1e-9;
const long long mod = 1e9+7;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
//cout.setf( std::ios::fixed, std:: ios::floatfield );               // floatfield not set
//cout.precision(10);
int main()
{
    FastIO;
    vl powers_of_ten(19,1);
    vl blocks(19,1);
    for(int i=1;i<=18;i++)
    {
        powers_of_ten[i] = powers_of_ten[i-1]*10;
    }
    blocks[0] = 0;
    blocks[1] = 9;
 
    //cout<<"Blocks : \n";
    for(int i=2;i<=18;i++)
    {
        blocks[i] = powers_of_ten[i]-powers_of_ten[i-1];
        //cout<<blocks[i]<<endl;
    }
 
    int t;
    cin>>t;
 
    
    while(t--)
    {
        ll k;
        cin>>k;
        int block_no = 0;
        ll digits_so_far = 0LL;
 
        ll digits_in_previous_block = 0LL;
 
        for(int i=1;i<=18;i++)
        {
            digits_so_far += (blocks[i]*i);
            if(digits_so_far>=k)
            {
                block_no = i;
                break;
            }
            digits_in_previous_block += (blocks[i]*i);
        }
        //cout<<"Block No : "<<block_no<<endl;
        //cout<<"Digits in the actual block : "<<digits_so_far<<endl;
        //cout<<"Digits in previous block : "<<digits_in_previous_block<<endl;
        ll low = powers_of_ten[block_no-1];
        ll high = powers_of_ten[block_no]-1;
        //cout<<"Low : "<<low<<endl;
        //cout<<"High : "<<high<<endl;
        ll closest_value = 0LL;
        ll closest_value_pos = 0LL;
        while(low<=high)
        {
            ll mid = (low+high)/2LL;
            cout << "Before \n";
            cout << "Lo = " << low << "\n";
            cout << "Hi = " << high << "\n";
            cout << "Mid = " << mid << "\n";
            cout << "Ans = " << closest_value << "\n";
            cout << "Idx = " << closest_value_pos << "\n";

            ll starting_pos_mid = (digits_in_previous_block+1LL) + ((mid-(powers_of_ten[block_no-1]))*block_no);
            cout<<"Starting post mid = "<<starting_pos_mid<<"\n";
            if(starting_pos_mid<=k)
            {
                if(mid>closest_value)
                {
                    closest_value = mid;
                    closest_value_pos = starting_pos_mid;
                }
                low = mid+1;
            }
            else 
            {
                high = mid-1;
            }
            
            cout << "Before \n";
            cout << "Lo = " << low << "\n";
            cout << "Hi = " << high << "\n";
            cout << "Mid = " << mid << "\n";
            cout << "Ans = " << closest_value << "\n";
            cout << "Idx = " << closest_value_pos << "\n";

 
        }
 
        string result = to_string(closest_value);
        cout<<result[k-closest_value_pos]<<endl;
        
    }
 
 

 return 0;
}