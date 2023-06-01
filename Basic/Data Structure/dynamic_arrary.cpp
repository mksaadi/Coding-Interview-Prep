#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define nl "\n"
#define all(x) (x).begin(), (x).end()

// create a data structure like Vector with array.

class DynamicArray
{
private:
    int size;
    int capacity;
    int *arr;

public:
    DynamicArray() : arr(nullptr), capacity(0), size(0) {}
    ~DynamicArray()
    {
        delete[] arr;
    }

    void push_back(int value)
    {
        cout << "Push_back(" << value << ")\n";
        cout << "Before : \n";
        cout << "Size = " << size << "\n";
        cout << "Capacity = " << capacity << "\n";
        if (size >= capacity)
        {
            int newCapacity = (capacity == 0 ? 1 : capacity * 2);
            int *newArr = new int[newCapacity];

            for (int i = 0; i < size; i++)
            {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
            capacity = newCapacity;
        }
        arr[size] = value;
        size++;
        cout << "After : \n";
        cout << "Size = " << size << "\n";
        cout << "Capacity = " << capacity << "\n";
    }

    int at(int index) const
    {
        if (index >= 0 && index < size)
        {
            return arr[index];
        }
        else
        {
            throw std::out_of_range("Index Out of Range\n");
        }
    }
    int getSize() const
    {
        return size;
    }
};

int main()
{
    FastIO;
    int n;
    cin >> n;
    DynamicArray d;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        d.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        cout << d.at(i) << " ";
    }
    cout << "\n";

    return 0;
}