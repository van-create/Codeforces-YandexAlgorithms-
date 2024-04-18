#include <iostream>
#include <vector>
#include <string>

using namespace std;

int char_to_int(char c) {
    return c - '0';
}

char int_to_char(int n) {
    return n + '0';
}

string realizatsiya(string str1, string str2) {
    string result;
    if (str2.length() > str1.length()) {
        swap(str1, str2);
    }

    str1 = "0" + str1;
    while (str2.length() < str1.length()) {
        str2 = "0" + str2;
    }

    int temp = 0;
    result.resize(str1.length(), '0');
    
    for (int i = str1.length() - 1; i >= 0; --i) {
        int sum = char_to_int(str1[i]) + char_to_int(str2[i]) + temp;
        result[i] = int_to_char(sum % 10);
        temp = sum / 10;
    }

    if (result[0] == '0') {
        result = result.substr(1);
    }

    return result;
}

// разбиение числа на массив
void razbiyeniye(string num, vector<string> &mass) {
    string temp = num;
    for (int i = 0; i < num.length(); ++i) {
        mass[i] = temp;
        temp.erase(temp.length() - 1, 1);
    }
}

int main() {
    int kol;
    cout << "vvedite num of strings:\n";
    cin >> kol;

    vector<string> vvod(kol), resultat(kol);

    cout << "vvedite strings:\n";
    for (int x = 0; x < kol; ++x) {
        cin >> vvod[x];
    }

    for (int i = 0; i < kol; ++i) {
        vector<string> mass(vvod[i].length());
        razbiyeniye(vvod[i], mass);
        string tempres = mass[0];
        for (int x = 1; x < vvod[i].length(); ++x) {
            tempres = realizatsiya(tempres, mass[x]);
        }
        resultat[i] = tempres;
    }

    cout << "resultat:\n";
    for (int x = 0; x < kol; ++x) {
        cout << resultat[x] << '\n';
    }

    return 0;
}