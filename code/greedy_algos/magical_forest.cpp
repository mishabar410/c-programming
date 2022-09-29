#include <bits/stdc++.h> //1859

using namespace std;

int n;
vector<vector<int>> ans;

bool try_bin(int sum, int mid, int mx, vector<int> &row, const vector<int> &v);
bool fn(int mx, vector<int> h, vector<int> v);

int main() {
    cin >> n;
    vector<int> h(n), v(n); //h это массив для сторк, v это массив для столбцов
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
        mx = max(mx, h[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        mx = max(mx, v[i]);
    }
    int l = 0, r = mx;              //mx максимум среди сумм
    while (r - l > 1)               //бинпоиском ищем верхнюю грань высоты
    {
        int mid = l + (r - l) / 2;
        if (fn(mid, h, v)) r = mid; //внесли mid, массив для столбцов и для строк
        else l = mid;
    }
    if (!fn(r, h, v)) cout << "NO";
    else
    {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++) cout << ans[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}

bool try_bin(int sum, int mid, int mx, vector<int> &row, const vector<int> &v)
{            //сумма на i-ой строке, mid, mx, строка леса, массив сумм на столбцах
    int res = 0;
    for (int j = 0; j < v.size(); ++j)
    {
        auto& el = v[j];                //el это сумма на j-том столбце
        row[j] = 0;                     //i, j ый элемент
        if (el < mid)  continue;        //проверка больше ли сумма на j-ом столбце чем mid
        int diff = min(mx, el - mid);
        res += diff;                    //в res держим все что прибавили к j-ому столбцу
        row[j] = diff;                  //diff значение i, j-го элемента
    }                                   //sum это сумма в i-ой строке
    return res >= sum;                  //если напривавляли больше чем можно, то true
}

bool fn(int mx, vector<int> h, vector<int> v)   //h - массив для строк, v - массив для столбцов
{
    vector<vector<int>> f(n, vector<int> (n));  //таблица f (forest)
    for (int i = 0; i < n; i++)                 //для каждой строки
    {
        int r = 0;
        for (auto p : v) r = max(r, p);         //находим максимум в массиве сумм для столбцов
        r++;
        int l = 0;
        while (l + 1 != r)                      //делаем бинпоиск mid чтобы заполнить строку не выйдя за пределы
        {
            int mid = (r + l) / 2;              // mid от 0 до максимума в массиве сумм столбцов
            if (try_bin(h[i], mid, mx, f[i], v)) l = mid; //если перебрали берем mid больше
            else r = mid;                                 //это нужно чтобы в следующий раз прибавлять меньше
        }                                                 //l == r - 1
        try_bin(h[i], l + 1, mx, f[i], v);                //последняя итерация
        for (int j = 0; j < n; ++j)
        {
            h[i] -= f[i][j];
            v[j] -= f[i][j];
        }
        for (int j = 0; j < n; ++j)
        {
            if (v[j] == l + 1 && h[i] > 0 && f[i][j] < mx)
            {
                h[i]--;
                v[j]--;
                f[i][j]++;
            }
        }
    }
    ans = f;
    for (int i = 0; i < n; i++)  if (v[i] != 0 || h[i] != 0) return false;  //если заполнили таблицу не до конца то мы проиграли
    return true;
}
