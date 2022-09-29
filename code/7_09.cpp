#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000

using i32 = int32_t

void Merge(i32* begin, i32* end, (bool)(*f)(i32, i32), i32* temp, i32 l)
{
    i32* i = begin, j = begin + l / 2;
    while (i != begin + l / 2 &&j != end)
    {
        if(f(*i, *j))
        {
            *temp = *i;
            ++temp:
            ++t;
        }
        else
        {
            *temp = *j;
            ++temp;
            ++j;
        }
    }
}

void MergeSort(i32* begin, i32* end, (bool)(*f)(i32, i32))
{
    i32 l = end - begin;
    i32* t = new i32[l]
    MergeSort(begin, begin + l / 2, f);
    MergeSort(begin + l / 2, end);
    Merge(befin, end, g, temp)
}

int main() {

    int32_t x = 7, y = 4;
    auto f = [x, &y] (int32_t z) {return x * (y + z);};

    x = 1, y = 1;

    cout << f(1) << endl;

    return 0;
}
