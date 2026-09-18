#include <iostream>

using namespace std;

void enkripsiPesan(char pesan[]) {

    int length = 0;
    while (pesan[length] != '\0') {
        length++;
    }

    char hasilSandi[1000];

    hasilSandi[0] = pesan[0];

    for (int i = 1; i < length; i++) {
        int shift = pesan[i - 1] - 'A' + 1;
        int posSekarang = pesan[i] - 'A';
        int posBaru = (posSekarang + shift) % 26;
        hasilSandi[i] = (char)('A' + posBaru);
    }

    hasilSandi[length] = '\0';

    cout << "Pesan yang telah di-sandi: " << hasilSandi << endl;
}

int main() {
    char pesan[1000];
    
    cout << "Masukkan pesan asli: ";
    cin >> pesan;

    enkripsiPesan(pesan);

    return 0;
}