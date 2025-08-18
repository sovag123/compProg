#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
using i128 = __int128_t;

int toMinutes(const string& s) {
    int HH = stoi(s.substr(0,2));
    int MM = stoi(s.substr(3,2));
    return HH*60 + MM;
}

int64 egcd(int64 a, int64 b, int64& x, int64& y) {
    if (b == 0) { x = (a>=0?1:-1); y = 0; return llabs(a); }
    int64 x1, y1;
    int64 g = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

bool crt2(int64 r1, int64 m1, int64 r2, int64 m2, int64& r, int64& mod) {
    int64 x, y;
    int64 g = egcd(m1, m2, x, y);
    int64 diff = r2 - r1;
    if (diff % g != 0) return false;
    int64 m2g = m2 / g;
    i128 k = (i128)(diff / g) * (i128)x;
    k %= (i128)m2g;
    if (k < 0) k += m2g;
    r = r1 + (int64)k * m1;
    mod = (m1 / g) * m2;
    r %= mod; if (r < 0) r += mod;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2, p1, p2;
    if (!(cin >> s1 >> s2 >> p1 >> p2)) return 0;

    int64 x1 = toMinutes(s1);
    int64 y1 = toMinutes(s2);
    int64 x2 = toMinutes(p1);
    int64 y2 = toMinutes(p2);

    int64 t0, L;
    if (!crt2(x1, x2, y1, y2, t0, L)) {
        cout << "Never\n";
        return 0;
    }

    int64 start = max(x1, y1);
    if (t0 < start) {
        int64 k = (start - t0 + L - 1) / L;
        t0 += k * L;
    }

    static const vector<string> day = {
        "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"
    };
    int64 dayIndex = (6 + (t0 / 1440)) % 7;
    int hh = (int)((t0 % 1440) / 60);
    int mm = (int)((t0 % 1440) % 60);

    cout << day[dayIndex] << "\n";
    cout << setw(2) << setfill('0') << hh << ":" << setw(2) << setfill('0') << mm << "\n";
    return 0;
}
