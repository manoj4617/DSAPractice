#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>

using namespace std;

int raised_to_power(vector<int> x, vector<int> y, int m, int n) {
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    int count = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (pow(x[i], y[j]) > pow(y[j], x[i]))
                count++;
        }
    }
    return count;
}

int main() {

    int m, n;
    cin >> m >> n;
    vector<int>x;
    vector<int>y;

    for (int i = 0; i < m; ++i) {
        int v;
        cin >> v;
        x.push_back(v);
    }

    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        y.push_back(v);
    }

    cout << raised_to_power(x, y, m, n) << endl;

    return 0;
}