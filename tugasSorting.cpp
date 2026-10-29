
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

string kecil(string s) {
    transform(s.begin(), s.end(), s.begin(),
              [](unsigned char c) {
                  return tolower(c);
              });
    return s;
}

void cetak(const vector<string>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i + 1 < v.size()) cout << ", ";
    }
    cout << "]";
}

int main() {
    int n;
    cout << "Jumlah kata: ";
    cin >> n;

    if (n <= 0) {
        cout << "Jumlah kata harus lebih dari 0." << endl;
        return 0;
    }

    vector<string> kata(n);

    for (int i = 0; i < n; i++) {
        cout << "Kata ke-" << i + 1 << ": ";
        cin >> kata[i];
    }

    cout << "\nData awal: ";
    cetak(kata);
    cout << endl;

    for (int i = 1; i < n; i++) {
        string key = kata[i];
        int j = i - 1;

        cout << "\nLangkah " << i
             << ": sisipkan '" << key << "'" << endl;

        while (j >= 0 && kecil(kata[j]) > kecil(key)) {
            kata[j + 1] = kata[j];

            cout << "  Geser '" << kata[j]
                 << "' ke kanan -> ";
            cetak(kata);
            cout << endl;

            j--;
        }

        kata[j + 1] = key;

        cout << "  Hasil langkah " << i << ": ";
        cetak(kata);
        cout << endl;
    }

    cout << "\nHasil akhir (A-Z): ";
    cetak(kata);
    cout << endl;

    return 0;
}
