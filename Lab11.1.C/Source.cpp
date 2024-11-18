//C:\Users\User\source\repos\Lab11.1.C\tt.txt
#include <iostream>
#include <fstream>
#include <cstring> 
using namespace std;

int CountCommaDashPairs(const char* fname) {
    ifstream fin(fname); 
    if (!fin.is_open()) {
        cerr << "�� ������� �i������ ����! �����i��� i�'� ����� ��� ���� �i��������������." << endl;
        return 0;
    }

    char line[256]; 
    int count = 0;
    int line_number = 0;

    while (fin.getline(line, sizeof(line))) { 
        line_number++;
        for (size_t i = 0; i < strlen(line) - 1; i++) { 
            if (line[i] == ',' && line[i + 1] == '-') {
                count++;
                cout << "�������� ',-' � ����� " << line_number << ", �����i� " << i + 1 << endl;
            }
        }
    }

    fin.close();
    return count;
}

int main() {
    setlocale(LC_ALL, "ukr"); 
    char fname[100]; 

    cout << "����i�� i�'� ���������� �����: ";
    cin >> fname; 

    int count = CountCommaDashPairs(fname); 
    if (count > 0) {
        cout << "\n�������� �i���i��� ��� ',-': " << count << endl;
    }
    else {
        cout << "\n���� ',-' �� ��������." << endl;
    }

    return 0;
}
