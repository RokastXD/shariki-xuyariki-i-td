#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>


using namespace std;

int n = 0;
int c = 0;
int p = 0;

bool ifSimple(int x) {
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

void shari() {
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
        cout << " " << arr[i];
    }

    do {
        for (int j = 0; j < n; j++) {
            if (j + 1 == arr[j]) { c++; break; }
        }
        p++;
    } while (next_permutation(arr, arr + n));
    cout << endl << c << ' ' << p;
}

void evklid() {
    int a; int b;
    cout << "Type a = ";
    cin >> a;
    cout << "Type b = ";
    cin >> b;
    while (a != 0 && b != 0) {
        if (a > b) {
            a = a % b;
        }
        else {
            b = b % a;
        }
    }
    cout << a + b;
}

void eratosven() {
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
        cout << " " << arr[i];
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        if (ifSimple(arr[i]) == true)
            if (arr[i] != 0 && arr[i] != 1)
                cout << arr[i] << " ";
    }
    cout << endl;
}

void longestWord() {
    char ch[100];
    int max = 0;
	ifstream fin;
    fin.open("bigword.txt");
	int c = 0; int summ = 0;
    
	while (!fin.eof()) {
        fin >> ch;
        //cout << ch << endl;
        if (max < int(strlen(ch)))
        {
            max = strlen(ch);
        }
	}
	cout << max << endl;
	fin.close();
}

void spinners() {
    int A; int B; int C; int M;
    cout << endl << "Spinners 1" << endl;
    cin >> A; cin >> B; cin >> C;
    cout << (C - A) / B;
    cout << endl << "Spinners 2" << endl;
    cin >> M;
    int three = 0; int four = 0;
    while (M % 4 != 0 && M > 0) {
        M -= 3;
        four = M / 4;
        three += 1;
    }
    if (M < 0) {
        cout << 0 << endl << 0;
    }
    else {
        cout << three << endl << four;
    }
}

string* bubble_sort(size_t length, string* sort_text) {
    string ct;
    for (int i = 0; i < int(length); i++) {
        for (int j = i + 1; j < int(length); j++) {
            if (sort_text[i][0] > sort_text[j][0]) {
                ct = sort_text[i];
                sort_text[i] = sort_text[j];
                sort_text[j] = ct;
            }
        }
    }
    return sort_text;
}

void file2() {
    string ch;
    ifstream fin;
    string answer;
    string word;
    int c = 0;
    string* sort_text;
    int lastSortSymbol = 0;
    fin.open("bigword.txt");
    while (!fin.eof()) {
        fin >> ch;
        c += 1;
    }
    fin.close();

    cout << "Do you want add word in file? (y/n): ";
    cin >> answer;
    if (answer == "y") {
        cout << "Type word: ";
        cin >> word;
        c += 1;
    }

    sort_text = new string[c];

    fin.open("bigword.txt");
    for (int i = 0; i < c - 1; i++) {
        fin >> ch;
        sort_text[i] = ch;
        cout << i << "   " << sort_text[i] << endl;
    }
    sort_text[c - 1] = word;
    fin.close();

    bubble_sort(c, sort_text);

    
    ofstream big_file("bigword.txt");
    for (int i = 0; i < c; i++) {
        big_file << sort_text[i] << " ";
    }
    big_file.close(); 
}


int main()
{
    //shari();
    //evklid();
    //eratosven();
    //longestWord();
    //spinners();
    file2();

}