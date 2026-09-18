#include <iostream>

using namespace std;

void prosesEliminasi(int N, int K) {
    int astronot[1000];
    
    for (int i = 0; i < N; i++) {
        astronot[i] = 1;
    }

    int sisa = N;
    int index = 0;

    cout << "Urutan astronot yang tereliminasi:" << endl;

    while (sisa > 1) {
        int hitungan = 0;

        while (hitungan < K) {
            if (astronot[index] == 1) {
                hitungan++;
            }
            if (hitungan < K) {
                index = (index + 1) % N;
            }
        }

        int nomorTereliminasi = index + 1;
        astronot[index] = 0;
        sisa--;

        cout << "Astronot " << nomorTereliminasi << " tereliminasi. ";

        if (nomorTereliminasi % 2 == 0) {
            K = K + 2;
        } else {
            K = K - 1;
        }

        if (K < 2) {
            K = 2;
        }

        cout << "(Nilai K baru: " << K << ")" << endl;

        while (sisa > 0 && astronot[index] == 0) {
            index = (index + 1) % N;
        }
    }

    for (int i = 0; i < N; i++) {
        if (astronot[i] == 1) {
            cout << "\nAstronot terakhir yang bertahan adalah astronot nomor: " << (i + 1) << endl;
            break;
        }
    }
}

int main() {
    int N, K;
    
    cout << "Masukkan jumlah astronot (N): ";
    cin >> N;
    cout << "Masukkan nilai awal K: ";
    cin >> K;

    prosesEliminasi(N, K);

    return 0;
}